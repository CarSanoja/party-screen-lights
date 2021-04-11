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

#define PANELCOUNT              2
#define FRAMEBUFFERSIZE         8 * PANELCOUNT
#define NUM_PIXELS              PANELCOUNT*64
//#define LEDCOUNT                PANELCOUNT * 64
#define PACKETCOUNT             NUM_PIXELS * 3
#define STRINGBUFFERSIZE        30
#define STRINGARRAYSIZE         STRINGBUFFERSIZE * 6

void pixel_init(void);

void pixel_set(uint32_t program_count, uint8_t mode, uint8_t flag_audio, uint8_t audio_signal);

unsigned char FrameBuffer[FRAMEBUFFERSIZE];

unsigned char StringBuffer[STRINGARRAYSIZE];

void ShowRainbowScan( void );

void ShowColor( unsigned char r, unsigned char g, unsigned char b );

void UpdateDisplay( void );

void DisplayShowArray( uint32_t bg, uint32_t fg );

void DisplaySweep( void );

void PrintText( unsigned char *Text);

void PrintCharStringBuffer( unsigned char ch, unsigned char pos );

void PrintCharFrameBuffer( unsigned char ch );

const unsigned char Letters[130]={		// Uppercase Definitions			
    0x7e,0x11,0x11,0x11,0x7e,	// 41 A
    0x7f,0x49,0x49,0x49,0x36,	// 42 B
    0x3e,0x41,0x41,0x41,0x22,	// 43 C
    0x7f,0x41,0x41,0x22,0x1c,	// 44 D
    0x7f,0x49,0x49,0x49,0x41,	// 45 E
    0x7f,0x09,0x09,0x09,0x01,	// 46 F
    0x3e,0x41,0x49,0x49,0x7a,	// 47 G
    0x7f,0x08,0x08,0x08,0x7f,	// 48 H
    0x00,0x41,0x7f,0x41,0x00,	// 49 I
    0x20,0x40,0x41,0x3f,0x01,	// 4a J
    0x7f,0x08,0x14,0x22,0x41,	// 4b K
    0x7f,0x40,0x40,0x40,0x40,	// 4c L
    0x7f,0x02,0x0c,0x02,0x7f,	// 4d M
    0x7f,0x04,0x08,0x10,0x7f,	// 4e N
    0x3e,0x41,0x41,0x41,0x3e,	// 4f O
    0x7f,0x09,0x09,0x09,0x06,	// 50 P
    0x3e,0x41,0x51,0x21,0x5e,	// 51 Q
    0x7f,0x09,0x19,0x29,0x46,	// 52 R
    0x46,0x49,0x49,0x49,0x31,	// 53 S
    0x01,0x01,0x7f,0x01,0x01,	// 54 T
    0x3f,0x40,0x40,0x40,0x3f,	// 55 U
    0x1f,0x20,0x40,0x20,0x1f,	// 56 V
    0x3f,0x40,0x38,0x40,0x3f,	// 57 W
    0x63,0x14,0x08,0x14,0x63,	// 58 X
    0x07,0x08,0x70,0x08,0x07,	// 59 Y
    0x61,0x51,0x49,0x45,0x43};	// 5a Z

