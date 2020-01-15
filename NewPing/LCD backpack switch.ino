// LCD backpack.ino
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display.
// If 0x27 doesn't work, try 0x3F.
int previous = LOW;
int time = 0;
int buttonPin = 11;
int buttonState = 0;
int switchState = 0;

void setup()
{
	// put your setup code here, to run once.
	Serial.begin(9600);
	pinMode(4, INPUT);
	pinMode(buttonPin, INPUT);
	lcd.init();
	lcd.setBacklight(HIGH);
	lcd.setCursor(0, 0);
	lcd.print("Hello World");
}

void loop()
{
	// put your main code here, to run repeatedly:
	buttonState = digitalRead(buttonPin);
	switchState = digitalRead(4);
	
	lcd.setCursor(0, 1);
	lcd.print(time);
	if (buttonState == HIGH && previous == LOW)
	{
		if (switchState == HIGH){
			(time = time + 1);
			// Serial.println('1');
		}
		if (switchState == LOW)
		{
			(time = time - 1);
			// Serial.println('0');
		}
	}
	Serial.println(digitalRead(4));
	previous = buttonState;
} 
