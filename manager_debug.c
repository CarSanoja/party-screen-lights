/*
 * File:   manager_debug.c
 * Author: mauro
 *
 * Created on April 7, 2021, 3:35 PM
 */


#include <xc.h>
#include "manager_debug.h"

void debug_init() {
    //inicialización del usart
    EUSART_Initialize();
}

void debug_get(uint8_t status_on_off,uint8_t status_mode,uint8_t status_audio){
    
    //imprimir los status de los botones
};
