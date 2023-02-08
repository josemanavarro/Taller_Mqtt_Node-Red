WiFiClient espClient;                 //Cliente WiFi
PubSubClient mqttClient(espClient);   //Cliente MQTT
String payload;                       //Contenido a enviar
String content;                       //Contenido a recibir

// Suscribe la placa al topic de test para probar conexión:
void SuscribeMqtt()
{
	mqttClient.subscribe((char*)topic_test.c_str());
}

// Suscribe la placa a un topic dado:
void SuscribeMqtt(String topic)
{
  mqttClient.subscribe((char*)topic.c_str());
}

// Publica un dato en el topic de test para probar conexión:
void PublisMqtt(unsigned long data)
{
	payload = "";
	payload = String(data);
	mqttClient.publish((char*)topic_test.c_str(), (char*)payload.c_str());
}

// Publica un dato en el topic dado:
void PublisMqttFloatTopic(float data,String topic)
{
  payload = "";
  payload = String(data);
  mqttClient.publish((char*)topic.c_str(), (char*)payload.c_str());
}

// Recibe un dato en un topic dado:
void OnMqttReceived(String topic, byte* payload, unsigned int length) 
{
	content = "";	
	for (size_t i = 0; i < length; i++) {
		content.concat((char)payload[i]);
	}
}
