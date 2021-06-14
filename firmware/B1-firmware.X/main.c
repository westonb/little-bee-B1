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

#define HIGH_FVR_VOLTAGE 460 
//if 4.096V FVR reads too high supply is too low 2^10*2.048/5.012/0.91

#define ADC_SUPERSAMPLE 8

#define ADC_MAX_VAL 262144

uint8_t mux_state = 0;
uint8_t led_color_state = LED_OFF;

//function prototypes

void set_led(uint8_t);
void init_sensor(void);
void reset_sensor(void);

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
    if(~LED_B_LAT && LED_G_LAT && LED_R_LAT){
        //led is red due to OC, do not clear
    } else{
        set_led(led_color_state);
    }
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
    __delay_ms(400);
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

uint32_t average_adc_reading(adc_channel_t read_ch){
    
    uint32_t averaged_val = 0;
    //throw away first value
    averaged_val = ADC_GetConversion(read_ch);
    averaged_val = 0;
    for (int i = 0; i<(1<<ADC_SUPERSAMPLE); i++){
        averaged_val = averaged_val + ADC_GetConversion(read_ch);
    }
    
    return averaged_val;
}

uint32_t average_adc_reading_quick(adc_channel_t read_ch){
    
    uint32_t averaged_val = 0;
    //throw away first value
    averaged_val = ADC_GetConversion(read_ch);
    averaged_val = 0;
    
    for (int i = 0; i<(1<<(ADC_SUPERSAMPLE-4)); i++){
        averaged_val = averaged_val + ADC_GetConversion(read_ch);
    }
    
    return (averaged_val<<4);
}


void set_led(uint8_t led_color) {
//red and blue LED pin mapping flipped    
LED_B_LAT = (~led_color>>2)&1;
LED_G_LAT = (~led_color>>1)&1;
LED_R_LAT = (~led_color)&1;
    
}

void zero_stage_1(void){
    uint32_t gnd_ref_val;
    uint16_t best_dac_val = 0;
    uint16_t best_dac_val_l;
    uint32_t stage_val;
    int32_t best_val = ADC_MAX_VAL; 
    int32_t diff_value;
    
    uint16_t start_dac;
    uint16_t end_dac;
    
    uint8_t old_bw = MUX_SEL1_LAT;
    uint8_t old_gain = MUX_SEL2_LAT;
    
    //switch gain to low gain
    MUX_SEL2_LAT = 1;
        //switch bw to low 
    MUX_SEL1_LAT = 0;
    
        
    //initial ranging 
    DAC1_Load10bitInputData(512);
     __delay_ms(20);
     gnd_ref_val = average_adc_reading(GNDREF_SENSE);

    stage_val = average_adc_reading(STAGE2_MON);
    diff_value = (int32_t) stage_val - (int32_t) gnd_ref_val;
    
    if(diff_value > ((1<<ADC_SUPERSAMPLE)*50)){ //250mV
        start_dac = 16;
        end_dac = 512;
    }
    else if (diff_value < ((1<<ADC_SUPERSAMPLE)*(-50)) ){ //-250mv 
        start_dac = 512;
        end_dac = 1007;
    }
    else{
        start_dac = 255;
        end_dac = 768;
    }
    
    DAC1_Load10bitInputData(start_dac);
    __delay_ms(20);
    
    stage_val = average_adc_reading(STAGE2_MON);
    diff_value = (int32_t) stage_val - (int32_t) gnd_ref_val;
    
    for(uint16_t i = start_dac; i<end_dac; i++){
        
        DAC1_Load10bitInputData(i);
        if(i%10==0){ 
            gnd_ref_val = average_adc_reading_quick(GNDREF_SENSE);
        } 
        stage_val = average_adc_reading_quick(STAGE2_MON);
        diff_value = (int32_t) stage_val - (int32_t) gnd_ref_val;
        if (labs(diff_value)<= labs(best_val)){
            best_val = diff_value;
            best_dac_val = i;
        }
  
        //break if diff value is greater than 25mv
        if((diff_value > (1<<ADC_SUPERSAMPLE)*5) && (i > start_dac+10) ){
            break;
        }
    }
    
    DAC1_Load10bitInputData(best_dac_val);
    __delay_ms(50);
    //ramp up 
    gnd_ref_val = average_adc_reading(GNDREF_SENSE);
    best_val = ADC_MAX_VAL;
    start_dac = best_dac_val - 15;
    end_dac = best_dac_val + 15;
    DAC1_Load10bitInputData(start_dac);
    __delay_ms(100);
    for(uint16_t i = start_dac; i<end_dac; i++){
        
        DAC1_Load10bitInputData(i);
        stage_val = average_adc_reading(STAGE2_MON);
        __delay_ms(2);
        diff_value = (int32_t) stage_val - (int32_t) gnd_ref_val;
        if (labs(diff_value)<= labs(best_val)){
            best_val = diff_value;
            best_dac_val = i;
        }
    }
    
    //ramp down 
    best_dac_val_l = best_dac_val;
    best_val = ADC_MAX_VAL;
    
    for(uint16_t i = end_dac; i> start_dac; i--){
        
        DAC1_Load10bitInputData(i);
        stage_val = average_adc_reading(STAGE2_MON);
        __delay_ms(2);
        diff_value = (int32_t) stage_val - (int32_t) gnd_ref_val;
        if (labs(diff_value)<= labs(best_val)){
            best_val = diff_value;
            best_dac_val = i;
        }
    }
    
    //set new DAC value and restore old settings
    best_dac_val = (best_dac_val + best_dac_val_l)>>1;   
    DAC1_Load10bitInputData(best_dac_val);
    MUX_SEL1_LAT = old_bw;
    MUX_SEL2_LAT = old_gain;
}



