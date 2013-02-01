#include "Communist.h"
#include "GUIManager.h"
#include "GUIWindow.h"
#include "GUIButton.h"
#include "GUIImage.h"
#include "GUIText.h"
#include "Randomizer.h"

static int foodCost		= 10;
static int goodsCost	= 20;
static int techCost		= 30;
static int taxChange	= 5;

Communist::Communist()
{
	mPopulation			= 50;			//Befolkning i miljoner
	mPatriotism			= 20;
	mTaxes				= 30;
	mFood				= 0;
	mTech				= 0;
	mGoods				= 0;
	mSpyNetwork			= 0;
	mSpaceProgram		= 0;
	mNuclearWeapon		= 10;
	mRound				= 0;
	mIncreasePopulation = false;
	mType				= COMMUNIST;

	initializeCommunistWindow();
	initializeGuiFunctions();

	fiveYearInitialize();
}


Communist::~Communist()
{
}

void Communist::fiveYearInitialize()
{
	for(int i = 0; i < 5; ++i)
	{
		std::map<std::string, int> tempMap;
		tempMap.insert(std::pair<std::string, int> ("food", 0));
		tempMap.insert(std::pair<std::string, int> ("goods", 0));
		tempMap.insert(std::pair<std::string, int> ("tech", 0));
		tempMap.insert(std::pair<std::string, int> ("taxes", 0));
		mYearVector.push_back(tempMap);
	}
}

void Communist::setYearlyResources(int year, std::string key, int value)
{
	mYearVector[year-1][key] += value;
}

int Communist::getYearlyFood(int round)
{
	int year = round %5;

	if(year == 0)
	{
		year = 5;
	}
	year -= 1;
	return mYearVector[year]["food"];
}

int Communist::getYearlyGoods(int round)
{
	int year = round %5;

	if(year == 0)
	{
		year = 5;
	}
	year -= 1;
	return mYearVector[year]["goods"];
}

int Communist::getYearlyTech(int round)
{
	int year = round %5;

	if(year == 0)
	{
		year = 5;
	}
	year -= 1;
	return mYearVector[year]["tech"];
}

int Communist::getYearlyTaxes(int round)
{
	int year = round %5;

	if(year == 0)
	{
		year = 5;
	}
	year -= 1;

	return mYearVector[year]["taxes"];
}



/*	Uppgraderar mNuclearWeapon med ett
	Kostar 10 mGoods och 5 mTech*/
void Communist::upgradeNuclearWeapon(int currentNuclearCount, int currentGoods, int currentTech)
{
	currentGoods	-= 10;
	currentTech		-= 5;
	
	++currentNuclearCount;
}

/*	Uppgraderar mSpaceProgram med ett
	Kostar 5 mGoods multiplicerat med den nuvarande nivån
	och 10 mTech multiplicerat med den nuvarande nivån*/
void Communist::upgradeSpaceProgram(int currentSpaceCount, int currentGoods, int currentTech)
{
	currentGoods	-= 5 * currentSpaceCount;
	currentTech		-= 10 * currentSpaceCount;
	
	++currentSpaceCount;
}

/*	
	Uppgraderar mSpyNetwork med ett
	Kostar 10 mTech multiplicerat med den nuvarande nivån
															 */
void Communist::upgradeSpyNetwork(int currentSpyCount, int currentTech)
{
	currentTech -= 10 * currentSpyCount;
	
	++currentSpyCount;
}

//--------------------------------------------
/*Funktioner som ger medlemsvariabler nya värden*/
void Communist::setFood(int foodCount, int currentCurrency, int value)
{
	foodCount		+= value;
	currentCurrency -= value * foodCost;
}

void Communist::setGoods(int goodsCount, int currentCurrency, int value)
{
	goodsCount		+= value;
	currentCurrency -= value * goodsCost;
}

void Communist::setTech(int techCount, int currentCurrency, int value)
{
	techCount		+= value;
	currentCurrency -= value * techCost;
}

int Communist::increaseTaxCost(int currentTax)
{
	currentTax += taxChange;
	
	return currentTax;
}
  
