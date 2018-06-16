#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
void setup() {
  // put your setup code here, to run once:


}

void loop() {
  // put your main code here, to run repeatedly:

lcd.begin(16,2);
lcd.clear();
lcd.setCursor(2,0);

lcd.print("HELLO");
lcd.setCursor(0,1);
lcd.print("Saurabh Ali");
delay(500);

}
