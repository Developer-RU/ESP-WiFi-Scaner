#include "ESP8266WiFi.h"

void setup()
{
    Serial.begin(115200);
  
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
}

void loop()
{
    int n = WiFi.scanNetworks();
    
    if (n == 0)
    {
        Serial.println("No networks found");
    }
    else
    {
        
        Serial.print("Networks found: ");
        Serial.println(n);
        Serial.println("");
        
        for (int i = 0; i < n; ++i)
        {
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
            delay(10);
        }
    }
    
    Serial.println("----------------------------------------------------------");
  
    delay(5000);
}