const unsigned char Wheel[256][3] __at(0x400) = 
{
{252,0,3},
{249,0,6},
{246,0,9},
{243,0,12},
{240,0,15},
{237,0,18},
{234,0,21},
{231,0,24},
{228,0,27},
{225,0,30},
{222,0,33},
{219,0,36},
{216,0,39},
{213,0,42},
{210,0,45},
{207,0,48},
{204,0,51},
{201,0,54},
{198,0,57},
{195,0,60},
{192,0,63},
{189,0,66},
{186,0,69},
{183,0,72},
{180,0,75},
{177,0,78},
{174,0,81},
{171,0,84},
{168,0,87},
{165,0,90},
{162,0,93},
{159,0,96},
{156,0,99},
{153,0,102},
{150,0,105},
{147,0,108},
{144,0,111},
{141,0,114},
{138,0,117},
{135,0,120},
{132,0,123},
{129,0,126},
{126,0,129},
{123,0,132},
{120,0,135},
{117,0,138},
{114,0,141},
{111,0,144},
{108,0,147},
{105,0,150},
{102,0,153},
{99,0,156},
{96,0,159},
{93,0,162},
{90,0,165},
{87,0,168},
{84,0,171},
{81,0,174},
{78,0,177},
{75,0,180},
{72,0,183},
{69,0,186},
{66,0,189},
{63,0,192},
{60,0,195},
{57,0,198},
{54,0,201},
{51,0,204},
{48,0,207},
{45,0,210},
{42,0,213},
{39,0,216},
{36,0,219},
{33,0,222},
{30,0,225},
{27,0,228},
{24,0,231},
{21,0,234},
{18,0,237},
{15,0,240},
{12,0,243},
{9,0,246},
{6,0,249},
{3,0,252},
{0,0,255},
{0,3,252},
{0,6,249},
{0,9,246},
{0,12,243},
{0,15,240},
{0,18,237},
{0,21,234},
{0,24,231},
{0,27,228},
{0,30,225},
{0,33,222},
{0,36,219},
{0,39,216},
{0,42,213},
{0,45,210},
{0,48,207},
{0,51,204},
{0,54,201},
{0,57,198},
{0,60,195},
{0,63,192},
{0,66,189},
{0,69,186},
{0,72,183},
{0,75,180},
{0,78,177},
{0,81,174},
{0,84,171},
{0,87,168},
{0,90,165},
{0,93,162},
{0,96,159},
{0,99,156},
{0,102,153},
{0,105,150},
{0,108,147},
{0,111,144},
{0,114,141},
{0,117,138},
{0,120,135},
{0,123,132},
{0,126,129},
{0,129,126},
{0,132,123},
{0,135,120},
{0,138,117},
{0,141,114},
{0,144,111},
{0,147,108},
{0,150,105},
{0,153,102},
{0,156,99},
{0,159,96},
{0,162,93},
{0,165,90},
{0,168,87},
{0,171,84},
{0,174,81},
{0,177,78},
{0,180,75},
{0,183,72},
{0,186,69},
{0,189,66},
{0,192,63},
{0,195,60},
{0,198,57},
{0,201,54},
{0,204,51},
{0,207,48},
{0,210,45},
{0,213,42},
{0,216,39},
{0,219,36},
{0,222,33},
{0,225,30},
{0,228,27},
{0,231,24},
{0,234,21},
{0,237,18},
{0,240,15},
{0,243,12},
{0,246,9},
{0,249,6},
{0,252,3},
{0,255,0},
{3,252,0},
{6,249,0},
{9,246,0},
{12,243,0},
{15,240,0},
{18,237,0},
{21,234,0},
{24,231,0},
{27,228,0},
{30,225,0},
{33,222,0},
{36,219,0},
{39,216,0},
{42,213,0},
{45,210,0},
{48,207,0},
{51,204,0},
{54,201,0},
{57,198,0},
{60,195,0},
{63,192,0},
{66,189,0},
{69,186,0},
{72,183,0},
{75,180,0},
{78,177,0},
{81,174,0},
{84,171,0},
{87,168,0},
{90,165,0},
{93,162,0},
{96,159,0},
{99,156,0},
{102,153,0},
{105,150,0},
{108,147,0},
{111,144,0},
{114,141,0},
{117,138,0},
{120,135,0},
{123,132,0},
{126,129,0},
{129,126,0},
{132,123,0},
{135,120,0},
{138,117,0},
{141,114,0},
{144,111,0},
{147,108,0},
{150,105,0},
{153,102,0},
{156,99,0},
{159,96,0},
{162,93,0},
{165,90,0},
{168,87,0},
{171,84,0},
{174,81,0},
{177,78,0},
{180,75,0},
{183,72,0},
{186,69,0},
{189,66,0},
{192,63,0},
{195,60,0},
{198,57,0},
{201,54,0},
{204,51,0},
{207,48,0},
{210,45,0},
{213,42,0},
{216,39,0},
{219,36,0},
{222,33,0},
{225,30,0},
{228,27,0},
{231,24,0},
{234,21,0},
{237,18,0},
{240,15,0},
{243,12,0},
{246,9,0},
{249,6,0},
{252,3,0},
{255,0,0},
};

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

