/*
 * File:   manager_audio.c
 * Author: mauro
 *
 * Created on April 6, 2021, 8:46 PM
 */

#include "manager_audio.h"
#include <xc.h>



void audio_init(void){
    ADC_Initialize();
}

uint8_t audio_get(void){
    
   adc_result_t sample;
   
   sample = ADC_GetConversion(ADC_AUDIO);
 
   sample /=4; 
   
   return (uint8_t)sample;
}

