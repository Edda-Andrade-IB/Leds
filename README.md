Este proyecto tiene por intención demostrar el desarrollo de un driver de 16 leds representados como un int16 basado en tests, utilizando el framework Ceedling.

El driver debe cumplir con los siguientes requerimientos:
<ul>
    <li>Con la inicialización todos los LEDs quedan apagados.</li>
    <li>Prender un LED individual.</li>
    <li>Apagar un LED individual.</li>
    <li>Prender y apagar múltiples LED’s.</li>
    <li>Prender todos los LEDs de una vez.</li>
    <li>Apagar todos los LEDs de una vez.</li>
    <li>Consultar el estado de un LED que está encendido.</li>
    <li>Consultar el estado de un LED que está apagado.</li>
    <li>Revisar límites de los parámetros.</li>
    <li>Revisar parámetros fuera de los límites.</li>
</ul>


## Uso del Repositorio

Este repositorio utiliza las siguientes herramientas:

- [clang-format]() para el mantenimiento del formato del código escrito en lenguaje C.
- [pre-commit](https://pre-commit.com/) para validaciones generales de formato del repositorio.
- [ceedling](http://www.throwtheswitch.org/ceedling) para ejecutar las pruebas unitarias en forma automatizada.
- [lcov](http://ltp.sourceforge.net/coverage/lcov.php) para generar los informes de cobertura de las pruebas unitarias.

Después de clonar el repositorio, usted debería ejecutar el siguiente comando:

```sh
pre-commit install
```

Para ejecutar las pruebas unitarias, se utiliza el siguiente comando:

```sh
ceedling test:all
```

Para generar el informe de cobertura de las pruebas, se utiliza el siguiente comando:

```sh
ceedling clobber gcov:all utils:gcov
```

Para generar la documentación del proyecto, se utiliza el siguiente comando:

```sh
make doc
```

Para compilar el proyecto, se utiliza el siguiente comando:

```sh
make all
```



p/d: despues de esta experiencia la superioridad de Linux para el uso de software libre quedo ampliamente demostrada
