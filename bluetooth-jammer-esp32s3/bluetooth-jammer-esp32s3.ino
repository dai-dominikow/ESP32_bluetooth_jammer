#include <SPI.h>
#include <RF24.h>

#define CE_PIN  9
#define CSN_PIN 10
#define SPI_SCK 12
#define SPI_MISO 13
#define SPI_MOSI 11

// Crear el objeto SPI y el objeto RF24
SPIClass vspi;
RF24 radio(CE_PIN, CSN_PIN); 

// Variables del programa
byte i = 45, ptr_hop = 0, flag = 0;
byte hopping_channel[] = {32, 34, 46, 48, 50, 52, 0, 1, 2, 4, 6, 8, 22, 24, 26, 28, 30, 74, 76, 78, 80, 82, 84, 86};

void nrfSPIInit() {
    // Inicializa la clase SPI con los pines personalizados
    vspi.begin(SPI_SCK, SPI_MISO, SPI_MOSI, CSN_PIN);
    
    if (radio.begin(&vspi)) { // Pasa el objeto vspi a la radio
        radio.setAutoAck(false);
        radio.stopListening();
        radio.setRetries(0, 0);
        radio.setPayloadSize(31);
        radio.setAddressWidth(4);
        radio.setPALevel(RF24_PA_MAX, true);
        radio.setDataRate(RF24_2MBPS);
        radio.setCRCLength(RF24_CRC_DISABLED);
        radio.startConstCarrier(RF24_PA_MAX, i);
    }
}

void adjustAndSweepChannels() {
    flag = (i > 79) ? 1 : (i < 2 ? 0 : flag);
    i += flag ? -2 : 2;
    for (int j = 0; j <= 79; j++) radio.setChannel(j);
}

void setup() {
    nrfSPIInit();
}

void loop() {
    adjustAndSweepChannels();
    ptr_hop = (ptr_hop + 1) % sizeof(hopping_channel);
    radio.setChannel(hopping_channel[ptr_hop]);
}
