#include "GameManager.h"
#include "Randomizer.h"
#include "Capitalist.h"
#include "Communist.h"
#include "SuperPower.h"

GameManager* GameManager::mInstance = NULL;
GameManager* GameManager::getInstance()
{
	if(mInstance == NULL)
	{
		mInstance = new GameManager();
	}
	return mInstance;
}

GameManager::GameManager() : 
		mVecPlayersLeft(),
		mRound(0)
{
	mVecSuperPowers.push_back(std::make_shared<Capitalist>());
	mVecSuperPowers.push_back(std::make_shared<Communist>());
	//for(std::vector<std::shared_ptr<SuperPower> >::iterator it = mVecSuperPowers.begin(); it != mVecSuperPowers.end(); it++)
	//{
	//	//(*it)->choosePresident();
	//}
	mCurrentPlayer = mVecSuperPowers[Randomizer::getInstance()->randomNr(mVecSuperPowers.size(), 0)];
}

void GameManager::init(int year)
{
	getInstance()->setYear(year);
}

void GameManager::addSuperPower(std::shared_ptr<SuperPower> power)
{
	mVecSuperPowers.push_back(power);		
}

void GameManager::startRound()
{
	int moneyIntFood = 0;
	int moneyIntGoods = 0;
	int moneyIntTech = 0;
	// Money internationally should be equal to everybodies money together
	for(std::vector<std::shared_ptr<SuperPower> >::iterator it = mVecSuperPowers.begin(); it != mVecSuperPowers.end(); it++)
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
	//foodBought = moneyIntFood / mCurrentPlayer->getExportedFoodPrice();
	//goodsBought = moneyIntGoods / mCurrentPlayer->getExportedGoodsPrice();
	//techBought = moneyIntTech / mCurrentPlayer->getExportedTechPrice();
	//// if international market tries to buy more resources than you have
	//if(foodBought > mCurrentPlayer->getExportedFood()) foodBought = mCurrentPlayer->getExportedFood();
	//if(goodsBought > mCurrentPlayer->getExportedGoods()) goodsBought = mCurrentPlayer->getExportedGoods();
	//if(techBought > mCurrentPlayer->getExportedTech()) techBought = mCurrentPlayer->getExportedTech();
	//exports += (foodBought * mCurrentPlayer->getExportedFoodPrice()) + (goodsBought * mCurrentPlayer->getExportedGoodsPrice()) + (techBought * mCurrentPlayer->getExportedTechPrice());
	//mCurrentPlayer->setExportedFood(mCurrentPlayer->getExportedFood() - foodBought);
	//mCurrentPlayer->setExportedGoods(mCurrentPlayer->getExportedGoods() - goodsBought);
	//mCurrentPlayer->setExportedTech(mCurrentPlayer->getExportedTech() - techBought);
	//mCurrentPlayer->getTaxIncome();
	//mCurrentPlayer->setCurrency(mCurrentPlayer->getCurrency() + exports);
	getCurrentPlayer()->showGUI();
}

int GameManager::getYear()const
{
	return mYear;
}

std::shared_ptr<SuperPower> GameManager::getCurrentPlayer()const
{
	return mCurrentPlayer;
}

std::vector<std::shared_ptr<SuperPower> > GameManager::getPlayers()const
{
	return mVecSuperPowers;
}

void GameManager::setCurrentPlayer(std::shared_ptr<SuperPower> newPlayer)
{
	mCurrentPlayer = newPlayer;
	mCurrentPlayer->setRound(mCurrentPlayer->getRound() + 1);
}

void GameManager::selectStartingPlayer(std::shared_ptr<SuperPower> startingPlayer)
{
	setCurrentPlayer(startingPlayer); // Need to set setCurrentPlayer to update player round
	mVecPlayersLeft = mVecSuperPowers;
	for(std::vector<std::shared_ptr<SuperPower> >::iterator it = mVecPlayersLeft.begin(); it != mVecPlayersLeft.end(); it++)
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
	for(std::vector<std::shared_ptr<SuperPower> >::iterator it = mVecSuperPowers.begin(); it != mVecSuperPowers.end(); it++)
	{
		(*it)->hideGUI();
	}
	mRound++;
	// Everybody has played once this round, time to decide next player to start by spy network
	if(mRound%mVecSuperPowers.size() == 0)
	{
		setYear(getYear() + 1);
		// Loop all players and put those with highest same spy network in vector to get random
		std::vector<std::shared_ptr<SuperPower> > nextPlayers;
		int max = -1;
		for(std::vector<std::shared_ptr<SuperPower> >::iterator it = mVecSuperPowers.begin(); it != mVecSuperPowers.end(); it++)
		{
			if((*it)->getSpyNetwork() > max)
				max = (*it)->getSpyNetwork();
		}
		for(std::vector<std::shared_ptr<SuperPower> >::iterator it = mVecSuperPowers.begin(); it != mVecSuperPowers.end(); it++)
		{
			if((*it)->getSpyNetwork() == max)
				nextPlayers.push_back((*it));
		}

		int randomPlayer = Randomizer::getInstance()->randomNr(nextPlayers.size(), 1);
		//nextPlayers[randomPlayer - 1]->selectStartingPlayer();
	}
	else
	{
		std::vector<std::shared_ptr<SuperPower> > nextPlayers;
		int max = -1;
		for(std::vector<std::shared_ptr<SuperPower> >::iterator it = mVecPlayersLeft.begin(); it != mVecPlayersLeft.end(); it++)
		{
			if((*it)->getSpyNetwork() > max)
				max = (*it)->getSpyNetwork();
		}
		for(std::vector<std::shared_ptr<SuperPower> >::iterator it = mVecPlayersLeft.begin(); it != mVecPlayersLeft.end(); it++)
		{
			if((*it)->getSpyNetwork() == max)
				nextPlayers.push_back((*it));
		}
		int randomPlayer = Randomizer::getInstance()->randomNr(nextPlayers.size(), 1);
		setCurrentPlayer(nextPlayers[randomPlayer - 1]);
		// Remove current player from players left to play
		for(std::vector<std::shared_ptr<SuperPower> >::iterator it = mVecPlayersLeft.begin(); it != mVecPlayersLeft.end(); it++)
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

