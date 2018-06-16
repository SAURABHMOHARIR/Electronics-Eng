//LED Outputs
const int LED1=13;
const int LED2=7;
const int LED3=9;
// Input Peripherals
const int P1=10;
const int P2=11;
const int P3=12;

void setup() {
  // put your setup code here, to run once:
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
pinMode(P1,INPUT);
pinMode(P2,INPUT);
pinMode(P3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int P1s,P2s,P3s;

P1s=digitalRead(P1);
P2s=digitalRead(P2);
P3s=digitalRead(P3);



if(P1s==1)
{
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
  delay(1000);}

 else if((P2s==1) && (P1s==0))
{ digitalWrite(LED2,HIGH);
  digitalWrite(LED3,LOW);
    digitalWrite(LED1,LOW);
   delay(1000);
   }
    else if((P3s=1)&&(P2s==0) && (P1s==0))
{ digitalWrite(LED3,HIGH);
  digitalWrite(LED2,LOW);
    digitalWrite(LED1,LOW);
   delay(1000);
   }
        
}
