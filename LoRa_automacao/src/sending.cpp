#include <Arduino.h>
#include <RadioLib.h>
#include <string.h>
#define BUFFER_SIZE 200 // Define o tamanho máximo do pacote a ser transmitido
// Configuração dos pinos para o módulo LoRa SX1262
SX1262 radio = new Module(8, 14, 12, 13); // CS, DIO1,RESET, BUSY

char txPacket[] = "meu nome e camille";

// Buffer para armazenar a mensagem a ser transmitida
void setup() {
  Serial.begin(115200); // Inicializa a comunicação serial
  Serial.println(F("Inicializando sistema..."));
  // Inicializa o módulo LoRa com as configurações padrão
  int state = radio.begin();
  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("Módulo LoRa inicializado com sucesso!"));
  } else {
    Serial.print(F("Falha na inicialização do LoRa, código de erro: "));
    Serial.println(state);
    while (true); // Trava o sistema em caso de falha
  };
}
void loop() {
  // if (Serial.available()) { // Verifica se há dados disponíveis na porta serial
    // int len = Serial.readBytes(txPacket, BUFFER_SIZE); //Lê os dados da serial para o buffer
    int len2 = sizeof(txPacket)/sizeof(txPacket[0]);
    // Serial.println(len2);
    txPacket[len2] = '\0';
    // Serial.println(txPacket);
    Serial.print(F("Enviando: "));
    Serial.println(txPacket); // Envia a mensagem via LoRa
    int transmissionState = radio.startTransmit(txPacket);
    if (transmissionState == RADIOLIB_ERR_NONE) {
        Serial.println(F("Mensagem enviada com sucesso!"));
    } 
    else {
        Serial.print(F("Falha ao enviar, código de erro: "));
        Serial.println(transmissionState);
    }

    delay(5000);
  }
// }