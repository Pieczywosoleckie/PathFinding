#include <utils/Timer.hpp>

Timer::Timer() {
	start = std::clock();
}

void Timer::stopTimer() {
	std::clock_t end = std::clock();
	double pauseTime = double(end - start) / CLOCKS_PER_SEC;
	pausedTime += pauseTime;
}

void Timer::resetTimer() {
	start = std::clock();
	pausedTime = 0.0;
}

void Timer::pauseTimer() {
	if (!paused) {
		std::clock_t current = std::clock();
		double currentTime = double(current - start) / CLOCKS_PER_SEC;
		pausedTime += currentTime;
		paused = true;
	}
}

void Timer::resumeTimer() {
	if (paused) {
		start = std::clock();
		paused = false;
	}
}

double Timer::getTime() const {
	if (paused) {
		return pausedTime;
	}
	else {
		std::clock_t current = std::clock();
		double currentTime = double(current - start) / CLOCKS_PER_SEC;
		return pausedTime + currentTime;
	}
}