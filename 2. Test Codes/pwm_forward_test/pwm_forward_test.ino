void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}
int speed_ = 0;
void loop() {
  // put your main code here, to run repeatedly:
/*  for(speed_ = 0; speed_ <= 255 ; speed_++)
  {
    forward(speed_);
    delay(100);
  }
  for(speed_ = 255; speed_ >=0 ; speed_--)
  {
    forward(speed_);
    delay(100);
  }
*/
 // forward(95);
  delay(2000);
  halt();
  delay(2000);
}

void forward(int value)
{

  digitalWrite(8, LOW);
  analogWrite(9, value);
  digitalWrite(2, LOW);
  analogWrite(3, value);
}

void halt()
{
  Serial.println("Stop");
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}
