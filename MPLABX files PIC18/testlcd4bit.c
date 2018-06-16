#include<PIC18F4550.h>


#define RS PORTCbits.RC0
#define En PORTCbits.RC1
#define _XTAL_FREQ 20e6


void delay(unsigned int time)  //Time delay function
{
unsigned int i,j;
for(i=0;i<time;i++)
for(j=0;j<5;j++);
}

             //Function for sending values to the command register of LCD
void llcdcmd(unsigned char value)
{
PORTDbits.RD0=(value >> 0) & 0x01;
PORTDbits.RD1=(value >> 1) & 0x01;
PORTDbits.RD2=(value >> 2) & 0x01;
PORTDbits.RD3=(value >> 3) & 0x01;
/*PORTB=0xF0;
PORTB | =(value&0x0F);
delay(500); */
En = 1;    //enable-e
delay(500);
En=0;       //enable-e
delay(500);
}
             //Function for sending values to the data register of LCD
void ddisplay(unsigned char value)
{
PORTDbits.RD0=(value >> 0) & 0x01;
PORTDbits.RD1=(value >> 1) & 0x01;
PORTDbits.RD2=(value >> 2) & 0x01;
PORTDbits.RD3=(value > 3) & 0x01;
/*PORTB=0xF0;
PORTB | =(value&0x0F);
delay(500); */
En= 1;       //enable-e
delay(500);
En=0;        //enable-e
delay(500);
}


void display(unsigned char c){
RS= 1;       //register select-rs
//rw= 0;       //read-write-rd
delay(150);
ddisplay(c>>4);
delay(150);
ddisplay(c);

}
void lcdcmd(unsigned char c){
RS= 0;           //register select-rs
//rw = 0;      //read-write-rd
delay(150);
llcdcmd(c>>4);
delay(150);
llcdcmd(c);
}

/*
void lcdcmd(unsigned char value)
{
    PORTB &=0xF0;
    PORTB=(value&0xF0);
    RS=0;			//Select command register
    En=1;			// High to Low pulse on Enable pin of LCD
    delay();
    En=0;
    PORTB=((value)<<4&0xF0);
    RS=0;			//Select command register
    En=1;			// High to Low pulse on Enable pin of LCD
    delay();
    En=0;
}
void lcddata(unsigned char value)
{
   PORTB &=0x0F;
    PORTB=(value&0xF0);
    RS=1;			//Select command register
    En=1;			// High to Low pulse on Enable pin of LCD
    delay();
    En=0;
    PORTB=((value)<<4&0xF0);
    RS=1;			//Select command register
    En=1;			// High to Low pulse on Enable pin of LCD
    delay();
    En=0;
}


void lcdinit()
{
   //  lcdcmd(0x38);	//Call Command subroutine (value=0x38)
     delay();
                lcdcmd(0x30);   //Special Sequence:Write Function Set.
                delay();
                 lcdcmd(0x30);               //Special Sequence:Write Function Set.
                delay();
                 lcdcmd(0x30);
  //  lcdcmd(0x33);
    lcdcmd(0x28);
    lcdcmd(0x0E);
    delay();
    lcdcmd(0x01);
    delay();
    lcdcmd(0x06);
    delay();

}
 */
void lcdint(void)
{
/*TRISB0=0;
TRISB1=0;
TRISB2=0;
TRISB3=0;*/
//Port 1 is used as output port
TRISD0=0;
TRISD1=0;
TRISD2=0;
TRISD3=0;
//rw=0;
RS=0;
	PORTD &= 0xF0;
	 PORTD |= (0x03&0x0F);    // Write 0x3

	En  = 1;
	 delay(150);
	En = 0;
	 delay(150);

     delay(4500);

	 PORTD &= 0xF0;
	 PORTD |= (0x03&0x0F);    // Write 0x3

	En = 1;
	 delay(150);
	 En = 0;
	 delay(150);

     delay(300);

	 PORTD &= 0xF0;
	 PORTD |= (0x03&0x0F);    // Write 0x3

	 En = 1;
	 delay(150);
	 En = 0;
	 delay(150);

     delay(650);

	 PORTD &= 0xF0;
	 PORTD |= (0x02&0x0F);    // Write 0x2

	 En  = 1;
	 delay(150);
	En = 0;
	 delay(150);
//display(0x20);
delay(1000);
lcdcmd(0x28);
delay(50);
lcdcmd(0x0C);
delay(50);
lcdcmd(0x01);
delay(50);
lcdcmd(0x06);
delay(50);
lcdcmd(0x80);
delay(50);
}
void stringlcd(const char * s)
{
            while(*s)
            display(*s++);
}
void main()
{
    TRISCbits.RC0=0;
    TRISCbits.RC1=0;
    //TRISB=0x00;
    TRISD=0x00;
    lcdint();
    
  //  lcdcmd(0x80);
    delay(20);

    display(A);
   
}

