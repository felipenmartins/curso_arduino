// Curso de Introdução a Sistemas Embarcados com Arduino
// Prof. Felipe N. Martins
// www.nossosrobos.blogspot.com
//
// Prática 15 - Comunicação entre Arduinos
// Objetivo: Realizar comunicação de dados entre duas placas Arduino (placa A
// e placa B) através da porta serial. As duas placas tem o mesmo hardware: 
// um botão e um LED. Ao clicar no botão de uma das placas o estado do LED da 
// outra placa é invertido. Ao soltar o botão, o LED volta ao estado anterior.
//
// Hardware adicionado:
// Botao: um terminal ao pino 7 e o outro ao GND.
// Comunicação: pino RX da placa A ligado ao pino TX da placa B
//              pino TX da placa A ligado ao pino RX da placa B

int led = 13;
int botao = 7;
int valor = HIGH;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop(){
  if (Serial.available()){
    if (Serial.read() == 'L')
      digitalWrite(led,HIGH);
    else
      digitalWrite(led,LOW);
  }
  delay(100);
  if (valor!=digitalRead(botao)){
    valor = digitalRead(botao);
    if (valor==HIGH)
      Serial.print('L');
    else
      Serial.print('D');  
  }
  delay(100);
}
