#define LED D0
void setup() {
pinMode(LED,OUTPUT);
}

void loop() {
for(int i=0;i<255;i=i+5)
{
  analogWrite(LED,i);
  delay(50);
}
for(int j=255;j>0;j=j-5)
{
  analogWrite(LED,j);
  delay(50);
}

}
