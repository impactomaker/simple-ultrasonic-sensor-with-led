
#include <Ultrasonic.h>

#define TRIGGER_PIN  4
#define ECHO_PIN     5

int led=13;

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup()
{
	Serial.begin(9600);
	pinMode(led, OUTPUT);
}

void loop()
{
	float cmMsec;
	long microsec = ultrasonic.timing();

	cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

	Serial.print("MS: ");
	Serial.print(microsec);
	Serial.print("CM: ");
	Serial.println(cmMsec);
	delay(100);

	if (cmMsec <= 12) {
	    digitalWrite(led, HIGH);
	} else {
	    digitalWrite(led, LOW);
	}
}
