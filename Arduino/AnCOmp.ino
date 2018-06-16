/*
 * Pgm Name:
 * Author:
 * SAURABH  MOHARIR
 * ALIHUSSAIN KANCHWALA
 */
 int sen=A0;
 int l=12;
 int sv=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(l,OUTPUT);
  pinMode(sen,INPUT);
Serial.begin(4800);
}

void loop() {
  // put your main code here, to run repeatedly:
sv=analogRead(sen);
digitalWrite(l,HIGH);
if(sv<511)
{
  digitalWrite(l,LOW);
  
}
else
{
  digitalWrite(l,HIGH);
 }
 Serial.print("Input is =");
Serial.println(analogRead(sen));
delay(1000);
}
