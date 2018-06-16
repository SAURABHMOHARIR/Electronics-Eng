int swp=10;
int b=9;
void setup() {
  // put your setup code here, to run once:
pinMode(swp,INPUT);
pinMode(b,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Switch is");
if(int a=digitalRead(swp)==1)
{
  Serial.println("OPEN");
}
else
{
  Serial.println("Alert!!Intruder Detected.");
  digitalWrite(b,1);

delay(1000);}
delay(1000);
}
