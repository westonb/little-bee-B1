/**
  DAC7 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    dac7.h

  @Summary
    This is the generated header file for the DAC7 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for DAC7.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC16F1776
        Driver Version    :  2.10
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

#ifndef DAC7_H
#define DAC7_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: DAC7 APIs
*/

/**
  @Summary
    Initializes the DAC7

  @Description
    This routine initializes the DAC7.
    This routine must be called before any other DAC7 routine is called.
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
    DAC7_Initialize();
    </code>
*/
void DAC7_Initialize(void);

/**
  @Summary
    Set Input data into DAC7.

  @Description
    This routine pass the digital input data into
    DAC7 voltage reference control register.

  @Preconditions
    The DAC7_Initialize() routine should be called
    prior to use this routine.

  @Param
    inputData - 8bit digital data to DAC7.

  @Returns
    None

  @Example
    <code>
    uint8_t count=0;

    DAC7_Initialize();

    for(count=0; count<=30; count++)
    {
        DAC7_SetOutput(count);
    }

    while(1)
    {
    }
    </code>
*/
void DAC7_SetOutput(uint8_t inputData);

/**
  @Summary
    Read input data fed to DAC7.

  @Description
    This routine reads the digital input data fed to
    DAC7 voltage reference control register.

  @Preconditions
    The DAC7_Initialize() routine should be called
    prior to use this routine.

  @Param
    None

  @Returns
    uint8_t inputData - digital data fed to DAC7

  @Example
    <code>
    uint8_t count=0;
    uint8_t inputData;

    DAC7_Initialize();

    inputData = DAC7_GetOutput();

    while(1)
    {
    }
    </code>
*/
uint8_t DAC7_GetOutput(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // DAC7_H
/**
 End of File
*/
