#include<PIC18F4550.h>
#include<stdio.h>
#include<math.h>
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
   // lcdcmd(0x06);
   // delay();

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

 unsigned int ADCRead( unsigned char ch){

 ADCON0 = 0x00;//configuring analog channel
 ADCON0 = (ch<<2); //selecting analog channel
 ADCON0bits.ADON = 1; //switch on adc module
 ADCON0bits.GO_DONE =1;//Start conversion

 while(ADCON0bits.GO_DONE); //wait for the conversion to finish
 ADCON0bits.ADON=0; //switch off adc

 return ADRES;
 }
/* void comp()
 {
     unsigned short ch;
     ch=ADCRead(0);
     if(ch>=0x3D){
         PORTDbits.RD0=1;
     }
     else
         if(ch<=0x3D)
             PORTDbits.RD0=0;
 }
*/


/*MAIN FUNCTION*/
void main()
{

    TRISAbits.RA1=1;
TRISDbits.RD0=0;
    TRISB = 0x00;                           // Configure LED pins (PORT B) as output
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;
    lcdinit();
    lcdcmd(0x80);

           unsigned char dt[]="Soil Moisture:";
    stringlcd(dt);

    unsigned short Ch_result;
    char vstring[3];
    while(1){

        lcdcmd(0xC0);
        adcinit();
     /*  ADCResult = (ADCRead(1) * 500) >>10;
          value[0] = ADCResult / 100;
          value[1] = (ADCResult / 10) % 10;
          value[2] = ADCResult % 10;
          vstring[0] = value[0] + 48;
          vstring[1] = value[1] + 48;
          vstring[2] = value[2] + 48;
          delay();
        //  val=ADCRead(0);
          //ans= (ADRESL*500)/1023;
          stringlcd(vstring);
       */
        Ch_result = ADCRead(0); // store 10 bit result ADRESH-ADRESL register in variable Ch_result
        //comp();
        float humid,fin,pcnt;
       int a;
      if(Ch_result>=483)
        {
          //  fin=(Ch_result)*0.004105571;
            fin=(Ch_result-483)*0.004887585;
        pcnt=(fin/1.83773216)*100;
        //humid=*Ch_result;
      a=round(pcnt);
        sprintf(vstring,"%d",a);
        stringlcd(vstring);
        delay();
        lcddata(37);
        //lcddata('C');

       //  lcddata(Ch_result);
// Display result in binary on LCD

       // delay();



    }
}
}



