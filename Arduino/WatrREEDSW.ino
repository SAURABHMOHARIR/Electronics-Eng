/*
 * Author: Saurabh Moharir
 * Alihussain Kanchwala
 * KKWIEER,NASHIK
 */
 const int mo=13;
 const int s1=10;
 const int s2=9;
 int s1s,s2s=0;
 void setup() {
  // put your setup code here, to run once:
pinMode(mo,OUTPUT);
pinMode(s1,INPUT);
pinMode(s2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
s1s=digitalRead(s1);
if(s1s==00)
{
  digitalWrite(mo,HIGH);
}else
{
  s2s=digitalRead(s2);
  if(s2s==0)
  {
    digitalWrite(mo ,LOW);
  }
}
}
