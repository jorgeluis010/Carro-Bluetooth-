#include "SoftwareSerial.h"

int tx = 2;
int rx = 3;
int motorD = 7;
int motorE = 8;

SoftwareSerial bluetooth(2, 3);
 
int response;

void setup() {
  bluetooth.begin(9600);

  pinMode(motorD, OUTPUT);
  pinMode(motorE, OUTPUT);
}

void loop() {
  if (bluetooth.available() > 0) {
    response = bluetooth.read();
    
    switch (response) {
      case 'c':
        digitalWrite(motorD, HIGH);
      	digitalWrite(motorE, HIGH);
        break;
      case 'b':
        digitalWrite(motorD, HIGH);
      	digitalWrite(motorE, HIGH);
        break;
      case 'd':
        digitalWrite(motorD, HIGH);
      	digitalWrite(motorE, LOW);
        break;
      case 'e':
        digitalWrite(motorD, LOW);
      	digitalWrite(motorE, HIGH);
        break;
      default:
        bluetooth.print("teste");
        break;
    }
  }
}
