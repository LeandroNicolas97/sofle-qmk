# Sofle Keyboard - Custom Keymap

Mi configuración personalizada para el teclado Sofle v2.

## Características

- **Encoder Izquierdo**: Control de volumen (arriba/abajo)
- **Encoder Derecho**: Scroll (Page Up/Down)
- **RGB Underglow**: Habilitado con toggle en capa de ajustes
- **OLED**: Soporte habilitado
- **WPM Counter**: Contador de palabras por minuto
- **Tri-Layer**: Activación automática de capa 3 al presionar capas 1 y 2

## Requisitos

### Arch Linux / Manjaro
```bash
sudo pacman -S qmk git python-pip libusb avr-gcc avr-libc arm-none-eabi-gcc arm-none-eabi-newlib
```

### Ubuntu / Debian
```bash
sudo apt install qmk git python3-pip libusb-1.0-0-dev gcc-avr avr-libc gcc-arm-none-eabi libnewlib-arm-none-eabi
```

### macOS
```bash
brew install qmk/qmk/qmk
```

## Instalación

### 1. Clonar QMK Firmware
```bash
cd ~
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
qmk setup -y
```

### 2. Clonar este keymap
```bash
cd ~/qmk_firmware/keyboards/sofle/keymaps/
git clone git@github.com:LeandroNicolas97/sofle-qmk.git sofle
```

### 3. Compilar
```bash
cd ~/qmk_firmware
qmk compile -kb sofle -km sofle
```

## Flashear el teclado

### Método 1: Flash automático (recomendado)
```bash
cd ~/qmk_firmware
qmk flash -kb sofle -km sofle
```

Luego:
1. Cuando veas "Waiting for USB device...", presiona el botón RESET en tu teclado
2. El proceso de flash comenzará automáticamente
3. Repite para el otro lado del teclado

### Método 2: Flash manual con avrdude
```bash
cd ~/qmk_firmware

# Compilar
qmk compile -kb sofle -km sofle

# El archivo .hex estará en: sofle_rev1_sofle.hex

# Flashear (presiona RESET cuando esté listo)
avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:sofle_rev1_sofle.hex
```

### Método 3: QMK Toolbox (GUI)

1. Descargar [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases)
2. Abrir el archivo `sofle_rev1_sofle.hex`
3. Seleccionar MCU: `atmega32u4`
4. Presionar RESET en el teclado
5. Click en "Flash"

## Poner el teclado en modo Bootloader

Hay tres formas de entrar al modo bootloader:

1. **Botón RESET físico**: Presiona el botón RESET en la PCB
2. **Keycode RESET**: Presiona `QK_BOOT` (en capa 3: Fn + Esc)
3. **Bootmagic reset**: Mantén presionada la tecla superior izquierda mientras conectas el USB

## Permisos USB en Linux

Si tienes problemas de permisos, crea reglas udev:
```bash
sudo tee /etc/udev/rules.d/50-qmk.rules << 'RULES'
# ATmega32U4
SUBSYSTEMS=="usb", ATTRS{idVendor}=="03eb", ATTRS{idProduct}=="2ff4", TAG+="uaccess"
# ATmega32U2
SUBSYSTEMS=="usb", ATTRS{idVendor}=="03eb", ATTRS{idProduct}=="2ff0", TAG+="uaccess"
RULES

sudo udevadm control --reload-rules
sudo udevadm trigger
```

## Estructura de archivos
```
.
├── config.h      # Configuración del keymap
├── keymap.c      # Layout y funciones personalizadas
├── rules.mk      # Features habilitadas
└── README.md     # Este archivo
```

## Modificar el keymap

1. Editar `keymap.c` con tu editor favorito:
```bash
   nano keymap.c
```

2. Compilar y probar:
```bash
   cd ~/qmk_firmware
   qmk compile -kb sofle -km sofle
```

3. Si funciona bien, flashear:
```bash
   qmk flash -kb sofle -km sofle
```

4. Guardar cambios:
```bash
   cd ~/qmk_firmware/keyboards/sofle/keymaps/sofle
   git add .
   git commit -m "Descripción de cambios"
   git push origin main
```

## Recursos útiles

- [QMK Documentation](https://docs.qmk.fm/)
- [QMK Keycodes](https://docs.qmk.fm/#/keycodes)
- [Sofle Keyboard](https://josefadamcik.github.io/SofleKeyboard/)

## Solución de problemas

### Error: "avrdude: ser_open(): can't open device"
```bash
# Verificar puerto
ls /dev/ttyACM*

# Agregar usuario al grupo dialout
sudo usermod -aG dialout $USER
# Cerrar sesión e iniciar de nuevo
```

### Error: "Device not found"

- Verifica que el teclado esté en modo bootloader
- Prueba con otro cable USB
- Verifica las reglas udev

### El teclado no responde después del flash

- Desconecta y reconecta el USB
- Presiona RESET dos veces rápidamente
- Re-flashea el firmware

## Licencia

Este keymap está bajo la misma licencia que QMK Firmware (GPL v2).
