const int mt1=8;
const int mt2=9;
void setup() {
  // put your setup code here, to run once:
pinMode(mt1,OUTPUT);
pinMode(mt2,OUTPUT);
digitalWrite(mt1,LOW);
digitalWrite(mt2,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(mt1,LOW);
digitalWrite(mt2,HIGH);
delay(2000);
digitalWrite(mt2,LOW);
digitalWrite(mt1,HIGH);
delay(2000);
}
