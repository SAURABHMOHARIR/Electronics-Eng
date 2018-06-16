
unsigned char rx1[6],Rxdata;
unsigned int i=0,j=0,bill=0,menu1[10];
   char  error, byte_read;
char bil[7];
//char t[16];
// LCD module connections
sbit LCD_RS at PORTA0_bit;
sbit LCD_EN at PORTA1_bit;
sbit LCD_D4 at PORTA4_bit;
sbit LCD_D5 at PORTA5_bit;
sbit LCD_D6 at PORTA6_bit;
sbit LCD_D7 at PORTA7_bit;

sbit LCD_RS_Direction at DDA0_bit;
sbit LCD_EN_Direction at DDA1_bit;
sbit LCD_D4_Direction at DDA4_bit;
sbit LCD_D5_Direction at DDA5_bit;
sbit LCD_D6_Direction at DDA6_bit;
sbit LCD_D7_Direction at DDA7_bit;
// End LCD module connections

void UartRxInterrupt() iv IVT_ADDR_USART__RXC
{
     RxData = UART1_Read();

     if(Rxdata=='1')
      {
       Lcd_Cmd(_LCD_CLEAR);
       Lcd_Out(1,1,"  TABLE No. 1   ");
       Lcd_Out(2,1,"      TEA      ");
       Delay_ms(2000);
        Lcd_Cmd(_LCD_CLEAR);
        bill=bill+10;
        menu1[i]=1;
        i++;
        j++;
       }
       if(Rxdata=='2')
      {
       Lcd_Cmd(_LCD_CLEAR);
        Lcd_Out(1,1,"  TABLE No. 1   ");
       Lcd_Out(2,1,"      MEAL     ");
       Delay_ms(2000);
        Lcd_Cmd(_LCD_CLEAR);
         bill=bill+80;
        menu1[i]=2;
        i++;
        j++;
       }

       if(Rxdata=='4')
      {
        Lcd_Cmd(_LCD_CLEAR);
         Lcd_Out(1,1,"  TABLE No. 1   ");
       Lcd_Out(2,1,"     DRINKS      ");
       Delay_ms(2000);
       Lcd_Cmd(_LCD_CLEAR);
        bill=bill+10;
       menu1[i]=4;
        i++;
        j++;
       }
       if(Rxdata=='5')
      {
       Lcd_Cmd(_LCD_CLEAR);
        Lcd_Out(1,1,"  TABLE No. 1   ");
       Lcd_Out(2,1,"    DESSERTS    ");
       Delay_ms(2000);
       Lcd_Cmd(_LCD_CLEAR);
        bill=bill+25;
       menu1[i]=5;
        i++;
        j++;
      }
       if(Rxdata=='7')
      {
        Lcd_Cmd(_LCD_CLEAR);
         Lcd_Out(1,1,"  TABLE No. 1   ");
        Lcd_Out(2,1,"    SUBMIT      ");
        Delay_ms(2000);
        Lcd_Cmd(_LCD_CLEAR);
        menu1[i]=7;
        i++;
        j++;
       }

 }
void main()
{

 // unsigned int i;
  DDRA=0xff;
  DDRC=0x00;
  PORTC=0xff;
  //DDRB.B0=1;
  Lcd_Init();                        // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
  //txt1[16]=0;
  UART1_Init(9600);               // Initialize UART module at 9600 bps
  UCSRB |= (1<<RXCIE);
  SREG|=(1<<7);                   //Enable Global Interrupt
  Delay_ms(100);
  /*
  for(i=0;i<=10;i++)
  {
  menu1[i]=' ';
  }
 // rx1[16]='\0';
    */
  while(1)
  {

  Lcd_Out(1,1,"     KITCHEN    ");
  Lcd_Out(2,1,"      DESK      ");
  //UART1_Write('A');
  if(PINC.B5==0)
  {
  //UART1_Write('A');
  UART1_Write_Text("  TABLE NO.1 ");
  UART1_Write(13);
   Delay_ms(50);
  for(i=0;i<=j;i++)
  {
  if(menu1[i]==1)
  {
   UART1_Write_Text("TEA       = 10");
   UART1_Write(13);
    Delay_ms(50);
  }
   if(menu1[i]==2)
  {
   UART1_Write_Text("MEAL      = 80");
   UART1_Write(13);
    Delay_ms(50);
  }
   if(menu1[i]==4)
  {
   UART1_Write_Text("DRINKS    = 10");
   UART1_Write(13);
    Delay_ms(50);
  }
   if(menu1[i]==5)
  {
   UART1_Write_Text("DESSERTS  = 25");
   UART1_Write(13);
    Delay_ms(50);
  }
  }
  i=0;
   Delay_ms(10);
   IntToStr(bill,bil);
    Delay_ms(50);
    UART1_Write_Text("-------------- ");
     UART1_Write(13);
    UART1_Write_Text(" TOTAL = ");
  UART1_Write_Text(bil);
   UART1_Write(13);
   Delay_ms(10);
   while(PINC.B5==0);
   
 }
 }


}