/* 
 * File:   lcd.h
 * Author: SAURABH MOHARIR
 *
 * Created on January 29, 2017, 8:01 PM
 */

#include<P18F4550.h>
#define RS PORTCbits.RC0
#define En PORTCbits.RC1
void delay(){
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<1000;j++);
    }
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
   //  lcdcmd(0x38);	//Call Command subroutine (value=0x38)
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
