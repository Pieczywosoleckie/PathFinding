#pragma once 
#include <ctime>

class Timer {
private:
	std::clock_t start;
	double pausedTime = 0.0;
	bool paused = false;

public :
	Timer();

	void stopTimer();
	void resetTimer();
	void pauseTimer();
	void resumeTimer();

	double getTime() const;
};