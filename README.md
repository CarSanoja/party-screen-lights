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
El hardware utilizado incluye:

* **[PIC16f1717]**
* **[LM45]**
* **[WS2812 8X1]**

## Software
El software se desarrolló en MPLABX, se utilizan los siguientes periféricos:

* **[GPIOS/IN]** - Para censar el estado de los 3 botones
* **[GPIOS/OUT]** - Para encender los 4 LED indicadores
* **[UART]** - Para transmitir la señal de debugging en la fábrica
* **[ADC]** - Para muestrear la señal de audio del microfono
* **[ADC]** - Para muestrear la temperatura en la termocupla.
* **[TIMER2][PWM4][CLC3][MSSP]** - Para configurar la señal de los WS2812. El proyecto implementa las ideas de la Nota de aplicación [AN1606](http://ww1.microchip.com/downloads/en/appnotes/00001606a.pdf) para crear la señal. Para una explicación más detallada sobre la implementación visitar la Nota de Aplicación [AN1606](http://ww1.microchip.com/downloads/en/appnotes/00001606a.pdf), el artículo [Interfacing with WS2812 Neopixel LED Arrays](https://mplabxpress.microchip.com/mplabcloud/example/details/503) y el repositorio de Github [PIC16F1717 WS2812 Proteus](https://github.com/leonardoward/pic16-ws2812-proteus) que muestra una implementación en el PIC16F1717.


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

La siguiente imágen muestra el proyecto completo de Proteus.
![alt text](https://github.com/CarSanoja/party-screen-lights/blob/development/imagenes/proteus_project.jpg?raw=true)

Básicamente consta de 5 grandes partes:

- El Speaker, conectado a un ADC del Microcontrolador.
- EL sensor de temperatura, conectado a un ADC del Microcontrolador.
- Los 3 botones de control del producto (encendido, cambio de modos y audio).
- El grupo de leds indicadores.
- La matriz de neopixeles.
- El microcontrolador PIC16F1717.
- Terminal para debug.


Antes de inciar la simualción se deben seguir las indicaciones de la sección [Prerequisitos](#prerequisites).

Luego de iniciar la simulación en Proteus se deberá hacer clic en el botón **BUT_ON_OFF** para encender el equipo, podrá observar que la luz indicadora **LED_ON_OFF** se enciende (deberpa esperar al menos 2 segundos antes de hacer clic en alguno de los otros 2 botones).

 Al iniciar la simulación se activará al terminal virtual con el que podrá observar el estatus de encendido del equipo, el modo de operación y si está funcionando controlado por una señal de audio.

 El equipo tiene dos grandes tipos de operación: Controlado por audio y sin audio. En cada uno de estos tipos de operación vamos a encontrar a su vez 4 modos de operación.
 Para alternar entre estas dos modalidades simplemente hay que hacer clic en el botón BUT_AUDIO y se encenderá o apagará el led LED_AUDIO  según sea el caso.

 ### Sin audio:
Aquí el led LED_AUDIO se encuentra apagado.
Podrá hacer uso del botón BUT_MODE para alternar entre los siguientes modos:

- Modo 0: Matriz en color cyan.
- Modo 1: Matriz en color verde claro.
- Modo 2: Matriz en color amarillo.
- Modo 3: Matriz en color magenta.

[Ver video](https://github.com/CarSanoja/party-screen-lights/blob/development/imagenes/modos_sin_audio.mkv)
### Controlado por audio:
Aquí el led LED_AUDIO se encuentra encendido.
Para probar al Speaker podrá hacer uso del potenciometro conectado en su extremo izquiedo, con el que podrá ajustar el volúmen.

El led LED_ACTIVITY se encenderá cuando la señal del ADC de audio alcance el 50% de su valor máximo.
Podrá hacer uso del botón BUT_MODE para alternar entre los siguientes modos:

- Modo 0: Barra de colores que inicia en el borde izquierdo, el ancho de la barra de colores depende de la amplitud de la señal analógica.
- Modo 1: El color en la matriz parpadea lentamente. El color depende de la amplitud de la señal analógica.
- Modo 2: Barra de colores que inicia en el borde izquierdo, el ancho de la barra de colores depende de la amplitud de la señal analógica. Usa diferentes transiciones de color a las del modo 0.
- Modo 3: El color en la matriz parpadea rápido. El color depende de la amplitud de la señal analógica.

[Ver video](https://github.com/CarSanoja/party-screen-lights/blob/development/imagenes/modos_con_audio.mkv)

### Sensor de temperatura:
Para probar el sensor de temperatura, podrá hacer uso de los controles que el propio sensor incluye, que le permitirán ajustar la temperatura al valor desado. Podrá observar que al alcanzar los 65° se encenderá el led LED_TEMP y se apagará la matriz. Si luego empieza a disminuir la temperatura, al aproximarse a los 53° se apagará LED_TEMP y la matriz se encenderá nuevamente.
## Authors

* **[Carlos Sanoja](https://github.com/CarSanoja)**
* **[Jesús Guillen](https://github.com/JG-Guillen)**
* **[Leonardo Ward](https://github.com/leonardoward)**
* **[Mauricio Marcano](https://github.com/rinripper)**
* **[Oscar Moreno](https://github.com/OscarEMoreno)**
* **[Vincenzo D’Argento](https://github.com/vincdargento)**

## Licencia

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
