// Incluimos la biblioteca 
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte player1[8] = {
  B01110,
  B11111,
  B01110,
  B11111,
  B11111,
  B01110,
  B01110,
};

byte pared1[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B01110,
  B01110,
  B01110,
  
};

 void setup() {

  lcd.createChar(0, player1);
  lcd.createChar(1, pared1);
  lcd.begin(16, 2);  
   lcd.setCursor(0, 1);
  lcd.write(byte(0));
   lcd.setCursor(2, 1);
   lcd.write(byte(1));
   
   
}

void loop() {}
  
