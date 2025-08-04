#include "timer.hpp"
#include <chrono>

timer::timer(std::chrono::milliseconds everyXms)
{
	setEvery(everyXms);
}

bool timer::isElapsed()
{
	std::chrono::steady_clock::time_point timerNow = std::chrono::steady_clock::now();
	if (std::chrono::duration_cast<std::chrono::milliseconds>(timerNow - timerBegin) >= targetMs)
	{
		timerBegin = timerNow;
		return true;
	}
	return false;
}

void timer::setEvery(std::chrono::milliseconds everyXms)
{
	timerBegin = std::chrono::steady_clock::now();
	targetMs = everyXms;
}

void timer::reset()
{
	timerBegin = std::chrono::steady_clock::now();
}