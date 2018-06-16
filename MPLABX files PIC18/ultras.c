#include<PIC18F4550.h>

#define _XTAL_FREQ 2000000
#include<xc.h>

#define RS PORTCbits.RC0
#define En PORTCbits.RC1

void delay()
{
	unsigned int q;
	for(q=0;q<1000;q++);
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
void lcd_setcursor(int row,int col)
{
    if(row==0){
        lcdcmd(0x80 | col);
            }
    else if(row==1){
        lcdcmd(0xc0| col);
    }
}
/*
 Main Function for ultrasonic Sensor
 */
void main()
{
   
    TRISAbits.RA0=0;       // Trig pin of Ultrasonic
    TRISAbits.RA1=1;        // ECHO pin of Ultrasonic
    TRISB=0x00;             // Data bus of lcd
    TRISCbits.RC0=0;        //RS pin of LCD
    TRISCbits.RC1=0;        // EN pin of LCD
    int a,a1;
      
    lcdinit();
    lcdcmd(0x80);
    stringlcd("Water Level");
    /*  Timer Code        */
    T1CON=0x10;
    while(1){
       
        TMR1H=0;
        TMR1L=0;
      PORTAbits.RA0=1;
     _delay(0.00001);
         PORTAbits.RA0=0;
       
        while(PORTAbits.RA1==0);
        TMR1ON=1;
        while(PORTAbits.RA1==1);
        TMR1ON=0;
           
        a1=TMR1H<<8;
      a = (TMR1L + a1);   //Reads Timer Value
    a = a/147.05;                //Converts Time to Distance
    a = a + 1;
 
    //Distance Calibration
    if(a>=2 && a<=400)          //Check whether the result is valid or not
    {
        lcdcmd(0x01);
         lcd_setcursor(1,14);
      lcddata(a%10 + 48);

      a = a/10;
      lcd_setcursor(1,13);
      lcddata(a%10 + 48);

      a = a/10;
      lcd_setcursor(1,12);
      lcddata(a%10 + 48);

      lcd_setcursor(1,15);
      lcddata("cm");
    
    }
    else
    {
        lcdcmd(0x01);
        lcd_setcursor(1,1);
      stringlcd("Out of Range");
    }
    _delay(0.00004);
  }
 
}
