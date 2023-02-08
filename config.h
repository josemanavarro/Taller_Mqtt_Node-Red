// FICHERO DE CONFIGURACIÓN:

// Constantes para cableado:
#define GRUPO 1                         //Grupo de trabajo cambiar por el correcto
#define DHTPIN 4                        //Pin del sensor
#define DHTTYPE DHT11                   //Tipo de sensor
#define WIREPIN 12                      //Pin de la sonda
#define ESPERA  5000                    //Tiempo de espera para el sensor

// Constantes para red:
const char* ssid     = "aula208";             //Red del aula
const char* password = "internet208";         //Clave de la red
const String hostname = "ESP32_"+GRUPO;       //Nombre del host
const IPAddress ip(192, 168, 208, 101);       //IP de la placa, cambiar último dígito
const IPAddress gateway(192, 168, 208, 1);    //IP de la puerta de enlace
const IPAddress subnet(255, 255, 255, 0);     //Máscara de subred

//Constantes para MQTT:
const char* MQTT_BROKER_ADRESS  = "192.168.208.100";                //Dirección del broker
const uint16_t MQTT_PORT        = 1883;                             //Puerto del broker
const char* MQTT_CLIENT_NAME    = (char*)hostname.c_str();          //Nombre del cliente
const String topic_test         = hostname + "/test";               //Topic prueba de conexión
const String topic_internaC     = hostname + "/internaC";           //Topic temperatura interna
const String topic_internaF     = hostname + "/internaF";           //Topic temperatura interna
const String topic_externaC     = hostname + "/externaC";           //Topic temperatura externa
const String topic_externaF     = hostname + "/externaF";           //Topic temperatura externa
const String topic_humedad      = hostname + "/humedad";            //Topic humedad externa
