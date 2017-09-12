/* SG90 Camera Mount [B051] :  http://rdiot.tistory.com/281 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h> 

LiquidCrystal_I2C lcd(0x27,20,4);
Servo myservo1;
Servo myservo2;

int servoPin_updown = 12;
int servoPin_leftright = 11;

int pos_updown = 0;
int pos_leftright = 0;

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  myservo1.attach(servoPin_updown); 
  myservo2.attach(servoPin_leftright); 
  delay(1000);

  lcd.clear();
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("B051:SG90 Mount");

  for(pos_leftright = 0; pos_leftright < 180; pos_leftright += 1) 
  { 
    myservo2.write(pos_leftright);
    //lcd.setCursor(0,1);
    //lcd.print("pos0~179=" + (String)pos + "  " );
    delay(10); 
  }

  for(pos_leftright = 180; pos_leftright>=0; pos_leftright-=1)
  { 
    myservo2.write(pos_leftright); 
    //lcd.setCursor(0,2);
    //lcd.print("pos180~1=" + (String)pos + "  " );
    delay(10); 
  } 

  for(pos_updown = 80; pos_updown < 180; pos_updown += 1) 
  { 
    myservo1.write(pos_updown);
    //lcd.setCursor(0,1);
    //lcd.print("pos0~179=" + (String)pos + "  " );
    delay(10); 
  }

  for(pos_updown = 180; pos_updown>=80; pos_updown-=1)
  { 
    myservo1.write(pos_updown); 
    //lcd.setCursor(0,2);
    //lcd.print("pos180~1=" + (String)pos + "  " );
    delay(10); 
  } 
}