void zero_stage_2(void){
    uint32_t gnd_ref_val;
    uint16_t best_dac_val = 0;
    uint32_t stage_val;
    uint16_t best_dac_val_l;

    uint8_t old_gain = MUX_SEL2_LAT;
    uint8_t old_bw = MUX_SEL1_LAT;
    
    int32_t best_val = ADC_MAX_VAL; 
    int32_t diff_value;
    
    uint16_t start_dac;
    uint16_t end_dac;
    
    //switch gain to high gain
    MUX_SEL2_LAT = 0;
    //switch bw to low 
    MUX_SEL1_LAT = 0;
    
    //initial ranging 
    DAC5_Load10bitInputData(512);
     __delay_ms(20);
     gnd_ref_val = average_adc_reading(GNDREF_SENSE);

    stage_val = average_adc_reading(STAGE2_MON);
    diff_value = (int32_t) stage_val - (int32_t) gnd_ref_val;
    
    if(diff_value < ((1<<ADC_SUPERSAMPLE)*-8)){ //40mV
        start_dac = 16;
        end_dac = 512;
    }
    else if (diff_value > ((1<<ADC_SUPERSAMPLE)*8) ){ //-40mv 
        start_dac = 512;
        end_dac = 1007;
    }
    else{
        start_dac = 255;
        end_dac = 768;
    }
    
    //rough ramp
    DAC5_Load10bitInputData(start_dac);
    __delay_ms(20);
    
    stage_val = average_adc_reading(STAGE2_MON);
    diff_value = (int32_t) stage_val - (int32_t) gnd_ref_val;
    
    for(uint16_t i = start_dac; i<end_dac; i++){
        
        DAC5_Load10bitInputData(i);
        if(i%10==0){
            gnd_ref_val = average_adc_reading_quick(GNDREF_SENSE);
        }
        
        stage_val = average_adc_reading_quick(STAGE2_MON);
        diff_value = (int32_t) stage_val - (int32_t) gnd_ref_val;
        if (labs(diff_value)<= labs(best_val)){
            best_val = diff_value;
            best_dac_val = i;
        }
      
        //break if diff value is greater than 20mv
        if((diff_value < (1<<ADC_SUPERSAMPLE)*(-4)) && (i > start_dac+10)){
            break;
        }
    }
    
    //ramp up 
    DAC5_Load10bitInputData(best_dac_val);
    __delay_ms(50);

    gnd_ref_val = average_adc_reading(GNDREF_SENSE);
    best_val = ADC_MAX_VAL;
    start_dac = best_dac_val - 15;
    end_dac = best_dac_val + 15;
    DAC5_Load10bitInputData(start_dac);
    __delay_ms(100);
    for(uint16_t i = start_dac; i<end_dac; i++){
        
        DAC5_Load10bitInputData(i);
        stage_val = average_adc_reading(STAGE2_MON);
        __delay_ms(3);
        diff_value = (int32_t) stage_val - (int32_t) gnd_ref_val;
        if (labs(diff_value)<= labs(best_val)){
            best_val = diff_value;
            best_dac_val = i;
        }
    }
    
    //dac ramp down 
    best_dac_val_l = best_dac_val;
    best_val = ADC_MAX_VAL;
    
    for(uint16_t i = end_dac; i> start_dac; i--){
        
        DAC5_Load10bitInputData(i);
        stage_val = average_adc_reading(STAGE2_MON);
        __delay_ms(3);
        diff_value = (int32_t) stage_val - (int32_t) gnd_ref_val;
        if (labs(diff_value)<= labs(best_val)){
            best_val = diff_value;
            best_dac_val = i;
        }
    }
    
    //set new DAC value and restore all settings 
    best_dac_val = (best_dac_val + best_dac_val_l)>>1;        
    DAC5_Load10bitInputData(best_dac_val);
    MUX_SEL1_LAT = old_bw;
    MUX_SEL2_LAT = old_gain;
}

