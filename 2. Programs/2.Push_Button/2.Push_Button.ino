#define LED D0            // Led in NodeMCU at pin GPIO16 (D0).
#define Button D1         // Push Button in NodeMCU at D1.
void setup() {
pinMode(LED, OUTPUT);     // set the digital pin as output.
pinMode(Button, INPUT);   // set the digital pin as input.
}

void loop() {
int x = digitalRead(Button);
if(x==HIGH)
{digitalWrite(LED,HIGH);}
if(x==LOW)
{digitalWrite(LED,LOW);}
}
