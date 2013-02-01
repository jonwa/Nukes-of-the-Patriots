#include "GameManager.h"
#include "Randomizer.h"

GameManager::GameManager(int year, std::vector<PoliticalSystem*> politicalSystemVec, PoliticalSystem *currentPlayer)
	:mYear(year),mVecPoliticalSystems(politicalSystemVec),mVecPlayersLeft(),mRound(0)
{
	setCurrentPlayer(currentPlayer);
	for(std::vector<PoliticalSystem*>::iterator it = mVecPoliticalSystems.begin(); it != mVecPoliticalSystems.end(); it++)
	{
		(*it)->choosePresident();
	}
}

void GameManager::startRound()
{
	int moneyIntFood = 0;
	int moneyIntGoods = 0;
	int moneyIntTech = 0;
	// Money internationally should be equal to everybodies money together
	for(std::vector<PoliticalSystem*>::iterator it = mVecPoliticalSystems.begin(); it != mVecPoliticalSystems.end(); it++)
	{
		moneyIntFood += (*it)->getCurrency();
		moneyIntGoods += (*it)->getCurrency();
		moneyIntTech += (*it)->getCurrency();
	}
	int foodBought = 0;
	int goodsBought = 0;
	int techBought = 0;
	int exports = 0;
	// if nobody bought my exports - then it will be sold internationally
	foodBought = moneyIntFood / mCurrentPlayer->getExportedFoodPrice();
	goodsBought = moneyIntGoods / mCurrentPlayer->getExportedGoodsPrice();
	techBought = moneyIntTech / mCurrentPlayer->getExportedTechPrice();
	// if international market tries to buy more resources than you have
	if(foodBought > mCurrentPlayer->getExportedFood()) foodBought = mCurrentPlayer->getExportedFood();
	if(goodsBought > mCurrentPlayer->getExportedGoods()) goodsBought = mCurrentPlayer->getExportedGoods();
	if(techBought > mCurrentPlayer->getExportedTech()) techBought = mCurrentPlayer->getExportedTech();
	exports += (foodBought * mCurrentPlayer->getExportedFoodPrice()) + (goodsBought * mCurrentPlayer->getExportedGoodsPrice()) + (techBought * mCurrentPlayer->getExportedTechPrice());
	mCurrentPlayer->setExportedFood(mCurrentPlayer->getExportedFood() - foodBought);
	mCurrentPlayer->setExportedGoods(mCurrentPlayer->getExportedGoods() - goodsBought);
	mCurrentPlayer->setExportedTech(mCurrentPlayer->getExportedTech() - techBought);
	mCurrentPlayer->getTaxIncome();
	mCurrentPlayer->setCurrency(mCurrentPlayer->getCurrency() + exports);
	getCurrentPlayer()->showGUI(this);
}

int GameManager::getYear()const
{
	return mYear;
}

PoliticalSystem* GameManager::getCurrentPlayer()const
{
	return mCurrentPlayer;
}

std::vector<PoliticalSystem*> GameManager::getPlayers()const
{
	return mVecPoliticalSystems;
}

void GameManager::setCurrentPlayer(PoliticalSystem *newPlayer)
{
	mCurrentPlayer = newPlayer;
	mCurrentPlayer->setRound(mCurrentPlayer->getRound() + 1);
}

void GameManager::selectStartingPlayer(PoliticalSystem *startingPlayer)
{
	setCurrentPlayer(startingPlayer); // Need to set setCurrentPlayer to update player round
	mVecPlayersLeft = mVecPoliticalSystems;
	for(std::vector<PoliticalSystem*>::iterator it = mVecPlayersLeft.begin(); it != mVecPlayersLeft.end(); it++)
	{
		if((*it) == mCurrentPlayer)
		{
			mVecPlayersLeft.erase(it);
			break;
		}
	}
}

void GameManager::setYear(int year)
{
	mYear = year; 
}

void GameManager::nextRound()
{
	for(std::vector<PoliticalSystem*>::iterator it = mVecPoliticalSystems.begin(); it != mVecPoliticalSystems.end(); it++)
	{
		(*it)->hideGUI();
	}
	mRound++;
	// Everybody has played once this round, time to decide next player to start by spy network
	if(mRound%mVecPoliticalSystems.size() == 0)
	{
		setYear(getYear() + 1);
		// Loop all players and put those with highest same spy network in vector to get random
		std::vector<PolticalSystem*> nextPlayers;
		int max = -1;
		for(std::vector<PoliticalSystem*>::iterator it = mVecPoliticalSystems.begin(); it != mVecPoliticalSystems.end(); it++)
		{
			if((*it)->getSpyNetwork() > max)
				max = (*it)->getSpyNetwork();
		}
		for(std::vector<PoliticalSystem*>::iterator it = mVecPoliticalSystems.begin(); it != mVecPoliticalSystems.end(); it++)
		{
			if((*it)->getSpyNetwork() == max)
				nextPlayers.push_back((*it));
		}

		int randomPlayer = Randomizer::randomNr(nextPlayers.size(), 1);
		nextPlayers[randomPlayer - 1]->selectStartingPlayer();
	}
	else
	{
		std::vector<PolticalSystem*> nextPlayers;
		int max = -1;
		for(std::vector<PoliticalSystem*>::iterator it = mVecPlayersLeft.begin(); it != mVecPlayersLeft.end(); it++)
		{
			if((*it)->getSpyNetwork() > max)
				max = (*it)->getSpyNetwork();
		}
		for(std::vector<PoliticalSystem*>::iterator it = mVecPlayersLeft.begin(); it != mVecPlayersLeft.end(); it++)
		{
			if((*it)->getSpyNetwork() == max)
				nextPlayers.push_back((*it));
		}
		int randomPlayer = Randomizer::randomNr(nextPlayers.size(), 1);
		setCurrentPlayer(nextPlayers[randomPlayer - 1]);
		// Remove current player from players left to play
		for(std::vector<PoliticalSystem*>::iterator it = mVecPlayersLeft.begin(); it != mVecPlayersLeft.end(); it++)
		{
			if((*it) == mCurrentPlayer)
			{
				mVecPlayersLeft.erase(it);
				break;
			}
		}
	}
	startRound();
}

