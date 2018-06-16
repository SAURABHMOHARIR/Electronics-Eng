#include<P18F4550.h>
#define RS PORTCbits.RC0
#define En PORTCbits.RC1
#define B1 PORTDbits.RD0

void delay()
{
	unsigned int q;
	for(q=0;q<10000;q++);
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


void lcdinit()
{
     lcdcmd(0x38);	//Call Command subroutine (value=0x38)
    delay();
    lcdcmd(0x0E);
    delay();
    lcdcmd(0x01);
    delay();
    lcdcmd(0x06);
    delay();

}
void adcinit(){
    TRISAbits.RA0=1;
    ADCON1 = 0x10;                //Ref voltages Vdd & Vss; AN0 - AN7 channels Analog
    ADCON2 = 0x18;
}
unsigned char bcd2ascii(unsigned char mbyte)
{
    unsigned char i,j,r1,r2,fr;
    i= mbyte & 0x0F;
    r1=i | 0x30;
    j=mbyte & 0xF0;
    j=j>>4;
    r2=j|0x30;
    fr=r1|r2;
    return(fr);
}
void stringlcd(const char * s)
{

            while(*s)
            lcddata(*s++);

}
unsigned char deci2ascii(unsigned char mb){
    unsigned char ans;
    ans= 0x30 | mb;
    return(ans);

}


void main()
{
    TRISAbits.RA3=1;
    TRISAbits.RA0=1;
    TRISDbits.RD0=1;
    TRISB = 0x00;                           // Configure LED pins (PORT B) as output
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;
    lcdinit();
    lcdcmd(0x80);
   
           unsigned char dt[]="Temperature";


    stringlcd(dt);
    unsigned char b;
      while(1)
    {
    if(B1=1){
   
          lcdcmd(0xC0);
          ADCON0=0x01;
          ADCON0bits.GO=1;
          while(ADCON0bits.GO==1)

    delay();

 unsigned long ADCResult;
unsigned int value[3];
char vstring[3];
    {
        lcdcmd(0xC0);
          delay();

      ADCResult = (ADCRead(0) * 500) >>10;
          value[0] = ADCResult / 100;
          value[1] = (ADCResult / 10) % 10;
          value[2] = ADCResult % 10;
          vstring[0] = value[0] + 48;
          vstring[1] = value[1] + 48;
          vstring[2] = value[2] + 48;
          delay();
       // val=ADCRead(0);
          //ans= (ADRESL*500)/1023;
          stringlcd(vstring);
   lcddata(223);
    lcddata('C');
    }while(1);
     }
      }
}

