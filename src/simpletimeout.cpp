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


void SIMPLETIMEOUT::begin(uint32_t time) {

	_time = time;

	retrigger();
}


bool SIMPLETIMEOUT::check(void) {

	return (_timeout + _time) < millis();
}


void SIMPLETIMEOUT::retrigger(void) {

	_timeout = millis();
}


bool SIMPLETIMEOUT::update(void) {

	if (check()) {
		retrigger();

		return true;
	}

	return false;
}