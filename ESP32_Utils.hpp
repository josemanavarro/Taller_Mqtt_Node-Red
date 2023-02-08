// Función que conecta la placa a una red WiFi con DHCP
void ConnectWiFi_STA(bool useStaticIP = false)
{
   Serial.println("");
   WiFi.mode(WIFI_STA);
   WiFi.begin(ssid, password);
   if(useStaticIP) WiFi.config(ip, gateway, subnet);
   while (WiFi.status() != WL_CONNECTED) 
   { 
     delay(1000);  
     Serial.print('.'); 
   }
 
   Serial.println("");
   Serial.print("Conectado a:\t");
   Serial.println(ssid);
   Serial.print("Con dirección IP:\t");
   Serial.println(WiFi.localIP());
}

// Función que conecta la placa a una red WiFi con IP fija
void ConnectWiFi_AP(bool useStaticIP = false)
{ 
   Serial.println("");
   WiFi.mode(WIFI_AP);
   while(!WiFi.softAP(ssid, password))
   {
     Serial.println(".");
     delay(1000);
   }
   if(useStaticIP) WiFi.softAPConfig(ip, gateway, subnet);

   Serial.println("");
   Serial.print("Conectado a:\t");
   Serial.println(ssid);
   Serial.print("Con dirección IP:\t");
   Serial.println(WiFi.softAPIP());
}
