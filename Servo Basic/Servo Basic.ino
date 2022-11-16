#include <Servo.h>
Servo Rotate;
int degree;
//RED = 5V
//BROWN = GND
//ORANGE = any

void setup() {
  // put your setup code here, to run once:
  Rotate.attach(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<= 180; i++){
    Rotate.write(i);
    delay(5);
  }    
}
