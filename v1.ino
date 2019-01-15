#include <Blynk.h>
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(2, 3); // RX, TX
#define BLYNK_PRINT Serial
#include <BlynkSimpleStream.h>
#include <Servo.h>

char auth[] = "d8684a41039f4f838b5860b4f05813f0"; // type auth code here, keep ""
int button;
Servo servo;
BLYNK_WRITE(V0) {
  servo.write(param.asInt());
}

BLYNK_WRITE(V1) {
  button = param.asInt();
  if (button == 1) {
    servo.write(0);
  }
  else
    servo.write(90);
}
void setup() {
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
  servo.attach(8);
}

void loop() {

  Blynk.run(); // run blynk on a loop.

}
