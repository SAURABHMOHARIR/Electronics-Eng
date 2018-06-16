#include<P18F4550.h>
#define RS LATCbits.LATC0
#define En LATCbits.LATC1
// LCD functions
void delay(unsigned int itime)
{
	unsigned int i,j;
	for(i=0;i<itime;i++)
        for(j=0;j<165;j++);
}
// LCD Functions
void lcdcmd(unsigned char value)
{
    LATB=value;
    RS=0;	//Select command register
   // delay();
    En=1;			// High to Low pulse on Enable pin of LCD
    delay(250);
    En=0;
}
void lcddata(unsigned char value)
{
    LATB=value;
    RS=1;//Select data register
   // delay();
    En=1;			// High to Low pulse on Enable pin of LCD
   delay(250);
    En=0;

}


void lcdinit()
{
     lcdcmd(0x38);	//Call Command subroutine (value=0x38)
  delay(250);
    lcdcmd(0x0E);
  delay(250);
    lcdcmd(0x01);
    //delay();
   // lcdcmd(0x06);
   // delay();

}

void stringlcd(const char * s)
{
            while(*s)
            lcddata(*s++);
}
void main()
{
    TRISB = 0x00;                           //Configure Data bus

    TRISCbits.TRISC0 = 0;                   // Configure RC0 as RS
    TRISCbits.TRISC1 = 0;                   // Configure RC1 as EN

    lcdinit();
    delay(250);
    lcdcmd(0x80);
    delay(250);
    stringlcd("Hello World");
    delay(250);
    lcdcmd(0xC0);
    delay(250);
    stringlcd("Good Morning");
    lcdcmd(0x90);
    stringlcd("SAMO");
    lcdcmd(0xD0);
    stringlcd("Systems");
    
}
