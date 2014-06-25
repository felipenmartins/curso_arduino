// Curso de Introdução a Sistemas Embarcados com Arduino
// Prof. Felipe N. Martins
// www.nossosrobos.blogspot.com
//
// Prática 2 - Codigo Morse
// Objetivo: Usar o LED do pino 13 para emitir SOS em código Morse
// S = ...
// O = ---

int led = 13;

void ponto(){
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW); 
  delay(100);
}

void traco(){
  digitalWrite(led, HIGH);
  delay(400);
  digitalWrite(led, LOW);  
  delay(100);
}

void S(){
  ponto();
  ponto();
  ponto();
}

void O(){
  traco();
  traco();
  traco();
}

void setup() {                
  pinMode(led, OUTPUT); 
}

// the loop routine runs over and over again forever:
void loop() {
  S();
  delay(300);
  O();
  delay(300);
  S();  
  delay(700);
}
