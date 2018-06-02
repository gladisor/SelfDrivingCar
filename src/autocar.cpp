#define TRISTANS_USELESS_DEFINE 1

int LeftMotor = 12;
int RightMotor = 13;
int ECPin = 1;
int TrigPin = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(LeftMotor, INPUT);
  pinMode(RightMotor, INPUT);
  pinMode(ECPin, INPUT);
  pinMode(TrigPin, OUTPUT);
}

void loop()
{
  distance();
  if (distance > 30)
  {
    DriveStraight();
  }
  else
  {
    Stop();
    TurnRight();
    if (distance > 30)
    {
      DriveStraight();
    }
    else
    {
      TurnLeft();
      TurnLeft();
      if (distance > 30)
      {
        DriveStraight();
      }
      else
      {
        Stop();
      }
    }
  }
}

void DriveStraight()
{
  digitalWrite(LeftMotor, HIGH);
  digitalWrite(RightMotor, HIGH);
  delayMicroseconds(500);
  Stop();
}

void TurnRight()
{
  digitalWrite(LeftMotor, HIGH);
  digitalWrite(RightMotor, LOW);
  delayMicroseconds(500);
  Stop();
}

void TurnLeft()
{
  digitalWrite(LeftMotor, LOW);
  digitalWrite(RightMotor, HIGH);
}

void Stop()
{
  digitalWrite(LeftMotor, LOW);
  digitalWrite(RightMotor, LOW);
}

long distance()
{
  long duration, distance;
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  duration = pulseIn(ECPin, LOW);
  distance = (duration/2)/29.1;
  return distance;
}
