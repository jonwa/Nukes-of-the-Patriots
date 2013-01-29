#include "PoliticalSystem.h"


PoliticalSystem::PoliticalSystem()
{
}


PoliticalSystem::~PoliticalSystem()
{
}


/*Funktioner som returnerar medlemsvariablernas v�rden*/
int PoliticalSystem::getCurrency()
{
	return mCurrency;
}

int PoliticalSystem::getFood()
{
	return mFood;
}

int PoliticalSystem::getGoods()
{
	return mGoods;
}

int PoliticalSystem::getPopulation()
{
	return mPopulation;
}

int PoliticalSystem::getTaxes()
{
	return mTaxes;
}

int PoliticalSystem::getTech()
{
	return mTech;
}

int PoliticalSystem::getNuclearWeapon()
{
	return mNuclearWeapon;
}

int PoliticalSystem::getSpaceProgram()
{
	return mSpaceProgram;
}

int PoliticalSystem::getSpyNetwork()
{
	return mSpyNetwork;
}

int PoliticalSystem::getRound()
{
	return mRound;
}
//--------------------------------------------
/*Funktioner som ger medlemsvariabler nya v�rden*/
void PoliticalSystem::setFood(int food)
{
	mFood = food;
}

void PoliticalSystem::setGoods(int goods)
{
	mGoods = goods;
}

void PoliticalSystem::setTaxes(int taxes)
{
	mTaxes = taxes;
}

void PoliticalSystem::setTech(int tech)
{
	mTech = tech;
}

void PoliticalSystem::setRound(int round)
{
	mRound = round;
}
//-----------------------------------------------------------

/*Uppgraderar mCurrency med mTaxes multiplicerat med mPopulation*/
void PoliticalSystem::getTaxIncome()
{
	mCurrency += mTaxes * mPopulation;
}

/*Kontrollerar ifall det finns nog med mat till hela befolkningen*/
bool PoliticalSystem::enoughFood()
{
	if(mFood >= mPopulation)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PoliticalSystem::updateFood()
{
	/*	Om m�ngden mat �r tillr�cklig blir m�ngden mat subtraherad med antalet befolkningen i miljoner
		Populationen �kar och om landet har mer eller lika mycket pengar som befolkning blir mIncreasePopulation true.
		Den anv�nds sedan f�r att ge m�jligheten att betala en viss summa f�r att �ka befolkningen*/
	if(enoughFood())
	{
		mFood -= mPopulation;
		++mPopulation;
		if(mCurrency >= mPopulation)
		{
			mIncreasePopulation = true;
		}
	}
	/*	Om m�ngden mat �r mindre �n h�flten av befolkningen tilldelas mFood noll
		mPatriotism subtraheras �ven med tv�*/
	else if(mFood <= mPopulation / 2)
	{
		mFood = 0;
		mPatriotism -= 2;
	}
	/*	Om det inte finns tillr�ckligt med mat och mFood inte �r lika med noll
		�kar inte patriotismen men mFood tilldelas noll*/
	else if(!enoughFood() && mFood != 0)
	{
		mFood = 0;
	}
	/*	Om inga av det �verst�ende st�mmer, inneb�r det att maten �r lika med noll och befolkningen inte f�tt n�gon mat
		Detta ger minus fyra i patriotism*/
	else
	{
		mFood = 0;
		mPatriotism -= 4;
	}
}
/*Kontrollerar ifall det �r m�jligt att �ka sin population*/
bool PoliticalSystem::enableToIncreasePopulation()
{
	return mIncreasePopulation;
}
/*	mCurrency subtraheras med mPopulation, befolkningen i miljoner.
	�kar befolkningen med ett, en miljon.
	Och tilldelar boolean:en mIncreasePopulation till false.*/
void PoliticalSystem::increasePopulation()
{
	mCurrency -= mPopulation;

	++mPopulation;

	mIncreasePopulation = false;
}