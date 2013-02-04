#include "GameManager.h"

GameManager* GameManager::mInstance = nullptr;

GameManager* GameManager::getInstance()
{
	if(mInstance == nullptr)
	{
		mInstance = new GameManager();
	}

	return mInstance;
}

GameManager::GameManager() :
	mCapitalist(),
	mCommunist()
{
}


GameManager::~GameManager()
{
}


