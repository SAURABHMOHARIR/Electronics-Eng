#include<P18F4550.h>
void delay1()
{
	unsigned int q;
	for(q=0;q<30000;q++);
}
void main()
{
    TRISB = 0x00;                           //Configure LED pins (PORT B) as output
   // TRISDbits.TRISD0 = 1;                   // Configure RD0 as input (button 1)
  TRISDbits.TRISD1 = 1;                   // Configure RD1 as input (button 2)
   // TRISDbits.TRISD2 = 0;                   // Configure buzzer pin RD2 as output

while(1)
    {
if(PORTDbits.RD1 == 1)       //If button1 pressed
{
    PORTB=0xF0;
  
    }
else if(PORTDbits.RD1==0)
{
    PORTB=0x0F;
}
}}
