void setup() {
  // put your setup code here, to run once:
 pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(115200);
}

void loop() {
 Serial.println("Motor Testing");
 forward();
}

void forward()
{
  Serial.println("Forward");
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}

void backward()
{
  Serial.println("Backward");
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
}

void right()
{
  Serial.println("Right");
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}
void sharp_right()
{
  Serial.println("Right");
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
}
void left()
{
  Serial.println("Right");
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
}

void sharp_left()
{
  Serial.println("Right");
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
}

void halt()
{
  Serial.println("Stop");
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}
