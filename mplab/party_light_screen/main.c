/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1509
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "manager_button.h"
#include "manager_audio.h"
#include "manager_memory.h"
#include "manager_temperature.h"
#include "manager_pixel.h"
#include "manager_debug.h"




/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
   
    //Inializa la memoria para guardar el estado del programa
    memory_init();
    bool flag_save_status;
    
    //Obtiene el estado de los botones guardados en memoria
    memory_get(&but_on_off,&but_mode,&but_audio);
    
    //Inicializa el ADC para la adquisicion de audio
    audio_init();
    
    //Variable para recibir el audio
    uint8_t audio_signal;

    //Inicializa los botones
    buts_init();
    
    //Inicializa el ADC para medir temperatura
    temperature_init();
    
    //Inicializa los pines de los pixeles
    pixel_init();
    
    //Inicializa el uart para el debug
    debug_init();
    
    //Contador de ciclos de programa para refrescar el programa
    uint32_t program_counter = 0;
    
    but_debouncer = program_counter;
    
    while (1)
    {
        LOG("hola aqui");
        //cada cierto tiempo manda el estado de los botones por el UART
        if(program_counter % (BUG_PROGRAM_COUNTER )== 0){
            debug_get(but_on_off,but_mode,but_audio);
        }
        
        //Cuando program_counter sea multiplo de TEMPERATURE_PC_COUNTER, entonces se realiza una medición de tempetura
        if(program_counter % (TEMPERATURE_PC_COUNTER )== 0){
            temperature_enable_flag = temperature_get();
        }
        
        //Si la temperatura es menor al máximo permitido entonces se le permite al programa operar normalmente, 
        // si no, se manda a pagar las luces para disminuir la temperatura
        // cuando se mida la temperatura de nuevo y este en el rango correcto vuelve a operar normalmente
        if(temperature_enable_flag){
        
            //Lee el estado de los botones y si hay algun cambio  
            //modifica las variables globales: but_on_off, but_mode, but_audio.
            //Si hubo algun cambio en el estado de los botones, manda un 1, si no hubo manda un 0
            if(but_debouncer < program_counter){
                flag_save_status = buts_get();
            }
            //Si hubo alguna modificación en los botones se activa la rutina de guardado de estado.
            if(flag_save_status){
                flag_save_status = 0;
                memory_set(but_on_off,but_mode,but_audio);
                but_debouncer = program_counter + BUT_DELAY;
                LED_TEMPETURE_Toggle();
            }
            
            // Si el estado de boton on_off es 1 (encendido) entonces permite la operacion normal, si no manda a apagar las luces
            if(but_on_off){

                // Pregunta si la función de audio está encendido,
                // para leer el adc del microfono
                if(but_audio){
                    audio_signal = (uint8_t) audio_get();
                    LED_AUDIO_SetHigh(); // enciende el led de audio_mode
                }else{
                    LED_AUDIO_SetLow(); // apaga el led de audio_mode
                }

                //Selecciona el modo de los pixeles dependiendo del estado del boton de modo (but_mode)
                 pixel_set(program_counter, but_mode, but_audio,audio_signal);

            
            }else{
                // Se setea los led en modo apagado
                pixel_set(program_counter, MODE_OFF, but_audio,audio_signal);
            }
     
        }else{
            // Se setea los led en modo apagado
            pixel_set(program_counter, MODE_OFF, but_audio,audio_signal);
        }
        
        //Despues de un ciclo se le suma uno al counter
        program_counter++;
    }
}
/**
 End of File
*/