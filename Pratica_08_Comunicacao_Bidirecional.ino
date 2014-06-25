// Curso de Introdução a Sistemas Embarcados com Arduino
// Prof. Felipe N. Martins
// www.nossosrobos.blogspot.com
//
// Prática 8 - Comunicação Bidirecional
// Objetivo: fazer comunicação bidirecional entre o Arduino e o 
// computador. O Arduino solicita ao usuário que entre com um
// número entre 0 e 9 e apresenta a tabuada desse número.
//
// Hardware adicionado:
// 

int i, numero;
void setup() {
  Serial.begin(9600); 
}
void loop() {
  while (true) {
    Serial.print("Entre com um numero: "); 
    while (Serial.available()==0);    
    numero = Serial.read();     
      if (numero>='0' && numero<='9')
      Serial.println(numero-'0');        
    else {
      Serial.println("O valor deve ser numerico!");   
      continue;                                   
    }
    numero-='0'; 
    for (i = 0; i <= 10; i++) {                                        
      Serial.print(numero);
      Serial.print(" x ");
      Serial.print(i);
      Serial.print(" = ");
      Serial.println(numero*i);
    }
    Serial.println("");    
  }
}
