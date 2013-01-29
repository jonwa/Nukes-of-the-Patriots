#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H

#include "PoliticalSystem.h"
#include <vector>

class GameManager
{
public:
									GameManager(int year, std::vector<PoliticalSystem*> politicalSystemVec, PoliticalSystem *currentPlayer);
	int								getYear()const;
	PoliticalSystem*				getCurrentPlayer()const;
	std::vector<PoliticalSystem*>	getPlayers()const;
	void							setCurrentPlayer(PoliticalSystem* nextPlayer);
	void							setYear(int year);
	void							startRound();
	void							nextRound();
									~GameManager();
private:
	int mYear, mRound;
	// Theoretically you should be able to play with x amount of players - instead of only 2
	std::vector<PoliticalSystem*> mVecPoliticalSystems;
	std::vector<PoliticalSystem*> mVecPlayersLeft;
	PoliticalSystem *mCurrentPlayer;
};

#endif