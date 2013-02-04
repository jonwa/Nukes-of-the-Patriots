#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Capitalist.h"
#include "Communist.h"

class GameManager
{
public:
	static GameManager *getInstance();
	~GameManager();

	void update();
	void render();


private:
	GameManager();
	GameManager(const GameManager &);
	void operator=(const GameManager &);
	static GameManager *mInstance;

	Capitalist	mCapitalist;
	Communist	mCommunist;

};

#endif