// Curso de Introdução a Sistemas Embarcados com Arduino
// ISA-ES - MAR-ABR/2014
// Prof. Felipe N. Martins
// www.nossosrobos.blogspot.com
//
// Prática 5 - Leitura de Sinal Digial
// Objetivo: cada vez que o botão for pressionado, o LED deve 
// ter seu estado invertido
//
// Hardware adicionado:
// Botão - pino 0
// Usa tecnica de debounce

int led_pin = 13;
int led_state = LOW;
int button_pin = 0;
int button_state;

// the setup routine runs once when you press reset:
void setup() { 
  pinMode(led_pin, OUTPUT); 
  pinMode(button_pin, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // Enquanto o botão não for pressionado, não faz nada.
  while (digitalRead(button_pin)!=0){
    delay(20);
  }
  // Depois que o botão é pressionado, aguarda ser solto
  while (digitalRead(button_pin)==0){
    delay(20);
  }
  // Atraso para aguardar oscilação de contato terminar
  delay(50);
  // Inverte o estado da variável led_state
  led_state = !led_state;
  // Copia variável led_state para o pino do LED
  digitalWrite(led_pin, led_state);
}
