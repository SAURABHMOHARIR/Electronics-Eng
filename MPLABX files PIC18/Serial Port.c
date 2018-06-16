#include<PIC18F4550.h>

void delay()
{
    unsigned int i;
    for(i=0;i<=30000;i++);
}
void main()
{
    unsigned char data ;
    unsigned char s[]={'H','E','L','L','o'};
    TRISCbits.RC6=0;
    SPBRG = 0x4D; //baud rate
    TXSTA = 0x20;
    RCSTA = 0x90;
    int i;
    for(i=0;i<5;i++);
    {
        data=s[i];
        TXREG= data;
        while(TXIF==0);
        delay();
    }
}