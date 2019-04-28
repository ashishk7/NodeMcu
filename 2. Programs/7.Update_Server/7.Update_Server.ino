#include <ESP8266WiFi.h>
String decodeJSON(char *json);
const char* ssid = "Redmi Ashish";    // Enter SSID here
const char* password = "ashish@8894";  //Enter Password here
const char* server = "api.thingspeak.com";
WiFiClient client;

void setup() {
  pinMode(D0,OUTPUT);
  Serial.begin(9600);
  delay(1000);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() 
{ int x = analogRead(A0);
  if (client.connect(server,80))     // "184.106.153.149" or api.thingspeak.com 
  {   Serial.println(x);
      Serial.println("connected");
      client.print(String("GET https://api.thingspeak.com/update?api_key=FJDNXSQ26G8NXA41&field1=")+ x + " HTTP/1.1\r\n" +
             "Host: " + server + "\r\n" +
             "Connection: close\r\n" +
             "\r\n");
       Serial.println("value updated");

      while (client.connected() || client.available())
            {if (client.available())
                { String line = client.readStringUntil('\n');
                   Serial.println(line);}
            }
  }
  
  else
  {
    Serial.println("connection failed!]");
    client.stop();
  }
  delay(10000);
}
