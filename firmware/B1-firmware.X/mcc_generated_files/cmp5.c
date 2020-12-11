 /**
   CMP5 Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     cmp5.c
 
   @Summary
     This is the generated driver implementation file for the CMP5 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This source file provides implementations for driver APIs for CMP5.
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
 
 /**
   Section: Included Files
 */


#include <xc.h>
#include "cmp5.h"
/**
  Section: CMP5 APIs
*/

void CMP5_Initialize(void)
{

	// C5HYS disabled; C5SP hi_speed; C5ON disabled; C5POL not inverted; C5SYNC asynchronous; C5ZLF unfiltered;                          
    CM5CON0 = 0x04;
	
	// C5INTN no_intFlag; C5INTP no_intFlag;                          
    CM5CON1 = 0x00;
	
	// C5NCH Vss;                          
    CM5NSEL = 0x08;
	
	// C5PCH Vss;                          
    CM5PSEL = 0x09;
	
	// MC5OUT 0;                          
    CMOUT = 0x00;
	
}

bool CMP5_GetOutputStatus(void)
{
	return (CMOUTbits.MC5OUT);
}


/**
 End of File
*/
