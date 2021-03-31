#include <SoftwareSerial.h>
#include <Servo.h>
Servo servo;
SoftwareSerial s(5,6);
bool value = false;
bool openExit = false;
bool ir1, ir2;
void setup() {
  s.begin(9600);
  servo.attach(9);
  Serial.begin(9600);
  servo.write(5);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {

  if(s.available()>0) {
    value = s.read();
    Serial.println(digitalRead(3));
    bool open = false;
    if(value == false && open == false) {
      Serial.println("NO");
      servo.write(5);
    } else if(value == true && open == false && digitalRead(2) == false) {         
        open = true;
        servo.write(60);
    } else if(digitalRead(3) == false) {
        open = false;
        servo.write(5);
      }
  }
  
  delay(500);
}
