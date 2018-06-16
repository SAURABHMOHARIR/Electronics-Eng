//PWM
/*
 * Author: Saurabh Moharir
 * Alihussain Kanchwala
 * KKWIEER,NASHIK
 */
const int LED=10;

void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int b;
for(b=0;b<=1023;b+=50)
{
  analogWrite(LED,b);
  delay(50);
}
}
