/*
 
 1/4 inch increments to mm:
	0 -	0
	1 -	6.35
	2 -	12.7
	3 -	19.05
	4 -	25.4
	5 -	31.75
	6 -	38.1
	7 -	44.45
	8 - 50.8
 */

#include <Arduino.h>

#define BIT_5 2
#define BIT_4 3
#define BIT_3 4
#define BIT_2 5
#define BIT_1 6
#define BIT_0 7

#define BIT_GO 9

void delaySafeMilli(unsigned long timeToWait) {
	unsigned long start_time = millis();
	while (millis() - start_time <= timeToWait) {}
}

void setBinaryOutput(int instruction_index) {
	digitalWrite(BIT_5, 0B100000 & instruction_index);
	digitalWrite(BIT_4, 0B010000 & instruction_index);
	digitalWrite(BIT_3, 0B001000 & instruction_index);
	digitalWrite(BIT_2, 0B000100 & instruction_index);
	digitalWrite(BIT_1, 0B000010 & instruction_index);
	digitalWrite(BIT_0, 0B000001 & instruction_index);
}

void setup() {
	for (int i = 2; i <= 7; ++i) {
		pinMode(i, OUTPUT);
	}

	pinMode(BIT_GO, OUTPUT);
}

void loop() {
	for (int i = 0; i <= 7; ++i) {
		delaySafeMilli(250);
		setBinaryOutput(i);
		delaySafeMilli(500);
		digitalWrite(BIT_GO, HIGH);
		delaySafeMilli(3500);
		digitalWrite(BIT_GO, LOW);
	}

	for (int i = 2; i <= 7; ++i) {
		digitalWrite(i, LOW);
	}
	
}
