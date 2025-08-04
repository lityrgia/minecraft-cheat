#pragma once
#include <chrono>

class timer
{
public:
	timer(std::chrono::milliseconds everyXms);
	bool isElapsed();
	void setEvery(std::chrono::milliseconds everyXms);
	void reset();
private:
	std::chrono::steady_clock::time_point timerBegin;
	std::chrono::milliseconds targetMs;
};