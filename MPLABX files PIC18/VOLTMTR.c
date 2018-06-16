#include<p18f458.h>
#include<stdio.h>
#define RS PORTCbits.RC0
#define EN PORTCbits.RC1
void delay()
{
    unsigned int i,j;
    for(i=0;i<20;i++){
        for(j=0;j<20;j++);
    }
}
void lcdcmd(unsigned char value)
{
    RS=0;
    delay();
    PORTB= value;
    EN=1;
    delay();
    EN=0;
}
void lcddata(unsigned char value)
{
    RS=1;
    delay();
    PORTB=value;
    EN=1;
    delay();
    EN=0;
    }


void lcdstring(unsigned char *string)
{
    while(*string){


    lcddata(*string);
    string++;
    }}


void main()
{
    unsigned short  Ch_result;
    unsigned char temp,i,text[10],tem;
    TRISB=0x00;
   TRISAbits.RA1=1;
  
   TRISCbits.RC0=0;
    TRISCbits.RC1=0;
    TRISB=0x00;
    lcdcmd(0x38);
    lcdcmd(0x06);
    lcdcmd(0x0E);
    lcdcmd(0x01);
    
      ADCON1=0b00000111;//left justified
    while(1)
    {
        lcdcmd(0x80);
        lcdstring("ADCValue=");
        ADCON0=0b00000110; // Select channel one, adon=1.
        delay();
        delay();
        lcdcmd(0xC0);
        ADCON0bits.GO=1;// Start of COnversion
        while(ADCON0bits.GO==1);// wait for EOC
        Ch_result=ADRES;
        delay();
        tem=(20000/1023)*ADRES;

        
   temp=temp & 0x03FC;
  
 
        for(i=0;i<3;i++)
        {text[i]=(temp%10)+'0';
        }

        text[4]='m';
        text[5]='v';
        for(i=0;i<6;i++)
        {
            lcddata(text[i]);
        }
     delay();
     delay();
    }

}