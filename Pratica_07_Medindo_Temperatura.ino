// Curso de Introdução a Sistemas Embarcados com Arduino
// Prof. Felipe N. Martins
// www.nossosrobos.blogspot.com
//
// Prática 7 - Medindo Temperatura
// Objetivo: fazer a leitura do valor obtido por um sensor de
// temperatura e enviá-lo ao computador via porta USB
//
// Hardware adicionado:
// Sensor de temperatura TMP36 - pino A0

float temperatura;

void setup() {
  Serial.begin(9600);
}
void loop() {
  int sensor = analogRead(A0);
  temperatura = (float)sensor * 0.45;
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println("C.");  
  delay(500);
}
