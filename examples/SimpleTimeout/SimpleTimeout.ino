/*
 * SimpleTimeout class
 * 
 * @autor: Thomas Winkler
 * @copyright: 2019-11-17
 * @lizence: CC0
 */


#include "simpletimeout.h"


SIMPLETIMEOUT timeout1;
SIMPLETIMEOUT timeout2;


void setup(void) {

	Serial.begin(115200);

	timeout1.begin(2000);
	timeout2.begin(500);
}


void loop(void) {

	if (timeout1.update()) {
		Serial.println("Timeout 2 Seconds");
	}

	if (timeout2.update()) {
		Serial.println("Timeout 500 ms");
	}

}