/*
 * File:   manager_debug.c
 * Author: mauro
 *
 * Created on April 7, 2021, 3:35 PM
 */


#include <xc.h>
#include "manager_debug.h"

//Function to send one byte of date to UART
void UART_send_char(char bt)  
{
    while(!TXIF);  // hold the program till TX buffer is free
    TXREG = bt; //Load the transmitter buffer with the received value
}

//Function to convert string to byte
void UART_send_string(char* st_pt)
{
    while(*st_pt) //if there is a char
        UART_send_char(*st_pt++); //process it as a byte data
}

void debug_init(void) {
    //inicialización del usart
    EUSART_Initialize();
    
    UART_send_string("Inicializando el sistema...\n");
}

void debug_get(uint8_t status_on_off,uint8_t status_mode, uint8_t status_audio){
    
    char auxString[20] = "";
    
    //imprimir los status de los botones
    sprintf(auxString, "Status ON/OFF: %d\n\r", status_on_off);
    UART_send_string(auxString);
    
    sprintf(auxString, "Status Mode: %d\n\r", status_mode);
    UART_send_string(auxString);
    
    sprintf(auxString, "Status Audio: %d\n\r", status_audio);
    UART_send_string(auxString);
};
