#include<PIC18F4550.h>
#include<stdio.h>
#include<stdlib.h>
#define RS PORTCbits.RC0
#define En PORTCbits.RC1

void delay()
{
	unsigned int q;
	for(q=0;q<10000;q++);
}
// LCD Functions
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

void stringlcd(const char * s)

{
            while(*s)
            lcddata(*s++);
}

// ADC FUNCTIONS
void adcinit(){
    TRISAbits.RA0=1;
    ADCON1 = 0x01;       //Ref voltages Vdd & Vss; AN0 - AN7 channels Analog
    ADCON2 = 0x8E; // select result format, acquistion time,clock slect bits
    ADCON2bits.ADFM=1;
}

 unsigned long ADCRead( unsigned char ch){
 //Invalid Channel
 ADCON0 = 0x00;//configuring analog channel
 ADCON0 = (ch<<2); //selecting analog channel
 ADCON0bits.ADON = 1; //switch on adc module
 ADCON0bits.GODONE =1;//Start conversion

 while(ADCON0bits.GODONE); //wait for the conversion to finish
 ADCON0bits.ADON=0; //switch off adc

 return ADRES;
 }


unsigned int deci2ascii(unsigned int mb){
    unsigned int ans;
    ans= 0x30 | mb;
    return(ans);

}
void main()
{
    TRISCbits.RC0=0;
    TRISCbits.RC1=0;
    TRISAbits.RA0=1;
    TRISB=0x00;
    lcdinit();
    lcdcmd(0x80);
    unsigned char l[]="Voltage";
    stringlcd(l);

      while(1){   adcinit();


unsigned long ADCResult;
unsigned int value[3];
char vstring[3];
   
        lcdcmd(0xC0);
     /* ADCResult = (ADCRead(0) * 5) >>10;
          value[0] = ADCResult / 100;
          value[1] = (ADCResult / 10) % 10;
          value[2] = ADCResult % 10;
          vstring[0] = value[0] + 48;
          vstring[1] = value[1] + 48;
          vstring[2] = value[2] + 48;
          delay();
stringlcd(vstring);*/
        unsigned short Ch_result,x;
        Ch_result= ADCRead(0);

        float volt;
        volt=0.004887585*Ch_result;

     sprintf(vstring, "%f", volt);
     stringlcd(vstring);

     /*   unsigned int i;
            for(i=0;i<10;i++)
 {
    x=Ch_result & 0x200;
   if(x==0)
   {
    lcddata('0');
   }
   else
   {
     lcddata('1');
   }
   Ch_result<<=1;
 }
      *
      * char str[10];
float adc_read = 678.0123;

dtostrf( adc_read, 3, 4, temp );
sprintf(str,"adc_read = %10s \n", temp);
printf(temp);
        delay();*/
         }
    }
