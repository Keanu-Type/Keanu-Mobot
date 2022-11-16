//motor one
int enA = 11;
int in1 = 10;
int in2 = 9;
// motor two
int enB = 3;
int in3 = 6;
int in4 = 5;
bool signalON = true;
bool signalOFF = false;

void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT); //POWER
  pinMode(enB, OUTPUT); //POWER
  pinMode(in1, OUTPUT); //DIRECTION A MOTOR A
  pinMode(in2, OUTPUT); //DIRECTION B MOTOR A
  pinMode(in3, OUTPUT); //DIRECTION C MOTOR B 
  pinMode(in4, OUTPUT); //DIRECTION C MOTOR B
}


int MotorHighLow(int ENABLE, int DISABLE){
  digitalWrite( ENABLE, HIGH);
  digitalWrite( DISABLE, LOW);
}


bool Motor(bool signal){
  if (signal==true){
    //set engine speed
    analogWrite(enA, 50);
    analogWrite(enB, 50);
    delay(5000);
  }else if(!signal){
    //turn off engine
    analogWrite(enA, 0);
    analogWrite(enB, 0);
    //turnoff all signals
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(2000);
  };
}

void loop()
{
  //----------------------------FORWARD-----------------------------//
  //MotorHighLow(HIGH_Pin, LOW_Pin);
  //MOTOR          ENABLE, DISABLE  
  MotorHighLow(in1, in2); //MOTOR A FORWARD
  MotorHighLow(in4, in3); //MOTOR B REVERSE
  //ENGINE ON
  Motor(signalON);
  //--------------------------STOP-----------------------------//
  //ENGINE OFF
  Motor(signalOFF);
  //--------------------------BACKWARD-------------------------------//
  MotorHighLow(in3, in4); //MOTOR B FORWARD
  MotorHighLow(in2, in1); //MOTOR A REVERSE
  Motor(signalON);
  //------------------------STOP-------------------------------------//
  Motor(signalOFF);
}

