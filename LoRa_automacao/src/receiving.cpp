// #include <RadioLib.h>
// // SX1262 has the following connections: Abaixo a conexão para o LORA V3
// // NSS pin: 8
// // DIO1 pin: 14
// // NRST pin: 12
// // BUSY pin: 13
// SX1262 radio = new Module(8, 14, 12, 13);
// volatile bool receivedFlag = false;
// #if defined(ESP8266) || defined(ESP32)
// ICACHE_RAM_ATTR
// #endif
// void setFlag(void) {
// // we got a packet, set the flag
// receivedFlag = true;
// }
// void Receber_Lora() {
//     if(receivedFlag) {
//     receivedFlag = false; // reset flag
//     String str;
//     int state = radio.readData(str);
//     if (state == RADIOLIB_ERR_NONE) {
//     // packet was successfully received
//     Serial.print("Mensagem Recebida:");
//     Serial.println(str);
//     }
//     }
// }

// void Iniciar_Lora() {
// int state = radio.begin();
// if (state == RADIOLIB_ERR_NONE) {
// Serial.println(F("Conexao Bem Sucedida!"));
// } else {
// Serial.print(F("Erro, Codigo "));
// Serial.println(state);
// while (true);
// }
// radio.setPacketReceivedAction(setFlag);
// state = radio.startReceive();
// if (state != RADIOLIB_ERR_NONE) {
// Serial.print(F("failed, code "));
// Serial.println(state);
// while (true);
// }
// }
// void setup() {
// Serial.begin(115200);
// Iniciar_Lora();
// }
// void loop() {
// Receber_Lora();
// }