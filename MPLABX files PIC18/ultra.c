
#include<P18F4550.h>
#define RS PORTCbits.RC0
#define En PORTCbits.RC1

void delay()
{
    unsigned int i;
    for(i=0;i<5000;i++);
}


void lcdcmd(unsigned char value)
{
    PORTB=value;
    RS=0;			//Select command register
    En=1;			// High to Low pulse on Enable pin of LCD
    delay();
    En=0;
}
void lcddata(unsigned char value)
{
    PORTB=value;
    RS=1;			//Select data register
    En=1;			// High to Low pulse on Enable pin of LCD
    delay();
    En=0;

}
