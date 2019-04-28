void setup() {
Serial.begin(9600);
}
void loop() {
int values=analogRead(A0);
Serial.println(values);
delay(400);
}
