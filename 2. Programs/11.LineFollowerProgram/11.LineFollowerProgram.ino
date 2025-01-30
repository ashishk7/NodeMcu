void setup() {
pinMode(D0,INPUT);
pinMode(D1,INPUT);
pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);
pinMode(D5,INPUT);
}

void loop() {
int ls = digitalRead(D0);
int rs = digitalRead(D1);

if (ls == HIGH && rs==HIGH){
digitalWrite(D2,HIGH);  digitalWrite(D3,LOW); digitalWrite(D4,HIGH); digitalWrite(D5,LOW);}
if (ls == HIGH && rs==LOW){
digitalWrite(D2,HIGH);  digitalWrite(D3,LOW); digitalWrite(D4,LOW); digitalWrite(D5,LOW);}
if (ls == LOW && rs==HIGH){
digitalWrite(D2,LOW);  digitalWrite(D3,LOW); digitalWrite(D4,HIGH); digitalWrite(D5,LOW);}
if (ls == LOW && rs==LOW){
digitalWrite(D2,LOW);  digitalWrite(D3,LOW); digitalWrite(D4,LOW); digitalWrite(D5,LOW);}
}
