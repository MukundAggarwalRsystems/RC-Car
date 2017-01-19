/*
 * Component used in the code : 
 * 1. Ultrasonic Right
 * 2. Sharp IR
 * 
 * 1. find the obstacle on the right side
 * 2. turn left
 * 3. follow left track
 */

#define trigPin1 6
#define echoPin1 7
#define trigPin2 4
#define echoPin2 5

long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;

// Sharp IR Sensor
const int analogInPin = A0;  // Sharp IR sensor
int sharpIRsensorValue = 0;        // value read

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
  delay(2000);
}

void loop() {
  // 
  followTrack();
  
}

void obstacle()
{
  left();
  delay(1500);
//  smooth_forward(160);
  smooth_left(150);
  delay(700);
  while(1)  //RightSensor > 5)
  {
      followLeftTrack();
      RightSensor = SonarSensor(trigPin1, echoPin1);
  }
  Serial.println("Crossing the obstacle");
}

void followLeftTrack()
{
  RightSensor = SonarSensor(trigPin1, echoPin1);
  LeftSensor = SonarSensor(trigPin2, echoPin2);
  sharpIRsensorValue = analogRead(analogInPin);
  
  if(LeftSensor < 5 )
  {
    Serial.println("turn right");
//    Serial.print("Left Sensor Test : ");
//    Serial.println(LeftSensor);
    smooth_right(120);
//    delay(50);
  }else if(RightSensor >= 12 && RightSensor < 19)
  {
    Serial.println("turn left");
//    Serial.print("Right Sensor Test : ");
//    Serial.println(RightSensor);
    smooth_left(180);    
  }else if(RightSensor < 12 )
  {
    Serial.println("turn left");
//    Serial.print("Right Sensor Test : ");
//    Serial.println(RightSensor);
    smooth_left(150);    
  }else smooth_forward(160);
}
void followTrack()
{
  RightSensor = SonarSensor(trigPin1, echoPin1);
  LeftSensor = SonarSensor(trigPin2, echoPin2);
  sharpIRsensorValue = analogRead(analogInPin);
  
  if(RightSensor < 3 )
  {
    Serial.println("turn left");
//    Serial.print("Right Sensor Test : ");
//    Serial.println(RightSensor);
    left();
    delay(100);
  }
  else if(LeftSensor < 19 )
  {
    Serial.println("turn right");
//    Serial.print("Left Sensor Test : ");
//    Serial.println(LeftSensor);
    smooth_right(150);
    
  }
  else smooth_forward(160);

  if(sharpIRsensorValue > 300)
  {
    //halt();
    obstacle();
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
  v1 = value+50;
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
  v1 = value+50;
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
void left()
{
  digitalWrite(8, LOW);
  analogWrite(9, 0);
  digitalWrite(2, LOW);
  analogWrite(3, 180);
}

void right()
{
  digitalWrite(8, LOW);
  analogWrite(9, 180);
  digitalWrite(2, LOW);
  analogWrite(3, 0);
}
