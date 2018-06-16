/* RTC interfacing with pic18f using i2c
 * Author: SAURABH MOHARIR
 * Date:20/11/2016
 */
#include<pic18f4550.h>
#include <stdio.h>
#define RS PORTCbits.RC0
#define EN PORTCbits.RC1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
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
 void comp()
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

/* MAIN FUNCTION */
void main()
{
    TRISAbits.RA0=1;
TRISDbits.RD0=0;
    TRISB = 0x00;                           // Configure LED pins (PORT B) as output
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;
    unsigned char date,mnt,yr,sec,min,hrs,i;
    i2c_init();
    set_reg(0x00,0x56);//seconds
    set_reg(0x01,0x23);//minutes
set_reg(0x02,0x02);//Hours along with 12 hour AM and PM
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
    sprintf(str,"Date:%0.2x:%0.2x:%0.2x",date,mnt,yr);
    lcdcmd(0x80);
    stringlcd("----Farmosys----");
    lcdcmd(0xC0);
    for(i=0;i<13;i++)
    {
        lcddata(str[i]);
    }
    sprintf(str,"Time:%0.2x:%0.2x:%0.2x",hrs,min,sec);
    lcdcmd(0x90);
    for(i=0;i<13;i++)
    {
        lcddata(str[i]);
         }
    delay(1000);
      // lcdinit();
    lcdcmd(0xD0);
               stringlcd("Temperature:");
    unsigned short Ch_result,x;
    char vstring[3];
   // while(1){

       // lcdcmd(0xC0);
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
        comp();
        float temp;
        int a;

        temp=0.48875*Ch_result;
        a=round(temp);
           sprintf(vstring,"%d",a);
        stringlcd(vstring);
        delay();
        lcddata(223);
        lcddata('C');
     

//}

} 
}

