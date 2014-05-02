// Curso de Introdução a Sistemas Embarcados com Arduino
// ISA-ES - MAR-ABR/2014
// Prof. Felipe N. Martins
// www.nossosrobos.blogspot.com
//
// Prática 4 - Leitura de Sinal Digial
// Objetivo: LED deve acender quando o botão for pressionado
// e apagar quando o botão estiver solto
//
// Hardware adicionado:
// Botão - pino 0 (lógica negativa)

int led_pin = 13;
int button_pin = 0;
int button_state = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_pin, OUTPUT); 
  pinMode(button_pin, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  button_state = digitalRead(button_pin);
  digitalWrite(led_pin, !button_state);
  delay(100);           
}
