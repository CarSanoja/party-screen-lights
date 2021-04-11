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
    //ShowColor(COLOR_BLUE);
    ShowRainbowScan();
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

void ShowRainbowScan( void )
{
    unsigned int i;
    
    i = 0;
    while(i < NUM_PIXELS)
    {
        SPI_WriteBlock(Wheel[i], PACKETCOUNT);
        i = i + 3;
        __delay_ms(50);
    }
}
