#include<Servo.h>
Servo horizontal;//config for horizontal servo
int servoh=180;
int servoLimitHigh = 175;//when signal is high
int servoLimitLow =5;//when signal is low
// 65 degrees MAX

Servo vertical; //config for vertical servo
int servov =45;
int servovLimitHigh = 60;//when signal is high
int servovLimitLow =1;//when signal is low

//LDR pin connections 
//name = analogpin;
int ldrlt = A0;//LDR top left - bottom left <---BDG
int ldrld = A1;//LDR down left - top left
int ldrrt = A2;//LDR top right - bottom right
int ldrrd = A3;//LDR down right - top right

void setup(){
horizontal.attach(9);// attached the vertical and horizontal servo motors
vertical.attach(10);
horizontal.write(180);//set the servo rotation 
vertical.write(45);
delay(1000);
}

void loop(){
int lt = analogRead(ldrlt); //to read the value from the LDR top left
int rt = analogRead(ldrrt); //top right
int ld = analogRead(ldrld); //down left
int rd = analogRead(ldrrd); //down right
int dtime = 10;int tol =90; //dtime-diffrence time,tol-toleransi
int avt = (lt + rt) / 2; // avg value top
int avd = (ld + rd) / 2; //down
int avl = (lt + ld) / 2; //left
int avr = (rt + rd) / 2; //right
int dvert = avt - avd; // check the diff of up and down
int dhoriz = avl -avr;// check the diff of left and right

if (-1*tol > dvert || dvert > tol)
{
if (avt > avd)
{
servov = ++servov;
if (servov > servovLimitHigh)
   {servov = servovLimitHigh;}
}
else if (avt < avd)
{servov= --servov;
if (servov < servovLimitLow)
{ servov = servovLimitLow;}
}
vertical.write(servov); // TO LOOP the PRoGram and to cal the avg value of resp LDR 
}
if (-1*tol > dhoriz || dhoriz > tol) // check id the diff is in the tolerance else channge horizontal angle
{
if(avl > avr)
{
servoh = --servoh;
if (servoh < servovLimitLow)
{
servoh = servovLimitLow;
}
}
else if (avl < avr)
{
servoh = ++servoh;
if(servoh > servovLimitHigh)
{
servoh = servovLimitHigh;
}
}
else if (avl = avr)
{
delay(1000);
}
horizontal.write(servoh);
}
delay(dtime);
}
