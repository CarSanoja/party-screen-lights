/*
 * File:   manager_pixel.c
 * Author: mauro
 *
 * Created on April 7, 2021, 2:58 PM
 */


#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "manager_pixel.h"
#include "manager_pixel_mode.h"

#define _XTAL_FREQ 32000000

void write_pixel(uint8_t r,uint8_t g,uint8_t b){
    SSP1BUF = g;
    while(!SSP1STATbits.BF);
    SSP1BUF = r;
    while(!SSP1STATbits.BF);
    SSP1BUF = b;
    while(!SSP1STATbits.BF);
}

void pixel_init(void) {
    //Funcion para inicializar los pixeles
    // Clear all the pixels
    wheel_index = 0;
    ShowColor( 0, 0, 0 );
    
    //clear();
    //ShowColor(COLOR_RED);
    //ShowRainbowScan();
    //ShowColor(COLOR_BLACK);
    //__delay_ms(1000);
    //PrintText("PARTY");
    //ShowRainbowScan();
}

void ShowColor( unsigned char r, unsigned char g, unsigned char b )
{
    for(unsigned char i = 0; i < NUM_PIXELS; i++)
    {
        write_pixel(r, g, b);
    }
}

void ShowColorRange( unsigned char r, unsigned char g, unsigned char b,  unsigned char start, unsigned char stop)
{
    for(unsigned char i = start; i < stop; i++)
    {
        write_pixel(r, g, b);
    }
}

// Lateral bar that changes depending on the signal level
void Animation1(uint8_t signal_level, int wheel_change){
    unsigned char limit = ((unsigned char)((signal_level*15)/255))*8+8;
    wheel_index = wheel_index + wheel_change;
    if(wheel_index > 255) wheel_index = 0; 
    if(wheel_index < 0) wheel_index = 255; 
    //write_pixel(Wheel[wheel_index][0], Wheel[wheel_index][1], Wheel[wheel_index][2]);
    ShowColorRange(Wheel[wheel_index][0], Wheel[wheel_index][1], Wheel[wheel_index][2], 0, limit);
    __delay_ms(5);    
}

// Slow Strobing
void Animation2(uint8_t signal_level){
    ShowColor(0, 0, 0);
    __delay_ms(30);  
    ShowColor(Wheel[signal_level][0], Wheel[signal_level][1], Wheel[signal_level][2]);
    __delay_ms(30);    
}

// Fast Strobing 
void Animation3(uint8_t signal_level){
    ShowColor(0, 0, 0);
    __delay_ms(5);  
    ShowColor(Wheel[signal_level][0], Wheel[signal_level][1], Wheel[signal_level][2]);
    __delay_ms(5);    
}

void pixel_set(uint32_t program_count, uint8_t mode, uint8_t flag_audio, uint8_t audio_signal) {
    //Funcion para setear los pixeles según el counter del programa, el modo y si hay audio o no
    
    //Selecciona el modo, dependiendo del estado del boton de modo (mode)
    switch(mode){
        case MODE_0: //Strobe lento
            
            if(flag_audio == 0){
                //si no hay musica hacer rutina con program_counter
                ShowColor(COLOR_CYAN);
                __delay_ms(5); 
            }else{
                //si hay musica hacer rutina con audio_signal
                Animation1(audio_signal, 10);
            }
            
        break;

        case MODE_1:  //Stobe rapido
            if(flag_audio == 0){
                //si no hay musica hacer rutina con program_counter
                ShowColor(0, 255, 0); //Green
                __delay_ms(5); 
            }else{
                //si hay musica hacer rutina con audio_signal
                Animation2(audio_signal);
            }
        break;

        case MODE_2: //Latigo desde el principio
            if(flag_audio == 0){
                //si no hay musica hacer rutina con program_counter
                ShowColor(COLOR_YELLOW);
                __delay_ms(5); 
            }else{
                //si hay musica hacer rutina con audio_signal
                Animation1(audio_signal, -10);
            }            
        break;

        case MODE_3: //Latigo desde el final
            if(flag_audio == 0){
                //si no hay musica hacer rutina con program_counter
                ShowColor(COLOR_MAGENTA);
                __delay_ms(5); 
            }else{
                //si hay musica hacer rutina con audio_signal
                Animation3(audio_signal);
            }            
        break;
        
        case MODE_OFF: //Apagado
            //apagado
            ShowColor(0, 0, 0);
            __delay_ms(5); 
        break;
        
        default:
        break;

    }
}
/*
void ShowRainbowScan( void )
{
    unsigned int i;
    for (i = 0; i < 254; i++)
    {
        ShowColor(Wheel[i][0], Wheel[i][1], Wheel[i][2]);
        i = i + 1;
        __delay_ms(50);
    }
}
*/
/*
void PrintText( unsigned char *Text )
{
    unsigned int cnt = 0;
    while (Text[cnt] != 0)
    {
        PrintCharStringBuffer(Text[cnt], cnt * 6);
        cnt++;
    }
}
*/
/* 
void PrintCharStringBuffer( unsigned char ch, unsigned char pos )
{
    unsigned char i = 0;

	if (ch == ' ')				 					// Print Space char
	{
		for (i = 0; i < 6; i++)
		{
			StringBuffer[pos + i] = 0x00;
		}
	}
    else if ((ch > 0x40) && (ch < 0x5B))	 				// Print Uppercase from "A" to "Z"
	{   
        ch = ch - 0x41;

		for (i = 0; i < 5; i++)
		{
			StringBuffer[pos + i] = Letters[(ch * 5) + i];
		}
		StringBuffer[pos + 6] = 0x00;
	}
}
*/
/*
 

void PrintCharFrameBuffer( unsigned char ch )
{
    unsigned char i = 0;

	if (ch == ' ')				 					// Print Space char
	{
		for (i = 0; i < 6; i++)
		{
			FrameBuffer[i] = 0x00;
		}
	}
    else if ((ch > 0x40) && (ch < 0x5B))	 				// Print Uppercase from "A" to "Z"
	{   
        ch = ch - 0x41;

		for (i = 0; i < 5; i++)
		{
			FrameBuffer[i] = Letters[(ch * 5) + i];
		}

		FrameBuffer[i] = 0x00;
	}
}

 */