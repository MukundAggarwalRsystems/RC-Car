#define trigPin1 6
#define echoPin1 7
#define trigPin2 4
#define echoPin2 5


long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;

void setup()
{
  Serial.begin (115200);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {
RightSensor = SonarSensor(trigPin1, echoPin1);

LeftSensor = SonarSensor(trigPin2, echoPin2);
Serial.print(RightSensor);
Serial.print(" - ");
Serial.println(LeftSensor);
  if(LeftSensor > 3 && LeftSensor<6 && RightSensor>= 32 && RightSensor <= 34)
  {
    Serial.print("forward");
    forward();
  }else
  {
    Serial.print("halt");
    halt();
  }
}

int SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
return distance;
}

void forward()
{
//  Serial.println("Forward");
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void halt()
{
  Serial.println("Stop");
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}

void right()
{
//  Serial.println("Right");
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}
