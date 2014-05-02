// Curso de Introdução a Sistemas Embarcados com Arduino
// ISA-ES - MAR-ABR/2014
// Prof. Felipe N. Martins
// www.nossosrobos.blogspot.com
//
// Prática 14 - Relógio na Serial (para simulador)
// Objetivo: Usar o Serial Monitor para mostrar a hora atual (hora, minutos e segundos). O ajuste
// da hora inicial é feito pelo computador e enviado pela porta serial.
//
// Para utilização no simulador: http://123d.circuits.io/
// Hardware adicionado:
// Potenciômetro com cursor no pino A0 (para simular o sinal de temperatura)

int temp;
int ajuste_hora = false;
int hora, minuto, segundo;
int hora_dez, hora_un, minuto_dez, minuto_un;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(900);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(900);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(100);
}

void ajusteHora(){
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
}

void loop() {
  Serial.print("Temperatura:"); // mostra mensagem
  temp = analogRead(A0)*0.46;
  Serial.print(temp);
  Serial.println("C");
  // mostra numero de segundos desde o reset:
  Serial.println("Ajuste a hora.");

  while (ajuste_hora==false){
    ajusteHora();
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
      Serial.println("Hora ajustada.");
    }
    else
      Serial.println("Tente novamente.");
  }

  while(1){
    // coloca cursor na coluna 0, linha 0:
    Serial.print("Temperatura:"); // mostra mensagem
    temp = analogRead(A0)*0.43;
    Serial.print(temp);
    Serial.println("C");

    if (hora < 10)
      Serial.print('0');
    Serial.print(hora);
    Serial.print(":");
    if (minuto < 10)
      Serial.print('0');
    Serial.print(minuto);
    Serial.print(":");
    if (segundo < 10)
      Serial.print('0');
    Serial.println(segundo);
    
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
    
    while (millis()%1000 !=0);
  }
}
