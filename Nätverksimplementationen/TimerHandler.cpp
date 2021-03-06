#include "TimerHandler.h"
#include "Timer.h"
#include <iostream>

TimerHandler::TimerHandler():mVecTimers(){}

void TimerHandler::addTimer(Timer* timer)
{
	mVecTimers.push_back(timer);
}

void TimerHandler::removeTimer(Timer* timer)
{
	for(std::vector<Timer*>::size_type it = 0; it < mVecTimers.size(); it++)
	{
		if(mVecTimers[it] == timer)
		{
			mVecTimers[it] = NULL; // Elements are not going to be deleted here
			break;
		}
	}
}

void TimerHandler::tick()
{
	for(std::vector<Timer*>::size_type it = 0; it < mVecTimers.size(); it++)
	{
		if(mVecTimers[it] == NULL)
		{
			delete mVecTimers[it];
			mVecTimers.erase(mVecTimers.begin() + it);
		}
		else
		{
			if(!mVecTimers[it]->tick())
			{
				if(mVecTimers[it] != NULL)
				{
					delete mVecTimers[it];
					mVecTimers.erase(mVecTimers.begin() + it);
				}
			}
		}
	}
}

TimerHandler* TimerHandler::mInstance = NULL;

TimerHandler* TimerHandler::getInstance()
{
	if(mInstance == NULL)
		mInstance = new TimerHandler();
	return mInstance;
}