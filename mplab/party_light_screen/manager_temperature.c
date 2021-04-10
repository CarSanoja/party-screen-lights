/*
 * File:   manager_temperature.c
 * Author: mauro
 *
 * Created on April 7, 2021, 1:53 PM
 */

#include "manager_temperature.h"
#include <xc.h>

int temperature_init(void){
    ADC_Initialize();
    
    // se pone esta bandera en 1 para empezar habilitado
    temperature_enable_flag = 1;
    return 0;
}

bool temperature_get(void){
    
   adc_result_t sample;
   bool result;
   
   sample = ADC_GetConversion(4);
 
   //Si temperature_enable_flag está encendida, está operando normalmente 
   if(temperature_enable_flag){
       // Si la temperatura pasa de TEMPERATURE_MAX entonces manda deshabilitar las operaciones
       if(sample >= TEMPERATURE_MAX){ 
           result = 0;
           //LED_TEMPETURE_SetHigh();
           
       }
       else{ 
           result = 1;
           //LED_TEMPETURE_SetLow();
       }
   }else{ // si temperature_enable_flag es cero, quiere decir que esta sobrecalentado
       // Entonces antes de restaurar las operaciones hay que esperar que la 
       // temperatura baje a un rango especifico antes de habilitar las operaciones
       if(sample > (TEMPERATURE_MIN + 10) || sample < (TEMPERATURE_MIN) ){ 
           result = 1;
           //LED_TEMPETURE_SetLow();
            
       }
       else{ 
           result = 0;
           //LED_TEMPETURE_SetHigh();   
       }
   
   }
   
   return result;
}

