#include <WiFi.h>
#include <PubSubClient.h>

// Definições de Wi-Fi e MQTT 
// Substituir login e senha
const char* ssid = "LABRA_lab";
const char* password = "LabraUFJF";
const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;
const char* mqtt_topic = "/aula/ENE090/pub/caiocamille";

// Definição do cliente WiFi e MQTT
WiFiClient espClient;
PubSubClient client(espClient);

// Função para conectar ao Wi-Fi
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

// Função para reconectar ao MQTT
void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32Client")) {
    } else {
      Serial.print("falha, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Envia uma mensagem a cada 5 segundos
  static unsigned long lastMsg = 0;
  unsigned long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    String msg = "Olá do ESP32!";
    Serial.print("Publicando mensagem: ");
    Serial.println(msg);
    client.publish(mqtt_topic, msg.c_str());
  }
}