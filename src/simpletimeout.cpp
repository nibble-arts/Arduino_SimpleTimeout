/*
 * SimpleTimeout class
 * 
 * @autor: Thomas Winkler
 * @copyright: 2019-11-17
 * @lizence: CC0
 */


#include <Arduino.h>
#include "simpletimeout.h"


SIMPLETIMEOUT::SIMPLETIMEOUT() {
}


void SIMPLETIMEOUT::begin(uint16_t time) {

	_timeout = time;

	retrigger();
}


bool SIMPLETIMEOUT::check(void) {

	return (_last_time + _timeout) < millis();
}


void SIMPLETIMEOUT::retrigger(void) {

	_last_time = millis();
}


bool SIMPLETIMEOUT::update(void) {

	if (check()) {
		retrigger();

		return true;
	}

	return false;
}