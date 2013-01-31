#ifndef _TIMER_H
#define _TIMER_H

#include <functional>
#include <SFML\System\Clock.hpp>
#include <vector>
#include <string>

class TimerHandler;

class Timer
{
public:
	static Timer* setTimer(std::function<void()> callbackFunc, int time = 50, int timesToExecute = 1);

	int getTimeLeft();
	int getTimesToExecuteLeft();

	bool tick();
	void killTimer();
	void resetTimer();
	~Timer();
private:
	Timer(std::function<void()> callbackFunc, int time, int timesToExecute);
private:
	std::function<void()> mCallbackFunc;
	int mTime;
	int mTimesToExecute;
	sf::Clock mClock;
};

#endif