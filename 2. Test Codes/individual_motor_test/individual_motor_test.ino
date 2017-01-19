void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(115200);
  Serial.println("Motor Testing");
 
}

void loop() {
  Serial.println("Right");
  right_motor();
  delay(3000);
  Serial.println("Left");
  left_motor();
  delay(3000);
}

void forward()
{
  Serial.println("forward");
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}

void left_motor()
{
  Serial.println("Left Motor");
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}

void right_motor()
{
  Serial.println("Right Motor");
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
}
