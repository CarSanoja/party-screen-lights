/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MANAGER_PIXEL_H
#define	MANAGER_PIXEL_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "manager_pixel_mode.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define RED                     0
#define GRN                     1
#define BLU                     2

#define COLOR_GREEN             0, 100, 0
#define COLOR_BLACK             0, 0, 0
#define COLOR_RED               100, 0, 0
#define COLOR_BLUE              0, 0, 100

#define PANELCOUNT              1
#define FRAMEBUFFERSIZE         8 * PANELCOUNT
//#define LEDCOUNT                PANELCOUNT * 64
#define PACKETCOUNT             LEDCOUNT * 3
#define STRINGBUFFERSIZE        30
#define STRINGARRAYSIZE         STRINGBUFFERSIZE * 6

void pixel_init(void);

void pixel_set(uint32_t program_count, uint8_t mode, uint8_t flag_audio, uint8_t audio_signal);

void ShowRainbowScan( void );

void ShowColor( unsigned char r, unsigned char g, unsigned char b );

void UpdateDisplay( void );

void DisplayShowArray( uint32_t bg, uint32_t fg );

void DisplaySweep( void );

void PrintText( unsigned char *Text);

void PrintCharStringBuffer( unsigned char ch, unsigned char pos );

void PrintCharFrameBuffer( unsigned char ch );

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

