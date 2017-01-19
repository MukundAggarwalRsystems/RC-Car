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
  Serial.println("Ultrasonic sensor test code");
  Serial.println("Please place Something in the range of the sensor");

}

void loop() {
SonarSensor(trigPin1, echoPin1);
RightSensor = distance;
//Serial.print("Right Sensor Test : ");
//Serial.println(RightSensor);
SonarSensor(trigPin2, echoPin2);
LeftSensor = distance;
//Serial.print("Left Sensor Test : ");
//Serial.println(LeftSensor);

Serial.print(LeftSensor);
Serial.print(" - ");
Serial.println(RightSensor);

delay(100);
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}
