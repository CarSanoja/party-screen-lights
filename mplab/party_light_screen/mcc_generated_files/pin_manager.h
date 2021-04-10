/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1717
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set ADC_AUDIO aliases
#define ADC_AUDIO_TRIS                 TRISAbits.TRISA0
#define ADC_AUDIO_LAT                  LATAbits.LATA0
#define ADC_AUDIO_PORT                 PORTAbits.RA0
#define ADC_AUDIO_WPU                  WPUAbits.WPUA0
#define ADC_AUDIO_OD                   ODCONAbits.ODA0
#define ADC_AUDIO_ANS                  ANSELAbits.ANSA0
#define ADC_AUDIO_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define ADC_AUDIO_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define ADC_AUDIO_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define ADC_AUDIO_GetValue()           PORTAbits.RA0
#define ADC_AUDIO_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define ADC_AUDIO_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define ADC_AUDIO_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define ADC_AUDIO_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define ADC_AUDIO_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define ADC_AUDIO_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define ADC_AUDIO_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define ADC_AUDIO_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set BUT_ON_OFF aliases
#define BUT_ON_OFF_TRIS                 TRISBbits.TRISB0
#define BUT_ON_OFF_LAT                  LATBbits.LATB0
#define BUT_ON_OFF_PORT                 PORTBbits.RB0
#define BUT_ON_OFF_WPU                  WPUBbits.WPUB0
#define BUT_ON_OFF_OD                   ODCONBbits.ODB0
#define BUT_ON_OFF_ANS                  ANSELBbits.ANSB0
#define BUT_ON_OFF_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define BUT_ON_OFF_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define BUT_ON_OFF_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define BUT_ON_OFF_GetValue()           PORTBbits.RB0
#define BUT_ON_OFF_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define BUT_ON_OFF_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define BUT_ON_OFF_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define BUT_ON_OFF_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define BUT_ON_OFF_SetPushPull()        do { ODCONBbits.ODB0 = 0; } while(0)
#define BUT_ON_OFF_SetOpenDrain()       do { ODCONBbits.ODB0 = 1; } while(0)
#define BUT_ON_OFF_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define BUT_ON_OFF_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set BUT_MODE aliases
#define BUT_MODE_TRIS                 TRISBbits.TRISB1
#define BUT_MODE_LAT                  LATBbits.LATB1
#define BUT_MODE_PORT                 PORTBbits.RB1
#define BUT_MODE_WPU                  WPUBbits.WPUB1
#define BUT_MODE_OD                   ODCONBbits.ODB1
#define BUT_MODE_ANS                  ANSELBbits.ANSB1
#define BUT_MODE_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define BUT_MODE_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define BUT_MODE_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define BUT_MODE_GetValue()           PORTBbits.RB1
#define BUT_MODE_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define BUT_MODE_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define BUT_MODE_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define BUT_MODE_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define BUT_MODE_SetPushPull()        do { ODCONBbits.ODB1 = 0; } while(0)
#define BUT_MODE_SetOpenDrain()       do { ODCONBbits.ODB1 = 1; } while(0)
#define BUT_MODE_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define BUT_MODE_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set BUT_AUDIO aliases
#define BUT_AUDIO_TRIS                 TRISBbits.TRISB2
#define BUT_AUDIO_LAT                  LATBbits.LATB2
#define BUT_AUDIO_PORT                 PORTBbits.RB2
#define BUT_AUDIO_WPU                  WPUBbits.WPUB2
#define BUT_AUDIO_OD                   ODCONBbits.ODB2
#define BUT_AUDIO_ANS                  ANSELBbits.ANSB2
#define BUT_AUDIO_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define BUT_AUDIO_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define BUT_AUDIO_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define BUT_AUDIO_GetValue()           PORTBbits.RB2
#define BUT_AUDIO_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define BUT_AUDIO_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define BUT_AUDIO_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define BUT_AUDIO_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define BUT_AUDIO_SetPushPull()        do { ODCONBbits.ODB2 = 0; } while(0)
#define BUT_AUDIO_SetOpenDrain()       do { ODCONBbits.ODB2 = 1; } while(0)
#define BUT_AUDIO_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define BUT_AUDIO_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set LED_TEMPETURE aliases
#define LED_TEMPETURE_TRIS                 TRISBbits.TRISB3
#define LED_TEMPETURE_LAT                  LATBbits.LATB3
#define LED_TEMPETURE_PORT                 PORTBbits.RB3
#define LED_TEMPETURE_WPU                  WPUBbits.WPUB3
#define LED_TEMPETURE_OD                   ODCONBbits.ODB3
#define LED_TEMPETURE_ANS                  ANSELBbits.ANSB3
#define LED_TEMPETURE_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define LED_TEMPETURE_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define LED_TEMPETURE_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define LED_TEMPETURE_GetValue()           PORTBbits.RB3
#define LED_TEMPETURE_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define LED_TEMPETURE_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define LED_TEMPETURE_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define LED_TEMPETURE_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define LED_TEMPETURE_SetPushPull()        do { ODCONBbits.ODB3 = 0; } while(0)
#define LED_TEMPETURE_SetOpenDrain()       do { ODCONBbits.ODB3 = 1; } while(0)
#define LED_TEMPETURE_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define LED_TEMPETURE_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set LED_AUDIO aliases
#define LED_AUDIO_TRIS                 TRISBbits.TRISB4
#define LED_AUDIO_LAT                  LATBbits.LATB4
#define LED_AUDIO_PORT                 PORTBbits.RB4
#define LED_AUDIO_WPU                  WPUBbits.WPUB4
#define LED_AUDIO_OD                   ODCONBbits.ODB4
#define LED_AUDIO_ANS                  ANSELBbits.ANSB4
#define LED_AUDIO_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define LED_AUDIO_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define LED_AUDIO_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define LED_AUDIO_GetValue()           PORTBbits.RB4
#define LED_AUDIO_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define LED_AUDIO_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define LED_AUDIO_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define LED_AUDIO_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define LED_AUDIO_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define LED_AUDIO_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define LED_AUDIO_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define LED_AUDIO_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set LED_ON_OFF aliases
#define LED_ON_OFF_TRIS                 TRISBbits.TRISB5
#define LED_ON_OFF_LAT                  LATBbits.LATB5
#define LED_ON_OFF_PORT                 PORTBbits.RB5
#define LED_ON_OFF_WPU                  WPUBbits.WPUB5
#define LED_ON_OFF_OD                   ODCONBbits.ODB5
#define LED_ON_OFF_ANS                  ANSELBbits.ANSB5
#define LED_ON_OFF_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define LED_ON_OFF_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define LED_ON_OFF_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define LED_ON_OFF_GetValue()           PORTBbits.RB5
#define LED_ON_OFF_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define LED_ON_OFF_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define LED_ON_OFF_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define LED_ON_OFF_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define LED_ON_OFF_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define LED_ON_OFF_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define LED_ON_OFF_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define LED_ON_OFF_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/