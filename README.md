# Party Screen Lights

Consiste en una matriz 8x8 de neopixeles, capaces de cambiar de patrón de iluminación con o sin influencia de señales de audio. 

Posee tres botones:
* [ON/OFF] - Permite encender y apagar la pantalla.
* [MODE] - Permite seleccionar el patrón de iluminación, con cada pulsada se va cambiando el modo de operación.
* [AUDIO] - Permite activar el microfono para que la señal de audio influya en el patrón de iluminación

Posee cuatro LED indicadores:
* [ON/OFF] - Para indicar cuando está encendido o apagado la pantalla. (Útil para la simulación)
* [AUDIO] - Para indicar cuando está encendido el micrófono y se está operando con señales de audio.
* [TEMPERATURA] - Para indicar cuando la matriz excede la temperatura máxima de operación.
* [ACTIVIDAD] - Para observar la dinámica de la señal de audio. (Útil para la simulación) 

Posee memoria persistente, esto permite retomar el patrón de iluminación que estaba corriendo antes de una falla de la red eléctrica.


## Tabla de Contenidos

1. **[About the Project](#party-screen-lights)**
2. **[Hardware](#hardware)**
3. **[Software](#software)**
4. **[Simulación](#simulación)**
5. **[Prerequisitos](#prerequisitos)**

 
## Hardware
El hardware utilizado son los siguientes:

* **[PIC16f1717]**
* **[FALTA SENSOR DE TEMP]**
* **[FALTA EEPROM EXTERNA]** 

## Software
El software se desarrolló en MPLAB, se utilizan los siguientes periféricos:

* **[GPIOS/IN]** - Para censar el estado de los 3 botones
* **[GPIOS/OUT]** - Para encender los 4 LED indicadores
* **[UART]** - Para transmitir la señal de debugging en la fábrica
* **[ADC]** - Para muestrear la señal de audio del microfono
* **[ADC]** - Para muestrear la temperatura en la termocupla.
*  FALTA EXPLICAR LOS NEOPIXELES y LA MEMORIA ROM

El diagrama de software de desiciones (macro) que toma el programa durante su funcionamiento se puede observar a continuación:

![alt text](https://github.com/CarSanoja/party-screen-lights/blob/development/imagenes/diagrama_software.png?raw=true)

## Simulación

### Prerequisitos


* **[Proteus v8]** - Se necesita el software Proteus en su version 8.
* **[.hex]** - Cada vez que se inicia Proteus, se pierde la ruta del archivo que contiene la configuración del PIC. Este debe ser recuperado, dándole doble click al PIC, y buscando en el campo Program File la ruta:

```
..\mplab\party_light_screen\dist\default\production\party_light_screen.production.hex
```
 
* **[Archivo de audio]** - Cada vez que se inicia Proteus, se pierde la ruta del archivo de audio. Este debe ser recuperado dando doble click al ícono de señal de audio, dándole click al botón _Browse_ y poner la ruta:

```
proteus\Pedazo_Omen.wav
```
## Pruebas
En esta sección se muestran todas las funcionalidades implementadas.

La siguiente imagen muestra el proyecto completo de Proteus.
![alt text](https://github.com/CarSanoja/party-screen-lights/blob/development/imagenes/proteus_project.png?raw=true)

Básicamente consta de 5 grandes partes:

- El Speaker con el terminal del ADC del Microcontrolador. 
- Los 3 botones de control del producto (encendido, cambio de modos y audio).
- El grupo de leds indicadores. 
- La matriz de neopixeles.
- El microcontrolador PIC16F1717

Antes de inciar la simualción se deben seguir las indicaciones de la sección [Prerequisitos](#prerequisites).

Luego de iniciar la simulación en Proteus se deberá hacer clic en el botón **BUT_ON_OFF** para encender el equipo, podrá observar que la luz indicadora **LED_ON_OFF** se enciende.

## Autores

* **[Carlos Sanoja](https://github.com/CarSanoja)**
* **[Jesús Guillen](https://github.com/JG-Guillen)**
* **[Leonardo Ward](https://github.com/leonardoward)**
* **[Mauricio Marcano](https://github.com/rinripper)**
* **[Oscar Moreno](https://github.com/OscarEMoreno)**
* **[Vincenzo D’Argento](https://github.com/vincdargento)**

## Licencia

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

