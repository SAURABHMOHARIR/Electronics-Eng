#include<pic18f4550.h>
void delay()
{
    unsigned int j;
     for(j=0;j<30000;j++);
}

void main ()
{
    unsigned char i,key=0,p=0x01;
    TRISB=0X00;
    TRISDbits.TRISD0=1;
    TRISDbits.TRISD1=1;
    TRISDbits.TRISD2=0;
    TRISAbits.TRISA4=0;
          while(1)
          {
              if(PORTDbits.RD0==0)
                  key=0;
              if(PORTDbits.RD1==0)
                  key=1;
                         if(key==0)
                         {
                             p=0x80;
                             PORTAbits.RA4=0;
                                     PORTDbits.RD2=1;
                                     for(i=0;i<8;i++)
                                     {
                                         PORTB=p;
                                         p=p>>1;
                                         delay();
                                     }

                         }

           
                         if(key==1)
                         {
                             p=0x01;
                             PORTAbits.RA4=1;
                                     PORTDbits.RD2=0;
                                     for(i=0;i<8;i++)
                                     {
                                         PORTB=p;
                                         p=p<<1;
                                         delay();

                                     }

                         }





          }
}