import paho.mqtt.client as mqtt
import time

# Configurações do MQTT
mqtt_broker = 'test.mosquitto.org'
mqtt_port = 1883
mqtt_topic = '/aula/ENE090/pub/caiocamille'

# Configuração do cliente MQTT
mqtt_client = mqtt.Client()

# Conecte ao broker MQTT
mqtt_client.connect(mqtt_broker, mqtt_port, 60)

# Função para publicar mensagens
def publish_message(message):
    mqtt_client.publish(mqtt_topic, message)
    print(f"Mensagem publicada no tópico {mqtt_topic}: {message}")

# Publicando mensagens em loop (apenas como exemplo)
for i in range(10):
    message = f"Mensagem {i} da aula ENE090"
    publish_message(message)
    time.sleep(10)  # Aguarde 2 segundos antes de enviar a próxima mensagem

# Encerre a conexão MQTT
mqtt_client.disconnect()
