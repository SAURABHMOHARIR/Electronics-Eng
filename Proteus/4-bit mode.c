#include <htc.h>
#define _XTAL_FREQ 20e6
#define en RD7
#define rs RD6
#define rw RD5

void delay(unsigned int time)  //Time delay function
{
unsigned int i,j;
for(i=0;i<time;i++)
for(j=0;j<5;j++);
}

             //Function for sending values to the command register of LCD
void llcdcmd(unsigned char value)  
{
RB0=(value >> 0) & 0x01;
RB1=(value >> 1) & 0x01;
RB2=(value >> 2) & 0x01;
RB3=(value >> 3) & 0x01;
/*PORTB=0xF0;
PORTB | =(value&0x0F);
delay(500); */
en = 1;    //enable-e
delay(500);
en=0;       //enable-e
delay(500);
}
             //Function for sending values to the data register of LCD
void ddisplay(unsigned char value)  
{
RB0=(value >> 0) & 0x01;
RB1=(value >> 1) & 0x01;
RB2=(value >> 2) & 0x01;
RB3=(value >> 3) & 0x01;
/*PORTB=0xF0;
PORTB | =(value&0x0F);
delay(500); */
en= 1;       //enable-e
delay(500);
en=0;        //enable-e
delay(500);
}


void display(unsigned char c){
rs= 1;       //register select-rs 
rw= 0;       //read-write-rd
delay(150);
ddisplay(c>>4);
delay(150);
ddisplay(c);

}
void lcdcmd(unsigned char c){
rs= 0;           //register select-rs 
rw = 0;      //read-write-rd
delay(150);
llcdcmd(c>>4);
delay(150);
llcdcmd(c);
}



             //function to initialize the registers and pins of LCD
             //always use with every lcd of hitachi
void lcdint(void)         
{
TRISB0=0;
TRISB1=0;
TRISB2=0;
TRISB3=0;    //Port 1 is used as output port             
TRISD5=0;
TRISD6=0;
TRISD7=0;
rw=0;
rs=0;
	PORTB &= 0xF0;		   
	 PORTB |= (0x03&0x0F);    // Write 0x3
	
	 en  = 1;               
	 delay(150);
	 en  = 0;               
	 delay(150);

     delay(4500);

	 PORTB &= 0xF0;		   
	 PORTB |= (0x03&0x0F);    // Write 0x3
	
	 en  = 1;               
	 delay(150);
	 en  = 0;              
	 delay(150);

     delay(300);

	 PORTB &= 0xF0;		   
	 PORTB |= (0x03&0x0F);    // Write 0x3
	
	 en  = 1;              
	 delay(150);
	 en  = 0;              
	 delay(150);

     delay(650);

	 PORTB &= 0xF0;		  
	 PORTB |= (0x02&0x0F);    // Write 0x2
	
	 en  = 1;               
	 delay(150);
	 en  = 0;              
	 delay(150);
display(0x20);
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

void main()
{
lcdint();
display('M');
display('i');
display('c');
display('r');
display('o');
display('c');
display('o');
display('n');
display('t');
display('r');
display('o');
display('l');
display('l');
display('e');
display('r');
lcdcmd(0xC0);
display('M');
display('i');
display('c');
display('r');
display('o');
display('c');
display('o');
display('n');
display('t');
display('r');
display('o');
display('l');
display('l');
display('e');
display('r');
lcdcmd(0x01);
delay(500);
}

