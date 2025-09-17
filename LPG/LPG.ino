#include <LiquidCrystal.h>
LiquidCrystal lcd(1,2,4,5,6,7);

int GAS_VAL = 0;

void setup()
{
  pinMode(A0,INPUT); // MQ-6 A0 Pin
  lcd.begin(16,2);
  pinMode(12,OUTPUT); // LED Green
  pinMode(13,OUTPUT); // LED Red
  pinMode(8,OUTPUT); // buzzer
  Serial.begin(9600);
  
  digitalWrite(2,HIGH);
  lcd.setCursor(0,0);
  lcd.print("   GAS SENSOR  ");
 
}

void loop()
{
  GAS_VAL = analogRead(A0);
  Serial.println(GAS_VAL);
  if (GAS_VAL > 700)
  {
    lcd.setCursor(0,1);
    lcd.print("  LPG Detected    ");
    digitalWrite(13,HIGH); //green
    digitalWrite(8,HIGH);
    delay(300);
    digitalWrite(13,LOW);
    digitalWrite(8,LOW);
    delay(300);
  
 }
  
else
{
  lcd.setCursor(0,1);
  lcd.print("LPG Not Detected    ");
  digitalWrite(12,HIGH);
  
}
  
delay(10); 
}