/*
 * File:   manager_pixel.c
 * Author: mauro
 *
 * Created on April 7, 2021, 2:58 PM
 */


#include <xc.h>
#include "manager_pixel.h"

void pixel_init(void) {
    //Funcion para inicializar los pixeles
}

void pixel_set(uint32_t program_count, uint8_t mode, uint8_t flag_audio, uint8_t audio_signal) {
    //Funcion para setear los pixeles seg�n el counter del programa, el modo y si hay audio o no
    
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