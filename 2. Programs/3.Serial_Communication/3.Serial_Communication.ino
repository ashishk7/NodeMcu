#define LED D0
void setup() {
pinMode(LED,OUTPUT);
}

void loop() {
char x= Serial.read();

if(x=='a')
{digitalWrite(LED,HIGH);}
if(x=='b')
{digitalWrite(LED,LOW);}

}
