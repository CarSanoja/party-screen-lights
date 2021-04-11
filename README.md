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
        1.**[Prerequisitos](#prerequisites)**

 
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
* **[.hex]** - Cada vez que se inicia Proteus, se pierde la ruta del archivo que contiene la configuración del PIC. Este debe ser recuperado, dandole doble click al PIC, y buscando en el campo Program File la ruta: "..\mplab\party_light_screen\dist\default\production\party_light_screen.production.hex"
* **[Archivo de audio]** - Cada vez que se inicia Proteus, se pierde la ruta del archivo de audio. Este debe ser recuperado dando doble click al icono de señal de audio, dandolé clicl al boton Browse y poner la ruta "...\Pedazo_Omen.wav"

```
Give examples
```

### Installing

A step by step series of examples that tell you how to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **[Carlos Sanoja](https://github.com/CarSanoja)**
* **[Jesús Guillen](https://github.com/JG-Guillen)**
* **[Leonardo Ward](https://github.com/leonardoward)**
* **[Mauricio Marcano](https://github.com/rinripper)**
* **[Oscar Moreno](https://github.com/OscarEMoreno)**
* **[Vincenzo D’Argento](https://github.com/vincdargento)**

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc
