/**
  DAC5 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    dac5.h

  @Summary
    This is the generated header file for the DAC5 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for DAC5.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC16F1776
        Driver Version    :  2.01
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

#ifndef DAC5_H
#define DAC5_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: DAC5 APIs
*/

/**
  @Summary
    Initializes the DAC5

  @Description
    This routine initializes the DAC5.
    This routine must be called before any other DAC5 routine is called.
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
    DAC5_Initialize();
    </code>
*/

void DAC5_Initialize(void);
/**
  @Summary
    Load 16bit input data to DAC5.

  @Description
    This routine passes the 16bit input data into
    DAC5 voltage reference control register.This data will
    be left justified. 
 
  @Preconditions
    The DAC5_Initialize() routine should be called
    before using this routine.DAC input reference range should be 16bit.
 
  @Param
    input16BitData - 16bit input data to DAC5.

  @Returns
    None

  @Example
    <code>
    uint16_t count=0xFFFF;

    DAC5_Initialize();
    DAC5_Load16bitInputData(count);
    while(1)
    {
    }
    </code>
*/
void DAC5_Load16bitInputData(uint16_t input16BitData);

/**
  @Summary
    Load 10bit input data to DAC5.

  @Description
    This routine passes the 10bit input data into DAC5 
    voltage reference control register.This data will be right justified. 
 
  @Preconditions
   The DAC5_Initialize() routine should be called
   before using this routine.DAC input reference range should be 10bit.
 
  @Param
    input10BitData - 10bit input data to DAC5.

  @Returns
    None

  @Example
    <code>
    uint16_t count=0x3FF;

    DAC5_Initialize();
    DAC5_Load10bitInputData(count);
    while(1)
    {
    }
    </code>
*/
void DAC5_Load10bitInputData(uint16_t input10BitData);

/**
  @Summary
    Load 8 bit input data to DAC5.

  @Description
    This routine passes the 8 bit input data into DAC5 
    voltage reference control register.This data will be right justified. 
 
  @Preconditions
   The DAC5_Initialize() routine should be called
   before using this routine.DAC input reference range should be 10bit.
 
  @Param
    input8BitData - 8 bit input data to DAC5.

  @Returns
    None

  @Example
    <code>
    uint8_t count=0x3F;

    DAC5_Initialize();
    DAC5_Load8bitInputData(count);
    while(1)
    {
    }
    </code>
*/
void DAC5_Load8bitInputData(uint8_t input8BitData);

/**
  @Summary
    Read 10bit data from DAC5.

  @Description
    This routine reads the 10bit data from DAC5 
    voltage reference control register.This data will be right justified. 
 
  @Preconditions
   The DAC5_Initialize() routine should be called
   before using this routine.DAC input reference range should be 10bit.

  @Returns
    uint16_t - 10bit data from DAC5.

  @Example
    <code>
    uint16_t count=0x3FF;

    DAC5_Initialize();
    DAC5_Load10bitInputData(count);
    
    // Make sure data was written to DAC correctly
    __conditional_software_breakpoint(count == DAC5_Read10BitInputData(count));
    </code>
*/
uint16_t DAC5_Read10BitInputData(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // DAC5_H
/**
 End of File
*/

