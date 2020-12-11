/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC16F1776
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

//led states as (R,G,B)
#define LED_OFF 0x0

#define LED_GREEN 0x2
#define LED_BLUE 0x1
#define LED_RED 0x4

#define LED_CYAN (LED_BLUE | LED_GREEN)
#define LED_PURPLE (LED_BLUE | LED_RED)
#define LED_YELLOW (LED_RED | LED_GREEN)

#define LED_WHITE (LED_GREEN | LED_BLUE | LED_RED)

#define LOW_BATTERY_VOLTAGE 173

uint8_t mux_state = 0;
uint8_t led_color_state = LED_OFF;

//function prototypes

void set_led(uint8_t);
void init_sensor(void);
void reset_sensor(void);



void my_CMP2_ISR(void){
    // clear the CMP2 interrupt flag
    PIR2bits.C2IF = 0;
    set_led(LED_RED);
    
}

void my_CMP1_ISR(void){
    // clear the CMP1 interrupt flag
    PIR2bits.C1IF = 0;
    set_led(LED_RED);
}

//change state
void SW2_ISR(void){
    
    switch(mux_state){
        case 0: //low gain, high bandwidth 
            led_color_state = LED_GREEN;
            MUX_SEL1_LAT = 1; //bandwidth select
            MUX_SEL2_LAT = 1; //gain select
        break;
        
        case 1: //low gain, low bandwidth 
            led_color_state = LED_YELLOW;
            MUX_SEL1_LAT = 0; //bandwidth select
            MUX_SEL2_LAT = 1; //gain select
        break;
        
        case 2: // high gain, high bandwidth 
            led_color_state = LED_BLUE;
            MUX_SEL1_LAT = 1; //bandwidth select
            MUX_SEL2_LAT = 0; //gain select
        break;
        
        case 3: //high gain, low bandwidth 
            led_color_state = LED_CYAN;
            MUX_SEL1_LAT = 0; //bandwidth select
            MUX_SEL2_LAT = 0; //gain select
        break;
    }
    set_led(led_color_state);
    mux_state = (mux_state+1)%4;
    __delay_ms(200); //delay for debounce 
}

//zero system
void SW1_ISR(void){
    
     //flash led at start
    set_led(LED_OFF);
    __delay_ms(200);
    set_led(led_color_state);
    reset_sensor();
    __delay_ms(200);
    if(SW1_GetValue() == 0){
        //if switch is still depressed do a full zero
        init_sensor();
    }
    
    //flash LED at end
    set_led(LED_OFF);
    __delay_ms(200);
    set_led(led_color_state);
    
     //zeroing system may trip over range comparators 
     PIR2bits.C2IF = 0;
     PIR2bits.C1IF = 0;
}

uint16_t average_adc_reading(adc_channel_t read_ch){
    
    uint16_t averaged_val = 0;
    for (int i = 0; i<8; i++){
        averaged_val = averaged_val + ADC_GetConversion(read_ch);
    }
    
    averaged_val = averaged_val;
    
    return averaged_val;
}

void set_led(uint8_t led_color) {
    
LED_B_LAT = (~led_color>>2)&1;
LED_G_LAT = (~led_color>>1)&1;
LED_R_LAT = (~led_color)&1;
    
}
void zero_stage_1(void){
    uint16_t gnd_ref_val;
    uint16_t best_dac_val = 0;
    uint16_t stage_val;
    uint16_t best_val = (1<<12); 
    
    gnd_ref_val = average_adc_reading(GNDREF_SENSE);
    
    for(uint16_t i = 0; i<1024; i++){
        
        DAC1_Load10bitInputData(i);
        __delay_ms(1);
        stage_val = average_adc_reading(STAGE1_MON);
        
        if ((stage_val-gnd_ref_val) < best_val){
            best_val = (stage_val - gnd_ref_val);
            best_dac_val = i;
        }
    }
    DAC1_Load10bitInputData(best_dac_val);
}

void zero_stage_2(void){
    uint16_t gnd_ref_val;
    uint16_t best_dac_val = 0;
    uint16_t stage_val;
    uint16_t best_val = 2000; 
    
    gnd_ref_val = average_adc_reading(GNDREF_SENSE);
    
    for(uint16_t i = 0; i<1024; i++){
        
        DAC5_Load10bitInputData(i);
        __delay_ms(1);
        stage_val = average_adc_reading(STAGE2_MON);
        
        if ((stage_val-gnd_ref_val) < best_val){
            best_val = (stage_val - gnd_ref_val);
            best_dac_val = i;
        }
        
    }
    
    DAC5_Load10bitInputData(best_dac_val);
    
}

void init_sensor(void){
    
    __delay_ms(50);
    zero_stage_1();
    __delay_ms(50);
    zero_stage_2();
    
}

void reset_sensor(){
    SR_SetLow();
     __delay_ms(50);
    SR_SetHigh();
     __delay_ms(50);
    SR_SetLow();
    
}

void low_battery_loop(){
    while(1){
        set_led(LED_OFF);
        
        __delay_ms(500);
        
        set_led(LED_RED);
        
        __delay_ms(500);
    }
}
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    DAC7_SetOutput(16); //set virtual ground to ~2.5V
    DAC3_SetOutput(24); //set overload high comparator  
    DAC4_SetOutput(8); //set overload low comparator 
    
    led_color_state = LED_GREEN;
    mux_state = 0;
    SW2_ISR();//initialize LED and mux
   
    reset_sensor();
    init_sensor();
    //zeroing system may trip over range comparators 
    PIR2bits.C2IF = 0;
    PIR2bits.C1IF = 0;
    //set interrupt handler for SW2
    IOCBF0_SetInterruptHandler(SW2_ISR);
    //set interrupt handler for SW1
    IOCCF7_SetInterruptHandler(SW1_ISR); 
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    while (1)
    {
        __delay_ms(100);
        if((average_adc_reading(VIN_SENSE)>>3) < LOW_BATTERY_VOLTAGE){
            INTERRUPT_GlobalInterruptDisable();
            INTERRUPT_PeripheralInterruptDisable();
            low_battery_loop();
        }
    }
}
/**
 End of File
*/