 /**
   CMP1 Generated Driver API Header File
 
   @Company
     Microchip Technology Inc. 

   @File Name
    cmp1.h

   @Summary
     This is the generated header file for the CMP1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This header file provides APIs for driver for CMP1.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
         Device            :  PIC16F1776
         Driver Version    :  2.11
     The generated drivers are tested against the following:
         Compiler          :  XC8 2.20 and above or later
         MPLAB             :  MPLAB X 5.40
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

#ifndef CMP1_H
#define CMP1_H
 
 /**
   Section: Included Files
 */

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: CMP1 APIs
*/

/**
  @Summary
    Initializes the CMP1

  @Description
    This routine initializes the CMP1.
    This routine must be called before any other CMP1 routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment

  @Example
    <code>
    CMP1_Initialize();
    </code>
*/
void CMP1_Initialize(void);

/**
  @Summary
    Gets the CMP1 output status.

  @Description
    This routine gets the CMP1 output status.

  @Preconditions
    The CMP1 initializer routine should be called
    prior to use this routine.

  @Param
    None

  @Returns
    high  - if the CMP1 output is high.
    low   - if the CMP1 output is low.

  @Example
    <code>
    #define LED_On  LATAbits.LATA0=1
    #define LED_Off LATAbits.LATA0=0

    CMP1_Initialize();

    while(1)
    {
        if(CMP1_GetOutputStatus())
        {
            LED_On;
        }
        else
        {
             LED_Off;
        }
    }
    </code>
*/
bool CMP1_GetOutputStatus(void);

/**
  @Summary
    Implements ISR

  @Description
    This routine is used to implement the ISR for the interrupt-driven
    implementations.

  @Returns
    None

  @Param
    None
*/
void CMP1_ISR(void);


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // CMP1_H
/**
 End of File
*/

