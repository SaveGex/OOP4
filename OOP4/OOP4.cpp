#include <iostream>
#include <cassert>
#include <ctime>

using namespace std;
 //–, != , == , > , <, >> , << , =, +="," – = "," ().

class Time {
private:
	
	int hour = 0;
	int minute = 0;
	int second = 0;

	void time_transition() {
		if (second >= 60) {
			minute++;
		}
		if (minute >= 60) {
			hour++;
		}
	}

public:
	

	Time(int hour, int minute, int second) : hour{hour}, minute{minute}, second{second}{}
	Time(int minute, int second) {
		int seconds = minute * second;
		while (second > 0) {
			seconds -= 60;
			minute += 1;
			if (minute >= 60) {
				hour++;
				minute = 0;
			}
			else if (seconds < 60) {
				second = seconds;
				seconds = 0;
			}
		}
	}
	Time(int seconds){
		
	}
	void operator++() {
		second++;
		void time_transition();
	}
	int operator-(int &seconds) {
		if (seconds > hour * minute * second) {
			hour = minute = second = 0;
		}
		else {
			while (seconds > 0) {
				if (hour > 0) {
					int hour_buf = seconds * 60 * 60;
					if (hour < hour_buf) {
						hour = 0;
						seconds = (hour_buf - hour) / 60 / 60;
					}
					else {
						hour -= hour_buf;
						seconds = 0;
					}
				}
				if (minute > 0) {
					int minute_buf = seconds * 60;
					if (minute < minute_buf) {
						minute = 0;
						seconds = (minute_buf - minute) / 60;
					}
					else {
						minute -= minute_buf;
						seconds = 0;
					}
				}
				if (second > 0){
					if (second < seconds) {
						seconds = 0;
						second = 0;
					}
					else {
						second -= seconds;
						seconds = 0;
					}
				}
			}
		}
	}

};


int main(){
	srand(static_cast<int>(time(nullptr)));
	

	return 0;
}

