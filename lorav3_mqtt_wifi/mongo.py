import paho.mqtt.client as mqtt
from pymongo import MongoClient
import json
from datetime import datetime

# Substitua 'LINK' pelo link de conexão do MongoDB
mongo_client = MongoClient('mongodb+srv://teste:teste@cluster0.qihgz9u.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0') 
mongo_db = mongo_client['teste'] # MongoDB database name
mongo_collection = mongo_db['sofri'] # MongoDB collection name


#mqtt.eclipseprojects.io
#broker.hivemq.com
#broker.emqx.io

mqtt_broker = 'test.mosquitto.org'
mqtt_port = 1883
mqtt_topic = '/aula/ENE090/pub/caiocamille'

def on_connect(client, userdata, flags, rc):
    print(f"Conectado ao broker MQTT com código de resultado {rc}")
    client.subscribe(mqtt_topic)

def on_message(client, userdata, msg):
    print(f"Mensagem recebida no tópico {msg.topic}: {msg.payload.decode()}")
    data_e_hora_atuais = datetime.now()
    
    try:
        message = json.loads(msg.payload.decode())
    except json.JSONDecodeError:
        message = {"time": data_e_hora_atuais.strftime('%d/%m/%Y %H:%M'),
                    "message": msg.payload.decode()}
    
    # Armazene a mensagem no MongoDB
    mongo_collection.insert_one(message)

# Configuração do cliente MQTT
mqtt_client = mqtt.Client()
mqtt_client.on_connect = on_connect
mqtt_client.on_message = on_message


# Conecte ao broker MQTT
mqtt_client.connect(mqtt_broker, mqtt_port, 60)

# Inicie o loop para processar mensagens recebidas
mqtt_client.loop_forever() 
