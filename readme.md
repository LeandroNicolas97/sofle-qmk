# Compilar sofle:

Para compilar el firmware personalizado para tu teclado Sofle, se debe ejecutar el siguiente comando dentro del directorio de QMK

**cd ~/qmk_firmware**



Compilar el keymap personalizado "si" para Sofle Rev1:

**qmk compile -kb sofle/rev1 -km si**



Este comando generará el archivo hexadecimal que posteriormente flashearemos en ambas mitades del teclado.


# Modo bootloader

Antes de flashear el firmware, se necesita poner el teclado en modo bootloader. Esto se puede hacer de dos maneras:

1-Método del botón físico: Localizar el botón de RESET en la PCB del teclado y presiónalo 2 veces rapidamente mientras esta conctada al pc.

2-Método de combinación de teclas: Si has configurado una combinación de teclas para entrar en modo bootloader en tu keymap, utiliza esa combinación.

El teclado entrará en modo bootloader, lo que permitirá que la computadora lo reconozca como un dispositivo programable.




# Flashear sofle:
Una vez que tu teclado esté en modo bootloader, se puede proceder a flashear el firmware:

**qmk flash -kb sofle/rev1 -km si -bl avrdude**




# Quantum Mechanical Keyboard Firmware



[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/qmk)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the Clueboard product line.

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [VitePress](https://vitepress.dev/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls).

## Supported Keyboards

* [Planck](/keyboards/planck/)
* [Preonic](/keyboards/preonic/)
* [ErgoDox EZ](/keyboards/ergodox_ez/)
* [Clueboard](/keyboards/clueboard/)
* [Cluepad](/keyboards/clueboard/17/)
* [Atreus](/keyboards/atreus/)

The project also includes community support for [lots of other keyboards](/keyboards/).

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
