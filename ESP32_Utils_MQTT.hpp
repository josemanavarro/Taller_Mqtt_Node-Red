// Función que inicializa el cliente MQTT
void InitMqtt() 
{
	mqttClient.setServer(MQTT_BROKER_ADRESS, MQTT_PORT);
	SuscribeMqtt();
	mqttClient.setCallback(OnMqttReceived);
}

// Función que conecta el cliente MQTT
void ConnectMqtt()
{
	while (!mqttClient.connected())
	{
		Serial.print("Estableciendo la conexión MQTT...");
		if (mqttClient.connect(MQTT_CLIENT_NAME))
		{
			//SuscribeMqtt();
		}
		else
		{
			Serial.print("Fallo en la conexión MQTT, rc=");
			Serial.print(mqttClient.state());
			Serial.println(" Siguiente prueba en 5 segundos.");

			delay(5000);
		}
	}
}

// Función que maneja la conexión del cliente MQTT
void HandleMqtt()
{
	if (!mqttClient.connected())
	{
		ConnectMqtt();
	}
	mqttClient.loop();
}
