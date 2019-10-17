#include<Servo.h>
int trigPin=2;
int echoPin=3;

long duration;
int distance;
Servo servo;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  servo.attach(9);
}

void loop()
{
  for(int i=15;i<=165;i++)
  {
    servo.write(i);
    distance=calculateDistance();
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.println(".");
  }

  for(int i=165;i>15;i--)
  {
    servo.write(i);
    delay(50);
    distance=calculateDistance();
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.println(".");
  }

}

int calculateDistance()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin,LOW);
  
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  return distance;
}  
