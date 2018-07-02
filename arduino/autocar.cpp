// motor 1
int enA = 10;
int in1 = 9;
int in2 = 8;
//motor 2
int enB = 5;
int in3 = 7;
int in4 = 6;
// ultrasonic sensor
int ECPin = 2;
int TrigPin = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ECPin, INPUT);
  pinMode(TrigPin, OUTPUT);
}

void loop()
{
  if (distance() > 30)
  {
    DriveStraight();
  }
  else
  {
    TurnLeft();
  }
}

void DriveStraight()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);
}

void TurnLeft()
{

}

void Stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}

long distance()
{
  long duration, distance;
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  duration = pulseIn(ECPin, HIGH);
  distance = (duration/2)/29.1;
  return distance;
}
