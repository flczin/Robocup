#include<Servo.h>
Servo arma;

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(A1, A0);

char comando = 0;

void setup() {
  bluetooth.begin(9600);
  arma.attach(A5);
  
  pinMode(2, INPUT_PULLUP);
  
  pinMode(3, OUTPUT);//ENA
  pinMode(4, OUTPUT);//IN1
  pinMode(5, OUTPUT);//IN2

  pinMode(11, OUTPUT);//ENB
  pinMode(12, OUTPUT);//IN3
  pinMode(13, OUTPUT);//IN4

  arma.write(0);
  parado();
}

void loop() {
  if (digitalRead(2) == 1) {
    arma.write(160);
  }
  if (digitalRead(2) == 0) {
    arma.write(0);
  }
  while (bluetooth.available()) {
    comando = bluetooth.read();

    if (comando == 'F') {
      frente();
    }
    else if (comando == 'B') {   // MOVIMENTO PARA TRAS
      tras();
    }
    else if (comando == 'L') {   // MOVIMENTO PARA ESQUERDA
      esquerda();
    }
    else if (comando == 'R') {   // MOVIMENTO PARA DIREITA
      direita();
    }
    else if (comando == 'I') { //DIREITA E FRENTE
      direitaF();
    }
    else if (comando == 'G') { //ESQUERDA E FRENTE
      esquerdaF();
    }
    else if (comando == 'H') { //ESQUERDA E TRAS
      esquerdaT();
    }
    else if (comando == 'J') { //DIREITA E TRAS
      direitaT();
    } else { // ALGUMA COISA NÃO ESPERADA
      parado();
    }
  }
}


void frente() {
  analogWrite(11, 220);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);

  analogWrite(3, 220);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void tras() {
  analogWrite(11, 220);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);

  analogWrite(3, 220);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void direita() {
  analogWrite(11, 180);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);

  analogWrite(3, 220);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void esquerda() {
  analogWrite(11, 220);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);

  analogWrite(3, 180);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void direitaF() {
  analogWrite(11, 90);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);

  analogWrite(3, 220);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void esquerdaF() {
  analogWrite(11, 220);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);

  analogWrite(3, 90);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);

}

void direitaT() {
  analogWrite(11, 90);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);

  analogWrite(3, 220);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void esquerdaT() {
  analogWrite(11, 220);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);

  analogWrite(3, 90);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);

}

void parado() {
  analogWrite(11, 0);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);

  analogWrite(3, 0);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}
