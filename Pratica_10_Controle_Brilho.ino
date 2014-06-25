// Curso de Introdução a Sistemas Embarcados com Arduino
// Prof. Felipe N. Martins
// www.nossosrobos.blogspot.com
//
// Prática 10 - Controle de Brilho com PWM
// Objetivo: Ajustar o brilho do LED do pino 13 de acordo 
// com o valor lido na entrada analógica A2.
// O valor de brilho também é enviado pela serial.
//
// Hardware adicionado:
// A2 -> trimpot ou sensor LM35 (temperatura) ou LDR (luz) etc.

int brilho = 0;  // brilho do LED
int sensor; // valor do LDR

void setup() {
  pinMode(A2, INPUT); // pino do LDR: entrada A2
  pinMode(13, OUTPUT); // pino do LED: saida 13
  Serial.begin(9600);
}

void loop() {
  sensor = analogRead(A2); // le valor do LDR
  brilho = map(sensor, 0, 1023, 0, 255);
  Serial.println(brilho); // envia ao PC
  analogWrite(13, brilho); // aciona LED
  delay(30);
}
