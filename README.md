# Party Screen Lights

Consiste en una matriz 8x8 de neopixeles capaces de cambiar de patron de iluminación con o sin influencia de señales de audio. 

Posee tres botones:
* [ON/OFF] - Permite encender y apagar la pantalla.
* [MODE] - Permite seleccionar el patrón de iluminación, con cada pulsada se va cambiando el modo de operación.
* [AUDIO] - Permite activar el microfono para que la señal de audio influya en el patrón de iluminación

Posee cuatro LED indicadores:
* [ON/OFF] - Para indicar cuando está encendido o apagado la pantalla. (Util para la simulación)
* [AUDIO] - Para indicar cuando está encendido el microfono y se está operando con señales de audio.
* [TEMPERATURA] - Para indicar cuando la matriz excede la temperatura máxima de operación.
* [ACTIVIDAD] - Para observar la dinámica de la señal de audio. (Util para la simulación) 

Posee memoria persistente, esto permite retomar el patrón de iluminación que estaba corriendo antes de una falla de la red electrica.


## Table of Contents

1. **[About the Project](#party-screen-lights)**
2. **[Hardware](#hardware)**
3. **[Software](#software)**
4. **[Simulación](#simulación)**
5. **[Prerequisitos](#prerequisites)**

 
## Hardware
El hardware utilizado son los siguientes:

* **[PIC16f1717]**
* **[FALTA SENSOR DE TEMP]**
* **[FALTA EEPROM EXTERNA]** 

## Software
El software se desarrolló en MPLAB, se utilizan los siguientes perifericos:

* **[GPIOS/IN]** - Para censar el estado de los 3 botones
* **[GPIOS/OUT]** - Para encender los 4 LED indicadores
* **[UART]** - Para transmitir la señal de debugging en la fábrica
* **[ADC]** - Para muestrear la señal de audio del microfono
* **[ADC]** - Para muestrear la temperatura en la termocupla.
*  FALTA EXPLICAR LOS NEOPIXELES y LA MEMORIA ROM

El diagrama de software de desiciones (macro) que toma el programa durante su funcionamiento se puede observar a continuación:

![alt text](https://github.com/CarSanoja/party-screen-lights/blob/development/imagenes/diagrama_software.png?raw=true)

## Simulación

### Prerequisites


* **[Proteus v8]** - Se necesita el software Proteus en su version 8.
* **[.hex]** - Cada vez que se inicia Proteus, se pierde la ruta del archivo que contiene la configuración del PIC. Este debe ser recuperado, dandole doble click al PIC, y buscando en el campo Program File la ruta:

```
..\mplab\party_light_screen\dist\default\production\party_light_screen.production.hex
```
 
* **[Archivo de audio]** - Cada vez que se inicia Proteus, se pierde la ruta del archivo de audio. Este debe ser recuperado dando doble click al icono de señal de audio, dandolé clicl al boton Browse y poner la ruta:

```
"proteus\Pedazo_Omen.wav"
```


## Authors

* **[Carlos Sanoja](https://github.com/CarSanoja)**
* **[Jesús Guillen](https://github.com/JG-Guillen)**
* **[Leonardo Ward](https://github.com/leonardoward)**
* **[Mauricio Marcano](https://github.com/rinripper)**
* **[Oscar Moreno](https://github.com/OscarEMoreno)**
* **[Vincenzo D’Argento](https://github.com/vincdargento)**

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

