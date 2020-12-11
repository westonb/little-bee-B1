/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC16F1776
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set GNDREF_SENSE aliases
#define GNDREF_SENSE_TRIS                 TRISAbits.TRISA0
#define GNDREF_SENSE_LAT                  LATAbits.LATA0
#define GNDREF_SENSE_PORT                 PORTAbits.RA0
#define GNDREF_SENSE_WPU                  WPUAbits.WPUA0
#define GNDREF_SENSE_OD                   ODCONAbits.ODA0
#define GNDREF_SENSE_ANS                  ANSELAbits.ANSA0
#define GNDREF_SENSE_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define GNDREF_SENSE_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define GNDREF_SENSE_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define GNDREF_SENSE_GetValue()           PORTAbits.RA0
#define GNDREF_SENSE_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define GNDREF_SENSE_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define GNDREF_SENSE_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define GNDREF_SENSE_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define GNDREF_SENSE_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define GNDREF_SENSE_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define GNDREF_SENSE_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define GNDREF_SENSE_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RA5 procedures
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode()         do { ANSELAbits.ANSA5 = 1; } while(0)
#define RA5_SetDigitalMode()        do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set SR aliases
#define SR_TRIS                 TRISAbits.TRISA6
#define SR_LAT                  LATAbits.LATA6
#define SR_PORT                 PORTAbits.RA6
#define SR_WPU                  WPUAbits.WPUA6
#define SR_OD                   ODCONAbits.ODA6
#define SR_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define SR_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define SR_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define SR_GetValue()           PORTAbits.RA6
#define SR_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define SR_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define SR_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define SR_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define SR_SetPushPull()        do { ODCONAbits.ODA6 = 0; } while(0)
#define SR_SetOpenDrain()       do { ODCONAbits.ODA6 = 1; } while(0)

// get/set MUX_SEL1 aliases
#define MUX_SEL1_TRIS                 TRISAbits.TRISA7
#define MUX_SEL1_LAT                  LATAbits.LATA7
#define MUX_SEL1_PORT                 PORTAbits.RA7
#define MUX_SEL1_WPU                  WPUAbits.WPUA7
#define MUX_SEL1_OD                   ODCONAbits.ODA7
#define MUX_SEL1_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define MUX_SEL1_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define MUX_SEL1_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define MUX_SEL1_GetValue()           PORTAbits.RA7
#define MUX_SEL1_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define MUX_SEL1_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define MUX_SEL1_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define MUX_SEL1_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define MUX_SEL1_SetPushPull()        do { ODCONAbits.ODA7 = 0; } while(0)
#define MUX_SEL1_SetOpenDrain()       do { ODCONAbits.ODA7 = 1; } while(0)

// get/set SW2 aliases
#define SW2_TRIS                 TRISBbits.TRISB0
#define SW2_LAT                  LATBbits.LATB0
#define SW2_PORT                 PORTBbits.RB0
#define SW2_WPU                  WPUBbits.WPUB0
#define SW2_ANS                  ANSELBbits.ANSB0
#define SW2_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define SW2_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define SW2_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define SW2_GetValue()           PORTBbits.RB0
#define SW2_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define SW2_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define SW2_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define SW2_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define SW2_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define SW2_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set MUX_SEL2 aliases
#define MUX_SEL2_TRIS                 TRISBbits.TRISB4
#define MUX_SEL2_LAT                  LATBbits.LATB4
#define MUX_SEL2_PORT                 PORTBbits.RB4
#define MUX_SEL2_WPU                  WPUBbits.WPUB4
#define MUX_SEL2_OD                   ODCONBbits.ODB4
#define MUX_SEL2_ANS                  ANSELBbits.ANSB4
#define MUX_SEL2_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define MUX_SEL2_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define MUX_SEL2_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define MUX_SEL2_GetValue()           PORTBbits.RB4
#define MUX_SEL2_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define MUX_SEL2_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define MUX_SEL2_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define MUX_SEL2_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define MUX_SEL2_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define MUX_SEL2_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define MUX_SEL2_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define MUX_SEL2_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set VIN_SENSE aliases
#define VIN_SENSE_TRIS                 TRISBbits.TRISB5
#define VIN_SENSE_LAT                  LATBbits.LATB5
#define VIN_SENSE_PORT                 PORTBbits.RB5
#define VIN_SENSE_WPU                  WPUBbits.WPUB5
#define VIN_SENSE_OD                   ODCONBbits.ODB5
#define VIN_SENSE_ANS                  ANSELBbits.ANSB5
#define VIN_SENSE_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define VIN_SENSE_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define VIN_SENSE_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define VIN_SENSE_GetValue()           PORTBbits.RB5
#define VIN_SENSE_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define VIN_SENSE_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define VIN_SENSE_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define VIN_SENSE_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define VIN_SENSE_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define VIN_SENSE_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define VIN_SENSE_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define VIN_SENSE_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)

