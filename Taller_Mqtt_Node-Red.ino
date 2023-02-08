// Librerías:
#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#include <OneWire.h>                
#include <DallasTemperature.h>

// Ficheros:
#include "config.h"             // Fichero de configuración
#include "MQTT.hpp"             // Funciones de uso de MQTT
#include "ESP32_Utils.hpp"      // Funciones de conexión WiFi
#include "ESP32_Utils_MQTT.hpp" // Funciones de conexión MQTT

DHT dht(DHTPIN, DHTTYPE);             // Se declara el sensor DHT
OneWire ourWire(WIREPIN);             // Se establece el pin 2  como bus OneWire
DallasTemperature sonda(&ourWire);    // Se declara una variable u objeto para nuestro sensor

// Método de inicio de la placa:
void setup(void)
{
	Serial.begin(115200);   // Iniciamos la 	
  dht.begin(); 
  sonda.begin();
	ConnectWiFi_STA(true);
	InitMqtt();
}

float hum;      //Humedad
float tempCI;   //Temperatura Celsius Interna
float tempFI;   //Temperatura Fahrenheit Interna
float tempCE;   //Temperatura Celsius Externa
float tempFE;   //Temperatura Fahrenheit Externa

// Método a ejecutar en la placa
void loop()
{
	HandleMqtt();
	PublisMqtt(millis());
	delay(ESPERA);

  // Leemos del DHT:
  hum = dht.readHumidity();  
  tempCE = dht.readTemperature();  
  tempFE = dht.readTemperature(true);

  // Comprobamos posibles errores de lectura:
  if (isnan(hum) || isnan(tempCE) || isnan(tempFE)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
  } else {
  // Si ha leído bien publicamos:
    PublisMqttFloatTopic(hum,topic_humedad);
    PublisMqttFloatTopic(tempCE,topic_externaC);  
    PublisMqttFloatTopic(tempFE,topic_externaF);    
  }

  // Leemos de la sonda:
  sonda.requestTemperatures();
  tempCI = sonda.getTempCByIndex(0);
  tempFI = sonda.getTempFByIndex(0);
  
  // Comprobamos posibles errores de lectura:
  if (isnan(tempCI) || isnan(tempFI) || (tempCI == -127) || (tempFI == -127)){
    Serial.println("Error obteniendo los datos de la sonda");
    return;
  }else{
  // Si ha leído bien publicamos:
    PublisMqttFloatTopic(tempCI,topic_internaC);  
    PublisMqttFloatTopic(tempFI,topic_internaF); 
  }
}
