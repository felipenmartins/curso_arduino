// Curso de Introdução a Sistemas Embarcados com Arduino
// Prof. Felipe N. Martins
// www.nossosrobos.blogspot.com
//
// Prática 14 - Relógio no LCD com ajuste pela Serial
// Objetivo: Usar o LCD para mostrar a hora atual (hora, minutos e segundos). O ajuste
// da hora inicial é feito pelo computador e enviado pela porta serial.
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
#include "pitches.h"

// notes in the melody:
int melody[] = {NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4, 8, 8, 4,4,4,4,4};

// inicializa bib. informando os pinos conectados:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int temp;
char grau = 223;  // simbolo de grau no LCD
int ajuste_hora = true;
int hora=0, minuto=0, segundo=0;
int hora_dez, hora_un, minuto_dez, minuto_un;

void setup() {
  lcd.begin(16, 2); // inicializa o LCD
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("Ajuste hora via");
  lcd.setCursor(0, 1);
  lcd.print("Serial Monitor");
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000/noteDurations[thisNote];
    tone(10, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(10);
  }
  delay(1000);
  lcd.clear();
}

void ajusteHora(){
  while (ajuste_hora==false){
    Serial.flush();  // apaga dados do buffer Serial
    Serial.println("Digite a hora no formato HH");
    while(Serial.available()==0);
    hora_dez = (Serial.read()-'0')*10;
    while(Serial.available()==0);
    hora_un = Serial.read()-'0';
    hora = hora_dez + hora_un;
    Serial.println("Digite os minutos no formato MM");
    while(Serial.available()==0);
    minuto_dez = (Serial.read()-'0')*10;
    while(Serial.available()==0);
    minuto_un = Serial.read()-'0';
    minuto = minuto_dez + minuto_un;
    Serial.print("Hora digitada: ");
    if (hora_dez == 0)
      Serial.print('0');
    Serial.print(hora);
    Serial.print(":");
    if (minuto_dez == 0)
      Serial.print('0');
    Serial.println(minuto);
    Serial.flush();
    Serial.println("Confirma? (S/N)");
    while(Serial.available()==0);
    if (Serial.read()=='S' || Serial.read()=='s'){
      ajuste_hora = true;
      Serial.print("Hora ajustada.");
    }
    else
      Serial.println("Tente novamente.");
  }
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Temperatura:"); // mostra mensagem
  temp = analogRead(A0)*0.48;
  lcd.print(temp);
  lcd.print(grau);
  lcd.print("C");

  if (ajuste_hora==false)
    ajusteHora();

  // coloca cursor na coluna 0, linha 1:
  lcd.setCursor(0,1);
  if (hora < 10)
    lcd.print('0');
  lcd.print(hora);
  lcd.print(":");
  if (minuto < 10)
    lcd.print('0');
  lcd.print(minuto);
  lcd.print(":");
  if (segundo < 10)
    lcd.print('0');
  lcd.print(segundo);
  
  // Contagem da hora:
  segundo++;
  if (segundo > 59){
    minuto++;
    segundo = 0;
  }
  if (minuto > 59){
    hora++;
    minuto = 0;
  }
  
  while(Serial.available()>0){
    ajuste_hora = false;
    hora_dez = Serial.read();
  }
   
  while (millis()%1000 !=0);

}
