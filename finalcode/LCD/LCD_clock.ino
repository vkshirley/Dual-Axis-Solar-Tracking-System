#include <LiquidCrystal.h>

int d7=2;
int d6=3;
int d5=4;
int d4=5;
int E=10;
int RS=11;
int in=12;
int i=0;
int second=0;
int minutes=0;
int hours=0;
LiquidCrystal lcd(RS, E, d4, d5, d6, d7); 
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);


}

void loop() {

  // put your main code here, to run repeatedly:

second++;
if(second>=60)
{
  second=0;
  minutes=0;
  hours++;
  
}
if(hours>=24)
{
  second=0;
  minutes=0;
  hours=0;
}
lcd.clear();
lcd.setCursor(4,1);
lcd.print(hours);
lcd.print(":");
lcd.print(minutes);
lcd.print(":");
lcd.print(second);
delay(100);
}
