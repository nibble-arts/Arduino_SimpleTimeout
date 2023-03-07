/*
 * SimpleTimeout class
 * 
 * @autor: Thomas Winkler
 * @copyright: 2019-11-17
 * @lizence: CC0
 *
 * change:
 *		add progress
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

uint32_t SIMPLETIMEOUT::rest(void) {

	if (millis() < (_last_time + _timeout)) {		
		return (_last_time + _timeout) - millis();
	}

	return false;
}

uint8_t SIMPLETIMEOUT::progress(void) {

	return (millis() - _last_time) * 100 / _timeout;
}