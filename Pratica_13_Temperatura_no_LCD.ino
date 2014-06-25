// Curso de Introdução a Sistemas Embarcados com Arduino
// Prof. Felipe N. Martins
// www.nossosrobos.blogspot.com
//
// Prática 13 - Temperatura no LCD
// Objetivo: Medir temperatura e mostrar seu valor no LCD.
// Mostrar a contagem de tempo na segunda linha do LCD.
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
char grau = 223;  // simbolo de grau no LCD
int hora=0, minuto=0, segundo=0;
int hora_dez, hora_un, minuto_dez, minuto_un;

void setup() {
  lcd.begin(16, 2); // inicializa o LCD
  lcd.setCursor(0, 0);
  lcd.print(" Intro Sistemas"); // mostra mensagem
  lcd.setCursor(0, 1);
  lcd.print("   Embarcados"); // mostra mensagem
  lcd.blink();
  delay(2000);
  lcd.clear();
  lcd.home();
}

void loop() {
  // coloca cursor na coluna 0, linha 0:
  lcd.setCursor(0, 0);
  temp = analogRead(A0)*0.44;
  lcd.print(temp);
  lcd.print(grau);
  lcd.print("C");

  // coloca cursor na coluna 0, linha 0:
  lcd.setCursor(0, 1);
  // mostra hora no LCD
  if (hora < 10)    // se hora < 10, inclui caractere "0"
    lcd.print('0');
  lcd.print(hora);
  lcd.print(":");
  if (minuto < 10)  // se minuto < 10, inclui caractere "0"
    lcd.print('0');
  lcd.print(minuto);
  lcd.print(":");
  if (segundo < 10)  // se segundo < 10, inclui caractere "0"
    lcd.print('0');
  lcd.print(segundo);
  
  // Contagem da hora:
  segundo++;         // incrementa segundo
  if (segundo > 59){ // se segundo > 59,
    minuto++;        // incrementa minuto e zera segundo
    segundo = 0;
  }
  if (minuto > 59){  // se minuto > 59,
    hora++;          // incrementa hora e zera minuto
    minuto = 0;
  }
  while (millis()%1000 !=0);  // fica em loop ate proximo segundo
}
