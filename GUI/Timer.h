#ifndef _TIMER_H
#define _TIMER_H

#include <functional>
#include <SFML\System\Clock.hpp>

class TimerHandler;

class Timer
{
public:
	static Timer* setTimer(std::function<void()> callbackFunc, double time = 50, int timesToExecute = 1);
	bool tick();
	void killTimer();
	void resetTimer();
	~Timer();
private:
	Timer(std::function<void()> callbackFunc, double time, int timesToExecute);
private:
	std::function<void()> mCallbackFunc;
	double mTime;
	int mTimesToExecute;
	sf::Clock mClock;
};

#endif