const int RED = 12;
const int Y = 11;
const int G = 10;
void setup() {
  // put your setup code here, to run once:
pinMode(RED,OUTPUT);
pinMode(Y,OUTPUT);
pinMode(G,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(RED,HIGH);
digitalWrite(Y,LOW);
digitalWrite(G,LOW);
delay(10000);
digitalWrite(RED,LOW);
digitalWrite(Y,HIGH);
digitalWrite(G,LOW);
delay(2000);
digitalWrite(RED,LOW);
digitalWrite(Y,LOW);
digitalWrite(G,HIGH);

delay(5000);



}
