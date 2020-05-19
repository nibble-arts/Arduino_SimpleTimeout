/*
 * SimpleTimeout class header
 * 
 * @autor: Thomas Winkler
 * @copyright: 2019-11-17
 * @lizence: CC0
 */


#ifndef SIMPLETIMEOUT_H
#define SIMPLETIMEOUT_H


class SIMPLETIMEOUT {

	public:
		SIMPLETIMEOUT(void);

		void begin(uint16_t); // start timeout with time in ms

		bool check(void); // check if timedout
		void retrigger(void); // retrigger timeout
		bool update(void); // check if timed out and retrigger if so

	private:
		uint16_t _timeout;
		uint32_t _last_time;
};


#endif