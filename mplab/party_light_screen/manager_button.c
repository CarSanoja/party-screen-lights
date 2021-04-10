/*
 * File:   manager_button.c
 * Author: mauro
 *
 * Created on April 6, 2021, 6:26 PM
 */

#include "manager_button.h"
#include <xc.h>


void buts_init(void){
    PIN_MANAGER_Initialize();
}

bool buts_get(void){
    // variables receptoras del status de los botones
    uint24_t flag_on_off,flag_mode,flag_audio;
    
    //varible para guardar si un estatus cambío, para avisar que algo cambió
    // por defecto empieza en 0, si hay algun cambio se le pone uno
    bool flag_change = 0;
            
    flag_on_off = BUT_ON_OFF_GetValue();
    flag_mode   = BUT_MODE_GetValue();
    flag_audio  = BUT_AUDIO_GetValue();
    
    //si alguno de los botones es precionado, se entra en el if y se modifica flag_change
    if(flag_on_off + flag_mode + flag_audio >= 1){
        flag_change++;
    }
    
    if(flag_on_off){
        but_on_off++;
        but_on_off %= 2; //con la operación modulo el estado del boton solo puede ser 0 o 1, apagado o prendido
    }
    
    if(flag_mode){
        
        but_mode++;
        but_mode %= MODE_MAX; //con la operación modulo el estado del boton solo puede ir de 0 a MODE_MAX, de forma ciclica
    }
    if(flag_audio){
        
        but_audio++; 
        but_audio %= 2; //con la operación modulo el estado del boton solo puede ser 0 o 1, apagado o prendido
        if(but_audio){
            LED_AUDIO_SetHigh(); // enciende el led de audio_mode 
        }else{
            LED_AUDIO_SetLow(); // apaga el led de audio_mode
        }
    }
    return flag_change;
}
