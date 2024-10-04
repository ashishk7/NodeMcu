#include <ESP8266WiFi.h>

const char* ssid = "Pixel";
const char* password = "snowcruiser";

const char* host = "api.thingspeak.com";

static char responseBuffer[3*1024]; // Buffer for received data
void setup()
{
  Serial.begin(9600);
  Serial.println();

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
}


void loop()
{
  WiFiClient client;

  Serial.printf("\n[Connecting to %s ... ", host);
  if (client.connect(host, 80))
  {
    Serial.println("connected]");

    Serial.println("[Sending a request]");
    client.print(String("GET https://api.thingspeak.com/channels/549015/feeds.json?api_key=YNFPSSYNLXCX15PZ&results=1/") + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n" +
                 "\r\n"
                );

    Serial.println("[Response:]");
    while (client.connected() || client.available())
    {
      if (client.available())
      {
        String line = client.readStringUntil('\n');
        if ( line.indexOf('{',0) >= 0 ){
        line.toCharArray(responseBuffer, line.length());
        Serial.println(line);
        }

        
      }
    }
    client.stop();
    Serial.println("\n[Disconnected]");
  }
  else
  {
    Serial.println("connection failed!]");
    client.stop();
  }
  delay(5000);
}