void init_sensor(void){
    uint32_t gnd_ref_val;
    uint32_t stage_val;
    int32_t diff_value;
    
    __delay_ms(5);
    zero_stage_1();
    //only zero second stage if in use
    if(MUX_SEL2_LAT == 0){
        __delay_ms(50);
        zero_stage_2();
    }
    
    stage_val = average_adc_reading(STAGE2_MON);
    gnd_ref_val = average_adc_reading(GNDREF_SENSE);
    diff_value = (int32_t) gnd_ref_val - (int32_t) stage_val ;
    if ( labs(diff_value) > ((1<<ADC_SUPERSAMPLE)*20) ){ //100mV offset
        set_led(LED_RED);
        __delay_ms(3000);
        set_led(led_color_state);
    }
}

void reset_sensor(){
    SR_SetLow();
     __delay_ms(40);
    SR_SetHigh();
     __delay_ms(40);
    SR_SetLow();
    __delay_ms(50);
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
    DAC3_SetOutput(25); //set overload high comparator  
    DAC4_SetOutput(7); //set overload low comparator 
    
    //init offset dac
    DAC5_Load10bitInputData(512);
    DAC1_Load10bitInputData(512);
    __delay_ms(50);
    
    //absolute field sensing / debug mode
    if((SW1_GetValue() == 0) && (SW2_GetValue() == 0)){
        set_led(LED_PURPLE);
        while(1){
            SR_SetLow();
            __delay_ms(9);
            SR_SetHigh();
            __delay_ms(9);
        }
    }
    
    led_color_state = LED_GREEN;
    mux_state = 0;
    SW2_ISR();//initialize LED and mux
    reset_sensor();
    __delay_ms(100); 
    zero_stage_1();
    __delay_ms(50);
    zero_stage_2();
    //zeroing system may trip over range comparators 
    PIR2bits.C2IF = 0;
    PIR2bits.C1IF = 0;
    //set interrupt handler for SW2
    IOCBF0_SetInterruptHandler(SW2_ISR);
    //set interrupt handler for SW1
    IOCCF7_SetInterruptHandler(SW1_ISR); 
    set_led(LED_OFF);
    __delay_ms(200);
    set_led(led_color_state);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    while (1)
    {
        __delay_ms(500);
        if((average_adc_reading(channel_FVRBuffer1)>>ADC_SUPERSAMPLE) > HIGH_FVR_VOLTAGE){
            INTERRUPT_GlobalInterruptDisable();
            INTERRUPT_PeripheralInterruptDisable();
            low_battery_loop();
        }
    }
}
/**
 End of File
*/