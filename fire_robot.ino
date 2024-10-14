#include <Servo.h>            //include servo.h library
Servo myservo; 
int pos = 0;    
boolean fire = false;
#define Left 4          // left sensor
#define Right 5         // right sensor
#define Forward 6       //front sensor
#define GAS_SENSOR 7    //Gas sensor
#define LM1 8           // left motor
#define LM2 9           // left motor
#define RM1 10          // right motor
#define RM2 11          // right motor
#define pump 12         //water pumb
void setup()
{ 
  Serial.begin(9600);
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);
  pinMode(GAS_SENSOR, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);
  digitalWrite(12,HIGH);
  myservo.attach(13);
  myservo.write(90); 
  
}
void put_off_fire()
{
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    digitalWrite(pump,LOW);
    delay(500);
    for (pos = 50; pos <= 110; pos += 1) 
    { 
    myservo.write(pos); 
    delay(10);  
    }
    for (pos = 110; pos >= 50; pos -= 1) 
    { 
    myservo.write(pos); 
    delay(10);
    }
    digitalWrite(pump,HIGH);
    myservo.write(90); 
    fire=false;
}

void loop()
{
  myservo.write(90);
  
    if (digitalRead(Left) ==1 && digitalRead(Right)==1 && digitalRead(Forward) ==1) 
    {
    delay(500);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    }
    else if(digitalRead(Forward) ==0) 
    {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    fire = true;
    }
    else if (digitalRead(Left) ==0)
    {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    }
    else if (digitalRead(Right) ==0) 
    {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    }
    delay(400);//change this value to change the distance
    
     if(digitalRead(GAS_SENSOR)== 0)
    {
     Serial.println("Gas is Detected.");
    }
     while (fire == true)
     {
      put_off_fire();
      Serial.println("Fire Detected.");
     }
}