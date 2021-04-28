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
  B10101,
  B01110,
  B01110,
  B01110,
  
};

byte pared2[8] = {
   B11111,
  B01110,
  B01110,
  B10101,
  B00000,
  B00000,
  B00000,
  
};

byte luna[8] = {
  B10001,
  B01110,
  B01110,
  B10001,
  B00000,
  B00000,
  B00000,
};

byte pared3[8] = {
  B11111,
  B01110,
  B01110,
  B10101,
  B00000,
  B00000,
  B00000,
  
};

byte pared4[8] = {
  B00000,
  B00000,
  B00000,
  B10101,
  B01110,
  B01110,
  B01110,
  
};

byte pared5[8] = {
  B11111,
  B01110,
  B01110,
  B10101,
  B00000,
  B00000,
  B00000,
  
};


byte pared6[8] = {
  B00000,
  B00000,
  B0000,
  B10101,
  B01110,
  B01110,
  B01110,
  
};


 void setup() {

  lcd.createChar(0, player1);
  lcd.createChar(1, pared1);
  lcd.createChar(2, pared2);
  lcd.createChar(3, luna);
  lcd.createChar(4, pared3);
  lcd.createChar(5, pared4);
  lcd.createChar(6, pared5);
  lcd.createChar(7, pared6);
  
  lcd.begin(16, 2);  
   lcd.setCursor(0, 1);
  lcd.write(byte(0)); // este es el jugador
    lcd.setCursor(2, 1); // esta es la piedra numero 1 
   lcd.write(byte(1));
    lcd.setCursor(4, 0); // esta es la piedra numero 2
    lcd.write(byte(2));
     lcd.setCursor(15, 0); // este es el sol 
     lcd.write(byte(3));
     lcd.setCursor(6, 0); // esta es la piedra numero 3
      lcd.write(byte(4));
     lcd.setCursor(8, 1); // esta es la piedra numero 4 
      lcd.write(byte(5));
     lcd.setCursor(10, 0); // esta es la piedra numero 5 
      lcd.write(byte(6));
     lcd.setCursor(12, 1); // esta es la piedra numero 6 
      lcd.write(byte(7));
   
   
}

void loop() {}
  
