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

		void begin(uint32_t); // start timeout with time in ms
		bool check(void); // check if timedout
		void retrigger(void); // retrigger timeout
		bool update(void); // check if timed out and retrigger if so

	private:
		uint32_t _time;
		uint32_t _timeout;
};


#endif