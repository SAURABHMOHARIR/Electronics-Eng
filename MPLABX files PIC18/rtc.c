/* RTC interfacing with pic18f using i2c
 * Author: SAURABH MOHARIR
 * Date:20/11/2016
 */
#include<pic18f4550.h>
#include <stdio.h>
#define RS PORTCbits.RC0
#define EN PORTCbits.RC1
unsigned char str[20];
/* DELAY FUNCTION */
void delay()
{
    unsigned int i,j;
    for(i=0;i<50;i++)
    {
        for(j=0;j<20;j++);
    }
}
/*I2C FUNCTIONS:*/
void i2c_interface_init()
{
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
}

void i2c_interface_deinit()
{
    SSPCON1bits.SSPEN = 0;
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 0;
}

void i2c_init(void)
{
    i2c_interface_init();
    SSPADD = 126;  //set i2c clock
    SSPCON1= 0b00001000; //set i2c master
    SSPSTATbits.SMP = 1;  //select mode...standard selected
   // ADCON1 = 0x0F;
    SSPCON1bits.SSPEN = 1;
}

void i2c_start(void)    // Initiate a Start sequence
{
    PIR1bits.SSPIF=0;
    SSPCON2bits.SEN=1;
    while(PIR1bits.SSPIF == 0);
}

void i2c_restart(void)  // Initiate a Restart sequence
{
    PIR1bits.SSPIF=0;
    SSPCON2bits.RSEN=1;
    while(PIR1bits.SSPIF==0);
}

void i2c_write(unsigned int data)      // Write data to slave.
{
    PIR1bits.SSPIF=0;
    SSPBUF=data;
    while(PIR1bits.SSPIF==0);
}

void i2c_stop(void)     //Initiate a Stop sequence.
{
    PIR1bits.SSPIF=0;
    SSPCON2bits.PEN=1;
    while(PIR1bits.SSPIF==0);
}

unsigned char i2c_read(void)     //Read data from I2C bus.
{
    unsigned char data;
    PIR1bits.SSPIF=0;
    SSPCON2bits.RCEN=1;

    while(PIR1bits.SSPIF==0);
    data=SSPBUF;
    PIR1bits.SSPIF=0;
    SSPCON2bits.ACKEN=1;
    while(PIR1bits.SSPIF==0);
    return data;
}

/* LCD FUNCTIONS */
void lcddata(unsigned char value)
{
    RS=1;
    delay();
    PORTB= value;
    EN=1;
    delay();
    EN=0;
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
void initlcd()
{
    TRISCbits.RC0=0;
    TRISCbits.RC1=0;
    TRISB=0x00;

    lcdcmd(0x38);
    lcdcmd(0x06);
    lcdcmd(0x0C);
    lcdcmd(0x01);
    lcdcmd(0x80);
}
/* I2C AND RTC FUNCTIONS */
unsigned char get_reg(unsigned char addrs) //gets time
{
    unsigned char data;
   i2c_start();
    i2c_write(0b11010000); // RTC address
    i2c_write(addrs); // Memory Location Address
    i2c_restart();
    i2c_write(0b11010001);
    SSPCON2bits.ACKDT=1;
    data=i2c_read();
    i2c_stop();
    return(data);
    }
void set_reg(unsigned char addrs,unsigned char x) // sets time
{
    i2c_start();
    i2c_write(0b11010000);
    i2c_write(addrs);
    i2c_write(x);
    i2c_stop();
    return;
}
/* MAIN FUNCTION */
void main()
{
    unsigned char date,mnt,yr,sec,min,hrs,i;
    i2c_init();
    set_reg(0x00,0x56);//seconds
    set_reg(0x01,0x59);//minutes
set_reg(0x02,0x11);//Hours along with 12 hour AM and PM
set_reg(0x04,0x31);//date
set_reg(0x05,0x03);//month
set_reg(0x06,0x17);//year
initlcd();
lcdcmd(0x01);
while(1)
{
    i2c_init();
    sec=get_reg(0);
    min=get_reg(1);
    hrs=get_reg(2)&0x1F;
    date=get_reg(4);
    mnt=get_reg(5);
    yr=get_reg(6);

    SSPCON1bits.SSPEN=0;
    initlcd();
    sprintf(str,"date:%0.2x:%0.2x:%0.2x",date,mnt,yr);
    lcdcmd(0x80);
    for(i=0;i<13;i++)
    {
        lcddata(str[i]);
    }
    sprintf(str,"time:%0.2x:%0.2x:%0.2x",hrs,min,sec);
    lcdcmd(0xC0);
    for(i=0;i<13;i++)
    {
        lcddata(str[i]);
         }
    delay(1000);
}
}

 