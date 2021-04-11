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

void clear(){
    for(int i = 0; i < NUM_PIXELS; i++) {
        write_pixel(0,0,0);  // Black  
    }
}

void pixel_init(void) {
    //Funcion para inicializar los pixeles
    // Clear all the pixels
    //clear();
    ShowColor(COLOR_RED);
    //ShowRainbowScan();
    //ShowColor(COLOR_BLACK);
    __delay_ms(1000);
    PrintText("PARTY");
}

void ShowColor( unsigned char r, unsigned char g, unsigned char b )
{
    for(unsigned char i = 0; i < NUM_PIXELS; i++)
    {
        write_pixel(r, g, b);
    }
}



void pixel_set(uint32_t program_count, uint8_t mode, uint8_t flag_audio, uint8_t audio_signal) {
    //Funcion para setear los pixeles según el counter del programa, el modo y si hay audio o no
    
    //Selecciona el modo, dependiendo del estado del boton de modo (mode)
    switch(mode){
        case MODE_0: //Strobe lento
            if(flag_audio == 0){
                //si no hay musica hacer rutina con program_counter
            }else{
                //si hay musica hacer rutina con audio_signal
            }
        break;

        case MODE_1:  //Stobe rapido
            if(flag_audio == 0){
                //si no hay musica hacer rutina con program_counter
            }else{
                //si hay musica hacer rutina con audio_signal
            }
        break;

        case MODE_2: //Latigo desde el principio
            if(flag_audio == 0){
                //si no hay musica hacer rutina con program_counter
            }else{
                //si hay musica hacer rutina con audio_signal
            }            
        break;

        case MODE_3: //Latigo desde el final
            if(flag_audio == 0){
                //si no hay musica hacer rutina con program_counter
            }else{
                //si hay musica hacer rutina con audio_signal
            }            
        break;
        
        case MODE_OFF: //Apagado
            //apagado
        break;
        
        default:
        break;

    }
}

void PrintText( unsigned char *Text )
{
    unsigned int cnt = 0;
    while (Text[cnt] != 0)
    {
        PrintCharStringBuffer(Text[cnt], cnt * 6);
        cnt++;
    }
}

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