int Communist::decreaseTaxCost(int currentTax)
{
	currentTax -= taxChange;
	
	return currentTax;
}

/*  Köper en dos propaganda för 100 kr/dos som kan ge upp till 10 av en resurs, 
	antalet man får är ==  10 rolls med en %chans baserat på resursens andel av 
	det årets planerade totala mängd resurser. (Därav måste 5-årsplanen komma före)
	Man kan inte med hjälp av propaganda producera mer av en 
	resurs än den mängd som står i femårsplanen för det året.
																			*/
void Communist::buyPropagandaFood(int round)
{
	int resourcesTotal = 0;
	resourcesTotal += getYearlyFood(round);
	resourcesTotal += getYearlyGoods(round);
	resourcesTotal += getYearlyTech(round);

	int percent = mFood/resourcesTotal;
	percent*=100;

	for(int i=0;i<10;i++)
	{
		float randNr=Randomizer::getInstance()->randomNr(100,1);

		if(randNr<percent)
		{
			mFood++;
		}
	}
}

void Communist::buyPropagandaGoods(int round)
{
	int resourcesTotal = 0;
	resourcesTotal += getYearlyFood(round);
	resourcesTotal += getYearlyGoods(round);
	resourcesTotal += getYearlyTech(round);

	int percent = mGoods/resourcesTotal;
	percent*=100;

	for(int i=0;i<10;i++)
	{
		float randNr=Randomizer::getInstance()->randomNr(100,1);

		if(randNr<percent)
		{
			mGoods++;
		}
	}
}

void Communist::buyPropagandaTech(int round)
{
	int resourcesTotal = 0;
	resourcesTotal += getYearlyFood(round);
	resourcesTotal += getYearlyGoods(round);
	resourcesTotal += getYearlyTech(round);
	
	int percent = mTech/resourcesTotal;
	percent*=100;

	for(int i=0;i<10;i++)
	{
		float randNr=Randomizer::getInstance()->randomNr(100,1);

		if(randNr<percent)
		{
		mTech++;
		}
	}
}

void Communist::initializeCommunistWindow()
{
	mCommunistMainWindow		= std::make_shared<GUIWindow>	(0, 0, 1024, 768);
	mCommunistMainImage			= std::make_shared<GUIImage>	(0, 0, 0, 0, "ref.png", mCommunistMainWindow);
	mCommunistTaxesButton		= std::make_shared<GUIButton>	(112, 636, 200, 132, mCommunistMainWindow);
	mCommunistResourcesButton	= std::make_shared<GUIButton>	(0, 0, 0, 0, mCommunistMainWindow);
	mCommunistUpgradeButton		= std::make_shared<GUIButton>	(0, 0, 0, 0, mCommunistMainWindow);
	mCommunistExportButton		= std::make_shared<GUIButton>	(0, 0, 0, 0, mCommunistMainWindow);
	mCommunistTaxesImage		= std::make_shared<GUIImage>	(112, 636, 200, 132, "7_kap_tax.png", mCommunistMainWindow);
	mCommunistResourceImage;
	mCommunistUpgradeImage;
	mCommunistExportImage;


	mTaxesWindow		= std::make_shared<GUIWindow>	(227, 264, 570, 168, mCommunistMainWindow);
	mTaxesImage			= std::make_shared<GUIImage>	(-227, -264, 0, 0, "ref5.png", mTaxesWindow);
	mTaxesCloseButton	= std::make_shared<GUIButton>	(235, 110, 101, 40, mTaxesWindow);
	mTaxesWindow->setVisible(false);


	GUIManager::getInstance()->addGUIElement(mCommunistMainWindow);
}

void Communist::initializeGuiFunctions()
{
	mCommunistTaxesButton->setOnClickFunction([=]() { mTaxesWindow->setVisible(true); });
	mCommunistResourcesButton->setOnClickFunction( [=]() {  });
	mCommunistUpgradeButton->setOnClickFunction( [=]() {  });
	mCommunistExportButton->setOnClickFunction( [=]() {  });
}

void Communist::showGUI()
{
	mCommunistMainWindow->setVisible(false);
}

void Communist::hideGUI()
{
	mCommunistMainWindow->setVisible(true);
}