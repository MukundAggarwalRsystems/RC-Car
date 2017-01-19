/*
 * Component used in the code : 
 * 1. Ultrasonic Right
 * 2. Sharp IR
 * 
 * 1. This code will allow the bot to trace the Wall on the right side of the bot and follow it at the distance of 15 cm.
 * 2. Through Sharp IR bot will always look for any obstacle in the front and stops if the hurdle comes near the bot.
 */

#define trigPin1 6
#define echoPin1 7
#define trigPin2 4
#define echoPin2 5

long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;

// Sharp IR Sensor
const int analogInPin = A0;  // Sharp IR sensor
int sensorValue = 0;        // value read

void setup() {
  // Motor pins
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  Serial.begin (115200);

  // Ultrasonic Pins
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Serial.println("Start");
}

void loop() {
  // 
  RightSensor = SonarSensor(trigPin1, echoPin1);
  LeftSensor = SonarSensor(trigPin2, echoPin2);
  sensorValue = analogRead(analogInPin);
  if(RightSensor < 15)
  {
    smooth_left(150);
    
  }
  else if(RightSensor > 15 && RightSensor <= 30 )
  {
    smooth_right(150);
    
  }
  else if(RightSensor > 30)
  {
    smooth_right(150);
  }
  else smooth_forward(160);

  if(sensorValue > 500)
  {
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

void smooth_forward(int value)
{
  digitalWrite(8, LOW);
  analogWrite(9, value);
  digitalWrite(2, LOW);
  analogWrite(3, value);
}
void forward()
{
  digitalWrite(8, LOW);
  analogWrite(9, 255);
  digitalWrite(2, LOW);
  analogWrite(3, 255);
}
void halt()
{
  Serial.println("Stop");
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}

void smooth_right(int value)
{
  int v1, v2;
  v1 = value+30;
  v2 = value;
  if(v1 > 255)
    v1 = 255;
  if(v2 > 255)
    v2 = 255;
  digitalWrite(8, LOW);
  analogWrite(9, v1);
  digitalWrite(2, LOW);
  analogWrite(3, v2);
}

void smooth_left(int value)
{
  int v1, v2;
  v1 = value+30;
  v2 = value;
  if(v1 > 255)
    v1 = 255;
  if(v2 > 255)
    v2 = 255;
  digitalWrite(8, LOW);
  analogWrite(9, v2);
  digitalWrite(2, LOW);
  analogWrite(3, v1);
}

