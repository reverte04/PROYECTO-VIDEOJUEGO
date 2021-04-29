// Incluimos la biblioteca 
#include <LiquidCrystal.h>
#include "sprites.h"
#include "scroll.h"

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
unsigned long tiempoTranscurrido = 0;
long interval = 200;
unsigned long tiempoAnterior = 0;
int posicionXjugador = 1;
int posicionYjugador = 1;
int posicionXpared1 = 15;
int posicionYpared1 = 1;
int val; 
const int BOTON = 9;
bool salto = false;
bool muerte = false;
bool mostrarPared1 = true;




 void setup() {

  pinMode(BOTON,INPUT);
  
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
      lcd.write(byte(5));
   delay(2000);
   lcd.clear();
   
}

void loop() {
  tiempoTranscurrido = millis();
  leerBoton();
  revisarEstadoDelJuego();
  if (muerte) {
    pantallaMuerte();
  }
  if (tiempoTranscurrido - tiempoAnterior > interval && !muerte) {

  actualizarPantallaDuranteElJuego();
  tiempoAnterior = tiempoTranscurrido;
  }
  
  
  }

void revisarEstadoDelJuego() {
   if(salto) {
  posicionYjugador=0;
 }
 else{
  posicionYjugador=1;
 }
 if ((posicionXjugador==posicionXpared1) && (posicionYjugador==posicionYpared1)) {
  muerte = true;
 }
 if (posicionXpared1 == -1)
 {
  mostrarPared1 = false;
 }
    
}

void leerBoton() {
    val=digitalRead(BOTON);
  if  (val==HIGH){
  salto = true;

  }
  else{
   salto = false;
  }
    
}

 void actualizarPantallaDuranteElJuego() {
 lcd.clear();

 lcd.setCursor(posicionXjugador, posicionYjugador);
 lcd.write(byte(0)); // este es el jugador

    if (mostrarPared1)
    {
     lcd.setCursor(posicionXpared1, posicionYpared1);
     lcd.write(byte(5)); // esta es la pared1
     posicionXpared1--;
    }
}
 void pantallaMuerte(){
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.write("GAME OVER");
   delay(100);
   revisarBotonReinicio();
 }

 
void revisarBotonReinicio() {
      val=digitalRead(BOTON);
  if  (val==HIGH){
  muerte = false;

  }
    
 }
  
