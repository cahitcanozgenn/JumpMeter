#include "NewPing.h"
#include <LiquidCrystal_I2C.h>

#include <Wire.h>

LiquidCrystal_I2C lcdekranim(0x27,16,2);

int SagTg = 9; 
int SagEC = 10;  

int SolTG = 5; 
int SolEC = 6;  

int SagOnTg = 12; 
int SagOnEC = 11;  

int SolOnTG = 4; 
int SolOnEC = 3;  

int SolUzunluk = 400;
int SagUzunluk = 400;

int SolOnUzunluk = 400;
int SagOnUzunluk = 400;
NewPing sol(SolTG,SolEC,SolUzunluk);
NewPing sag(SagTg,SagEC,SagUzunluk);
NewPing solOn(SolOnTG,SolOnEC,SolOnUzunluk);
NewPing sagOn(SagOnTg,SagOnEC,SagOnUzunluk);
///arka
int SagSensor()
{
return sag.ping_cm();
}
int SolSensor()
{
return sol.ping_cm();
}

///Ön
int SagOnSensor()
{
return sagOn.ping_cm();
}
int SolOnSensor()
{
return solOn.ping_cm();
}

void setup() {
  pinMode(SagTg, OUTPUT); 
  pinMode(SagEC,INPUT); 

  pinMode(SolTG, OUTPUT); 
  pinMode(SolEC,INPUT);
  Serial.begin(9600);
  Serial.println("Başladı");

  lcdekranim.init();
  lcdekranim.backlight();
  lcdekranim.setCursor(0,0);
  lcdekranim.print("Ziplama Olcer");
  delay(1000);
  lcdekranim.clear();
}

int maxSag = 0;
int maxSol = 0;
int maxSagOn = 0;
int maxSolOn = 0;


void loop() {
int sol = SolSensor();
int sag = SagSensor();

int solOn = SolOnSensor();
int sagOn = SagOnSensor();



delay(100);
//Serial.println();
//Serial.println();
Serial.print("Sol Arka: ");
Serial.print(sol);
Serial.print("  Sag Arka: ");
Serial.print(sag);
Serial.print("  Sol Ön: ");
Serial.print(solOn);
Serial.print("  Sag Ön: ");
Serial.print(sagOn);
Serial.println();
//Serial.println();


if (sag >= maxSag){
  maxSag = sag;
  }
if (sol >= maxSol){
maxSol = sol;
}
if (sagOn >= maxSagOn){
  maxSagOn = sagOn;
  }
if (solOn >= maxSolOn){
maxSolOn = solOn;
}

  lcdekranim.setCursor(0,0);
 lcdekranim.print("SagAr:");
  lcdekranim.setCursor(6,0);
 lcdekranim.print(maxSag);
 
  lcdekranim.setCursor(10,0);
 lcdekranim.print("On:");
  lcdekranim.setCursor(13,0);
 lcdekranim.print(maxSagOn);
 
 lcdekranim.setCursor(0,1);
 lcdekranim.print("SolAr:");
  lcdekranim.setCursor(6,1);
 lcdekranim.print(maxSol);

   lcdekranim.setCursor(10,1);
 lcdekranim.print("On:");
  lcdekranim.setCursor(13,1);
 lcdekranim.print(maxSagOn);

 
Serial.print("Max Sağ Arka Deger: ");
Serial.print(maxSag);
Serial.print(" Max Sol Arka Deger: ");
Serial.print(maxSol);
Serial.println();
Serial.print("Max Sağ Ön Deger: ");
Serial.print(maxSagOn);
Serial.print(" Max Sol Ön Deger: ");
Serial.print(maxSolOn);
Serial.println();

}
