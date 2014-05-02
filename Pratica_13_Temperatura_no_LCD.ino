// Curso de Introdução a Sistemas Embarcados com Arduino
// ISA-ES - MAR-ABR/2014
// Prof. Felipe N. Martins
// www.nossosrobos.blogspot.com
//
// Prática 13 - Temperatura no LCD
// Objetivo: Medir temperatura e mostrar seu valor no LCD.
//
// Hardware adicionado:
// Sensor de temperatura LM35 no pino A0
// LCD (Liquid Cristal Display) baseado no CI HD 44780.
// 2 linhas, 16 colunas.
// Conexão do LCD:
// pino RS do LCD ao pino 12 do Arduino
// pino Enable do LCD ao 11 do Arduino
// pino D4 do LCD ao 5 do Arduino
// pino D5 do LCD ao 4 do Arduino
// pino D6 do LCD ao 3 do Arduino
// pino D7 do LCD ao 2 do Arduino
// pino R/W do LCD ao GND
// Trimpot de 10K: extremidades a +5V e GND. Cursor ao pino VO do LCD (pino 3)


#include <LiquidCrystal.h>
// inicializa bib. informando os pinos conectados:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int temp;
char grau = 223;  // simbolo de grau no LCD utilizado (pode variar de acordo com o modelo)

void setup() {
  lcd.begin(16, 2); // inicializa o LCD
  lcd.setCursor(0, 0);
  lcd.print("Temperatura:"); // mostra mensagem
}

void loop() {
  // coloca cursor na coluna 0, linha 0:
  lcd.setCursor(0, 1);
  temp = analogRead(A0)*0.44;
  lcd.print(temp);
  lcd.print(grau);
  lcd.print("C");
  delay(500);
}
