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

## Hardware

## Software

El diagrama de software macro se puede observar a continuación:

![alt text](https://github.com/[username]/[reponame]/blob/[branch]/image.jpg?raw=true)



### Prerequisites

What things you need to install the software and how to install them

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

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc
