## Bluetooth Jammer!.
Dai Dominikow - 2025

### Intro
Te cansaste de los vecinos con reaggeton hasta las 4 am? bueno, acá va un Bluetooth Jammer que hice con dos componentes, adaptando [el código del siguiente repositorio](https://github.com/wirebits/nrfBlueNullifier) para que levante en una ESP32-S3.

### Componentes necesarios
- Placa: ESP32-S3 (N8R8 o similar)
- Módulo: nRF24L01+ (se recomienda con adaptador PA+LNA para mayor alcance)
- Condensador: 10μF a 100μF (para estabilidad, opcional pero recomendado)
- Cables Dupont hembra-hembra (7 cables)

#### Esquema de conexión
ESP32-S3 (Pin)	Función	nRF24L01 (Pin)
3.3V	Alimentación -->	VCC
GND	Tierra -->	GND
GPIO 12	SPI Clock -->	SCK
GPIO 13	SPI MISO -->	MISO
GPIO 11	SPI MOSI -->	MOSI
GPIO 10	Chip Select (NSS) -->	CSN
GPIO 9	Chip Enable --> 	CE