const int LED1=13;
const int P1=10;
void setup() {
  // put your setup code here, to run once:
pinMode(LED1,OUTPUT);
pinMode(P1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int P1s;
P1s=digitalRead(P1);

if(P1s==1){
    digitalWrite(LED1,HIGH);
}
else{
    digitalWrite(LED1,LOW);
}
}
