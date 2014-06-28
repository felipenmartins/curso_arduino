// Curso de Introdução a Sistemas Embarcados com Arduino
// Prof. Felipe N. Martins
// www.nossosrobos.blogspot.com
//
// Prática 12 - Dados no LCD
// Objetivo: Mostrar no LCD a contagem de segundos desde a 
// energização do Arduino.
//
// Hardware adicionado:
// LCD (Liquid Cristal Display) baseado no CI HD 44780.
// 2 linhas, 16 colunas.
// Conexão do LCD:
// pino RS do LCD ao pino 12 do Arduino
// pino Enable do LCD  pin to digital pin 11 do Arduino
// pino D4 do LCD pin to digital pin 5 do Arduino
// pino D5 do LCD  pin to digital pin 4 do Arduino
// pino D6 do LCD  pin to digital pin 3 do Arduino
// pino D7 do LCD  pin to digital pin 2 do Arduino
// pino R/W do LCD ao GND
// Trimpot de 10K: extremidades a +5V e GND. Cursor ao pino VO do LCD (pino 3)

//  This example code is in the public domain.
// http://www.arduino.cc/en/Tutorial/LiquidCrystal


#include <LiquidCrystal.h>
// inicializa bib. informando os pinos conectados:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); // inicializa o LCD
  lcd.print("hello, world!"); // mostra mensagem
}

void loop() {
  // coloca cursor na coluna 0, linha 1:
  lcd.setCursor(0, 1);
  // mostra numero de segundos desde o reset:
  lcd.print(millis()/1000);
  delay(100);
}