// get/set STAGE2_MON aliases
#define STAGE2_MON_TRIS                 TRISCbits.TRISC2
#define STAGE2_MON_LAT                  LATCbits.LATC2
#define STAGE2_MON_PORT                 PORTCbits.RC2
#define STAGE2_MON_WPU                  WPUCbits.WPUC2
#define STAGE2_MON_OD                   ODCONCbits.ODC2
#define STAGE2_MON_ANS                  ANSELCbits.ANSC2
#define STAGE2_MON_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define STAGE2_MON_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define STAGE2_MON_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define STAGE2_MON_GetValue()           PORTCbits.RC2
#define STAGE2_MON_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define STAGE2_MON_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define STAGE2_MON_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define STAGE2_MON_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define STAGE2_MON_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define STAGE2_MON_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define STAGE2_MON_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define STAGE2_MON_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set STAGE1_MON aliases
#define STAGE1_MON_TRIS                 TRISCbits.TRISC3
#define STAGE1_MON_LAT                  LATCbits.LATC3
#define STAGE1_MON_PORT                 PORTCbits.RC3
#define STAGE1_MON_WPU                  WPUCbits.WPUC3
#define STAGE1_MON_OD                   ODCONCbits.ODC3
#define STAGE1_MON_ANS                  ANSELCbits.ANSC3
#define STAGE1_MON_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define STAGE1_MON_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define STAGE1_MON_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define STAGE1_MON_GetValue()           PORTCbits.RC3
#define STAGE1_MON_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define STAGE1_MON_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define STAGE1_MON_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define STAGE1_MON_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define STAGE1_MON_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define STAGE1_MON_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define STAGE1_MON_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define STAGE1_MON_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set LED_R aliases
#define LED_R_TRIS                 TRISCbits.TRISC4
#define LED_R_LAT                  LATCbits.LATC4
#define LED_R_PORT                 PORTCbits.RC4
#define LED_R_WPU                  WPUCbits.WPUC4
#define LED_R_OD                   ODCONCbits.ODC4
#define LED_R_ANS                  ANSELCbits.ANSC4
#define LED_R_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LED_R_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LED_R_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LED_R_GetValue()           PORTCbits.RC4
#define LED_R_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LED_R_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LED_R_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define LED_R_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define LED_R_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define LED_R_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)
#define LED_R_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define LED_R_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set LED_G aliases
#define LED_G_TRIS                 TRISCbits.TRISC5
#define LED_G_LAT                  LATCbits.LATC5
#define LED_G_PORT                 PORTCbits.RC5
#define LED_G_WPU                  WPUCbits.WPUC5
#define LED_G_OD                   ODCONCbits.ODC5
#define LED_G_ANS                  ANSELCbits.ANSC5
#define LED_G_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED_G_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED_G_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LED_G_GetValue()           PORTCbits.RC5
#define LED_G_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED_G_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LED_G_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LED_G_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LED_G_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define LED_G_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)
#define LED_G_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define LED_G_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set LED_B aliases
#define LED_B_TRIS                 TRISCbits.TRISC6
#define LED_B_LAT                  LATCbits.LATC6
#define LED_B_PORT                 PORTCbits.RC6
#define LED_B_WPU                  WPUCbits.WPUC6
#define LED_B_OD                   ODCONCbits.ODC6
#define LED_B_ANS                  ANSELCbits.ANSC6
#define LED_B_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define LED_B_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define LED_B_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define LED_B_GetValue()           PORTCbits.RC6
#define LED_B_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define LED_B_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define LED_B_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define LED_B_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define LED_B_SetPushPull()        do { ODCONCbits.ODC6 = 0; } while(0)
#define LED_B_SetOpenDrain()       do { ODCONCbits.ODC6 = 1; } while(0)
#define LED_B_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define LED_B_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set SW1 aliases
#define SW1_TRIS                 TRISCbits.TRISC7
#define SW1_LAT                  LATCbits.LATC7
#define SW1_PORT                 PORTCbits.RC7
#define SW1_WPU                  WPUCbits.WPUC7
#define SW1_OD                   ODCONCbits.ODC7
#define SW1_ANS                  ANSELCbits.ANSC7
#define SW1_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SW1_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SW1_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SW1_GetValue()           PORTCbits.RC7
#define SW1_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define SW1_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define SW1_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define SW1_SetPushPull()        do { ODCONCbits.ODC7 = 0; } while(0)
#define SW1_SetOpenDrain()       do { ODCONCbits.ODC7 = 1; } while(0)
#define SW1_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF0 pin functionality
 * @Example
    IOCBF0_ISR();
 */
void IOCBF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_InterruptHandler);

*/
extern void (*IOCBF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_DefaultInterruptHandler);

*/
void IOCBF0_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF7 pin functionality
 * @Example
    IOCCF7_ISR();
 */
void IOCCF7_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF7 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF7 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF7_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF7 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF7_SetInterruptHandler() method.
    This handler is called every time the IOCCF7 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(IOCCF7_InterruptHandler);

*/
extern void (*IOCCF7_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF7 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF7_SetInterruptHandler() method.
    This handler is called every time the IOCCF7 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(IOCCF7_DefaultInterruptHandler);

*/
void IOCCF7_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/