#include "TimerHandler.h"
#include "Timer.h"

TimerHandler::TimerHandler():mVecTimers(){}

void TimerHandler::addTimer(Timer* timer)
{
	mVecTimers.push_back(timer);
}

void TimerHandler::removeTimer(Timer* timer)
{
	for(std::vector<Timer*>::iterator it = mVecTimers.begin(); it != mVecTimers.end(); it++)
	{
		if((*it) == timer)
		{
			//delete (*it);
			mVecTimers.erase(it);
			break;
		}
	}
}

void TimerHandler::tick()
{
	for(std::vector<Timer*>::iterator it = mVecTimers.begin(); it != mVecTimers.end();)
	{
		if(!(*it)->tick())
		{
			delete (*it);
			it = mVecTimers.erase(it);
		}
		else
			++it;
	}
}

TimerHandler* TimerHandler::mInstance = NULL;

TimerHandler* TimerHandler::getInstance()
{
	if(mInstance == NULL)
		mInstance = new TimerHandler();
	return mInstance;
}