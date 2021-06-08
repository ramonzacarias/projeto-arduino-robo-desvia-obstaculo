//motor1
int p10 = 10;
int p9 = 9;
int velMotor1 = 11;

//motor2
int p6 = 6;
int p5 = 5;
int velMotor2 = 3;

// Pino 12 irá receber o pulso do echo
int echoPino = 7;
// Pino 13 vai enviar o pulso para gerar o echo
int trigPino = 4;
long duracao = 0;
long distancia = 0;

void setup() {

  //motor1
  pinMode (p10, 1);
  pinMode (p9, 1);

  //motor2
  pinMode (p6, 1);
  pinMode (p5, 1);

  //Inicia a porta com velocidade de 9600 bits por segundos
  Serial.begin(9600);
  pinMode(echoPino, INPUT);
  pinMode(trigPino, OUTPUT);
  
  // Iniciar a velocidade dos motores
  pinMode(velMotor1, 1);
  pinMode(velMotor2, 1);

}

void loop() {
  
  // Pino trigger com um pulso baixo LOW(desligado)
  digitalWrite(trigPino, LOW);
  // Delay(atraso) de 10 microsegundos
  delayMicroseconds(10);
  // Pino trigger com pulso HIGH(ligado)
  digitalWrite(trigPino, HIGH);
  // Delay(atraso) de 10 microsegundos
  delayMicroseconds(10);
  // Pino trigger com um pulso baixo LOW
  // (desligado) novamente
  digitalWrite(trigPino, LOW);
  // A funcção pulseInt verifica o tempo que o pino ECHO ficou HIGH
  // calculando, desta forma, a duração do tráfego de sinal
  duracao = pulseIn(echoPino, HIGH);
  // cálculo: distancia = duracao/58
  distancia = duracao / 58;
  Serial.print("Distancia em cm: ");
  Serial.println(distancia);

  // Definindo a velocidade do motor 1 e motor 2, range entre (0 - 255);
  analogWrite(velMotor1, 230);
  analogWrite(velMotor2, 230);
  
  if(distancia <= 50){

    // Se o carro estiver a uma distancia menor ou igual a 50cm
    // O mesmo para e aguarda um determinado tempo para realizar a manobra
    
    //motor1
    digitalWrite (p10, 0);
    digitalWrite (p9, 0);

    //motor2
    digitalWrite (p6, 0);
    digitalWrite (p5, 0);

    delay(900); //Tempo que o carro vai aguardar

    //motor1
    digitalWrite (p10, 1); // ligar apenas um motor para realizar a manobra

    delay(900); //Tempo necessario para girar em 90 graus
    
    // Após o tempo necessario o carro segue em linha reta, ligando os dois motores
    //motor1
    digitalWrite (p10, 1);
    digitalWrite (p9, 0);

    //motor2
    digitalWrite (p6, 0);
    digitalWrite (p5, 1);
    
  }else{

    //motor1
    digitalWrite (p10, 1);
    digitalWrite (p9, 0);

    //motor2
    digitalWrite (p6, 0);
    digitalWrite (p5, 1);
     
  }

}
