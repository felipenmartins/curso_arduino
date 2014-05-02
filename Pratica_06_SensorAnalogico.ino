// Curso de Introdução a Sistemas Embarcados com Arduino
// ISA-ES - MAR-ABR/2014
// Prof. Felipe N. Martins
// www.nossosrobos.blogspot.com
//
// Prática 6 - Usando o sensor de luz
// Objetivo: acender o LED do pino 13 quando houver pouca luz 
// e apagar o mesmo LED quando houver muita luz.
//
// Hardware adicionado:
// LDR - um terminal ao +5V e o outro ao pino A0
// Resistor de 10kohms - um terminal ao pino A0 e o outro ao GND

int led_pin = 13;
int ldr_pin = A0;

void setup() { 
  pinMode(led_pin, OUTPUT); 
}

void loop() {
  if (analogRead(ldr_pin) >= 1000)
    digitalWrite(led_pin, HIGH);
  else
    digitalWrite(led_pin, LOW);
} 
