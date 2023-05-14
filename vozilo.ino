/* BT KOMANDE
 *  1 - NAPRIJED
 *  2 - NAZAD
 *  3 - LIJEVO
 *  4 - DESNO
 *  0 - STOP
 *  + - UBRZANJE ZA 10
 *  - - USPORAVANJE ZA 10
 */


#include <AFMotor.h>
#include <SPI.h>
#include <Wire.h>

char bluetooth;
String smjer;
int brzina;

AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

void setup() {
  
  Serial.begin(9600);
  Serial.println("Motor test!");
 
  bluetooth = '0';
  brzina = 255;

  M1.setSpeed(brzina);
  M1.run(RELEASE);
  M2.setSpeed(brzina);
  M2.run(RELEASE);
  M3.setSpeed(brzina);
  M3.run(RELEASE);
  M4.setSpeed(brzina);
  M4.run(RELEASE);
  
}

void loop() {
  
  if (brzina > 255)brzina = 255;
  else if (brzina < 105)brzina = 110;

  M1.setSpeed(brzina);
  M2.setSpeed(brzina);
  M3.setSpeed(brzina);
  M4.setSpeed(brzina);

  bt();

}


void bt() {

  if (Serial.available() > 0)
  {
    bluetooth = Serial.read();

    if (bluetooth == '1' ) naprijed();
    if (bluetooth == '2') nazad();
    if (bluetooth == '3') lijevo();
    if (bluetooth == '4') desno();
    if (bluetooth == '0') Stop();
    if (bluetooth == '+' ) brzina = brzina + 10;
    if (bluetooth == '-' ) brzina = brzina - 10;
    
  }
}




void naprijed() {
  M1.setSpeed(brzina);
  M2.setSpeed(brzina);
  M3.setSpeed(brzina);
  M4.setSpeed(brzina);

  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);

  smjer = "Nazad";

}

void nazad() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
  
  M1.setSpeed(brzina);
  M2.setSpeed(brzina);
  M3.setSpeed(brzina);
  M4.setSpeed(brzina);

  smjer = "Naprijed";

}

void lijevo() {
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
  
  M1.setSpeed(brzina);
  M2.setSpeed(brzina);
  M3.setSpeed(brzina);
  M4.setSpeed(brzina);

  smjer = "Lijevo";

}

void desno() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);

  M1.setSpeed(brzina);
  M2.setSpeed(brzina);
  M3.setSpeed(brzina);
  M4.setSpeed(brzina);

  smjer = "Desno";
}
void Stop() {
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);

  smjer = "STOP";

}
