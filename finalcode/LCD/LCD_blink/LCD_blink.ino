#include <LiquidCrystal.h>

int d7=2;
int d6=3;
int d5=4;
int d4=5;
int E=10;
int RS=11;
LiquidCrystal lcd(RS, E, d4, d5, d6, d7); 
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);


}

void loop() {
  // put your main code here, to run repeatedly:

lcd.setCursor(3,0);
lcd.print("All ");
delay(1000);
lcd.clear();

lcd.setCursor(0,1);
lcd.print("Good");
delay(1000);
lcd.clear();


}
