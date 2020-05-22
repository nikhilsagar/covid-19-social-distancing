#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define trigPin1 8
#define echoPin1 9
#define trigPin2 6
#define echoPin2 7

int ALARM = 10;
long duration, distance, Sensor1,Sensor2, distanceCm, distanceInch, distanceft ;
void setup()
{
lcd.begin(16,2);
Serial.begin (9600);
lcd.clear(); 
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(ALARM, OUTPUT);
digitalWrite(ALARM, LOW);
lcd.clear();
}

void loop() 
{
/////////////////////////////////////////////////////// 
sonic(trigPin1, echoPin1);
Sensor1 = distanceft;
sonic(trigPin2, echoPin2);
Sensor2 = distanceft;

/////////////////////////////////////////////////////////////
digitalWrite(ALARM, LOW);
lcd.setCursor(0,0);lcd.print("S1:");lcd.setCursor(4,0);lcd.print(Sensor1);
lcd.setCursor(9,0);lcd.print("S2:");lcd.setCursor(12,0);lcd.print(Sensor2);
delay(1000);lcd.clear();
///////////////////////////////////////////////////////
if((Sensor1 <= 3)) 
{digitalWrite(ALARM, HIGH);delay(500);}
///////////////////////////////////////////////////////
if((Sensor2 <= 3) ) 
{digitalWrite(ALARM, HIGH);delay(500);}
///////////////////////////////////////////////////////
}
/////////////////////////////////////////////////////////////////////////////////
void sonic(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
distanceft =distanceInch/12;
}
