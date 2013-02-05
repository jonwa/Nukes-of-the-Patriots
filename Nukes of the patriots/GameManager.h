#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H

#include <vector>

class SuperPower;

class GameManager
{
public:
								GameManager(int year, std::vector<SuperPower*> SuperPowerVec, SuperPower *currentPlayer);
	int							getYear()const;
	SuperPower*					getCurrentPlayer()const;
	std::vector<SuperPower*>	getPlayers()const;
	void						selectStartingPlayer(SuperPower *startingPlayer);
	void						setCurrentPlayer(SuperPower* nextPlayer);
	void						setYear(int year);
	void						startRound();
	void						nextRound();
								~GameManager();
private:
	int mYear, mRound;
	// Theoretically you should be able to play with x amount of players - instead of only 2
	std::vector<SuperPower*> mVecSuperPowers;
	std::vector<SuperPower*> mVecPlayersLeft;
	SuperPower *mCurrentPlayer;
};

#endif