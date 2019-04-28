#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
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
{
  if (client.connect(server,80))     // "184.106.153.149" or api.thingspeak.com 
  {   //Serial.println("connected");
      client.print(String("GET https://api.thingspeak.com/channels/577527/feeds.json?api_key=9E9L480OZE16RZSP&results=1/") + " HTTP/1.1\r\n" +
             "Host: " + server + "\r\n" +
             "Connection: close\r\n" +
             "\r\n");

       static char responseBuffer[3*1024]; // Buffer for received data

      while (client.connected() || client.available())
            {if (client.available())
                { String line = client.readStringUntil('\n');
                   if ( line.indexOf('{',0) >= 0 ) {                  // Ignore data that is not likely to be JSON formatted, so must contain a '{'
                     line.toCharArray(responseBuffer, line.length()); // Convert to char array for the JSON decoder
                     decodeJSON(responseBuffer);                      // Decode the JSON text
                      }
                }
     
  
  }}
  else
  {
    Serial.println("connection failed!]");
    client.stop();
  }

}


String decodeJSON(char *json) {
  StaticJsonDocument <3*1024> doc;
  char *jsonstart = strchr(json, '{');                     // Skip characters until first '{' found and ignore length, if present
  if (jsonstart == NULL) {
    Serial.println("JSON data missing");

  }
  json = jsonstart;
  DeserializationError error = deserializeJson(doc, json); // Parse JSON
  if (error) {
    Serial.print("deserializeJson() failed with code: ");
    Serial.println(error.c_str());
 
  }
  
    JsonObject channel = doc["feeds"][0];                 // Now we can read 'feeds' values and so-on
    String field1 = channel["field1"];
    Serial.println("Field1: "+field1);
    if(field1=="1") {digitalWrite(D0,HIGH);}
    if(field1=="0") {digitalWrite(D0,LOW);}

}
