#include "NewPing.h"
int sagOnTriggerPin = 9;
int sagOnEchoPin = 10;

int sagArkaTriggerPin = 24 ;
int sagArkaEchoPin = 22;

int maxUzunluk=400;

NewPing sonar(sagOnTriggerPin,sagOnEchoPin,maxUzunluk);
NewPing sonar2(sagArkaTriggerPin,sagArkaEchoPin,maxUzunluk);
float duration, distance , distance2;  // duration=süre distance=mesafe

void setup() 
{
  pinMode(sagOnTriggerPin, OUTPUT);
  pinMode(sagOnEchoPin, INPUT);

  pinMode(sagArkaTriggerPin, OUTPUT);
  pinMode(sagArkaEchoPin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  sagOnSensor();
  //sagArkaSensor();
 
}

void sagOnSensor()
{

  distance = sonar.ping_cm();
  Serial.print("Yükseklik = ");
  
  if (distance >= 120 || distance <= 2) 
  {
 
    Serial.println("0 cm");
  }

  else 
  {
    
    Serial.print(distance);
    Serial.println("cm");


  }
  delay(50);
}

void sagArkaSensor()
{
  distance2 = sonar2.ping_cm();
  Serial.print("Yükseklik2 = ");
  
  if (distance2 >= 120 || distance2 <= 2) 
  {
 
    Serial.println("0 cm");
  }

  else 
  {
    
    Serial.print(distance2);
    Serial.println("cm");


  }
  delay(50);
}
