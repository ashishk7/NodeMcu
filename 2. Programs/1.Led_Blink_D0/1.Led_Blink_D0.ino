#define LED D0            // Led in NodeMCU at pin GPIO16 (D0).
void setup() {
pinMode(LED, OUTPUT);     // set the digital pin as output.
}
void loop() {
digitalWrite(LED, HIGH);  // turn the LED off.(Note that LOW is the voltage level but actually
delay(200);              // wait for 1 second.
digitalWrite(LED, LOW);   // turn the LED on.
delay(200);              // wait for 1 second.
}
