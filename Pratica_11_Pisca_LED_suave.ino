// Curso de Introdução a Sistemas Embarcados com Arduino
// Prof. Felipe N. Martins
// www.nossosrobos.blogspot.com
//
// Prática 11 - Controle de Brilho com PWM
// Objetivo: Piscar o LED do pino 13 suavemente usando PWM.
//
// Hardware adicionado:


int brilho = 0; // brilho do LED
int variacao = 5; // quanto varia o brilho

void setup() { 
  pinMode(13, OUTPUT);
} 

void loop() { 
  analogWrite(13, brilho); 
  brilho = brilho + variacao;
  if (brilho == 0 || brilho == 255) {
    variacao = -variacao; 
  } 
  delay(30); 
}
