/**
  DAC5 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    dac5.c

  @Summary
    This is the generated driver implementation file for the DAC5 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for DAC5.
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "dac5.h"

/**
  Section: Macros
*/

/**
 *  Loads data from DAC buffer onto the DAC output
 */
#define DAC5_DoubleBufferLatch() \
    (DACLDbits.DAC5LD = 1)

/**
  Section: DAC5 APIs
*/

void DAC5_Initialize(void)
{
    // DAC5FM right justified; DACEN enabled; DACNSS VSS; DACPSS VDD; DACOE1 enabled; DACOE2 disabled; 
    DAC5CON0 = 0xA0;
    // 
    DAC5REFH = 0x00;
    // 
    DAC5REFL = 0xCD;
    //Loading DAC5 double buffer data to latch.
    DAC5_DoubleBufferLatch();
}


void DAC5_Load16bitInputData(uint16_t input16BitData)
{
    //DAC input reference range should be 16bit.
    //Input data left justified.
    DAC5CON0bits.DAC5FM = 1;
    
    //Loading 16bit data to DAC5
    DAC5REFL  = (uint8_t) input16BitData;  
    DAC5REFH  = (uint8_t)(input16BitData >> 8);
    //Loading DAC5 double buffer data to latch.
    DAC5_DoubleBufferLatch();
}

void DAC5_Load10bitInputData(uint16_t input10BitData)
{
    //DAC input reference range should be 10bit.
    //Input data right justified.
    DAC5CON0bits.DAC5FM = 0;
    
    //Loading 10bit data to DAC5
    DAC5REFL  = (uint8_t) input10BitData;  
    DAC5REFH  = (uint8_t)(input10BitData >> 8);
    //Loading DAC5 double buffer data to latch.
    DAC5_DoubleBufferLatch();
}

void DAC5_Load8bitInputData(uint8_t input8BitData)
{
    //DAC input reference range should be 8 bit.
    //Input data right justified.
    DAC5CON0bits.DAC5FM = 0;
    
    //Loading 10bit data to DAC5
    DAC5REFL  = input8BitData;  
    //Loading DAC5 double buffer data to latch.
    DAC5_DoubleBufferLatch();
}

uint16_t DAC5_Read10BitInputData(void) {
    // Right justified, to match ?load? function
    DAC5CON0bits.DAC5FM = 0;

    // Read data
    uint16_t data = ((uint16_t) DAC5REFH) << 8;
    data |= ((uint16_t) DAC5REFL);

    return data;
}
/**
 End of File
*/ 



