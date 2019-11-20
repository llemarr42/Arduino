#include <Servo.h>
Servo myServo;
int angle = 0;
int echo = 6;
int trig = 7;
long duration, cm = 0;
void setup()
{
	Serial.begin(9600);
	pinMode(echo, INPUT);
	pinMode(trig, OUTPUT);
	myServo.attach(9);
}

void loop()
{
	/*
	Serial.print(cm);
	Serial.print("cm");
	Serial.println();
	delay(50);
	*/
	/*
	if (cm >= 50)
	{
	angle = angle + 10;
	}
	if (cm <= 49 and cm >= 20)
	{
	angle = angle + 5;
	}
	if (cm <= 19 and cm >= 5)
	{
	angle = angle + 1;
	}
	*/
	angle = map(cm, 0, 70, 0, 180);
	angle = constrain(angle, 0, 180);
	myServo.write(angle);
	Serial.println(angle);
}

int getdistance()
{
digitalWrite(trig, LOW);
	delayMicroseconds(5);
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);
	pinMode(echo, INPUT);
	duration = pulseIn(echo, HIGH);
	cm = (duration/2) / 29.1;
	return cm;
}

