#include "Communist.h"
#include "GUIManager.h"
#include "GUIWindow.h"
#include "GUIButton.h"
#include "GUIImage.h"
#include "GUIText.h"

Communist::Communist() :
	mPopulation(50),			//Befolkning i miljoner
	mPatriotism(20),
	mTaxes(30),
	mFood(0),
	mTech(0),
	mGoods(0),
	mSpyNetwork(0),
	mSpaceProgram(0),
	mNuclearWeapon(10),
	mIncreasePopulation(false)
{
	initializeCommunistWindow();
}


Communist::~Communist()
{
}

//-------------------------------------
/*Funktioner som returnerar medlemsvariablernas v�rden*/
int Communist::getCurrency()
{
	return mCurrency;
}

int Communist::getFood()
{
	return mFood;
}

int Communist::getGoods()
{
	return mGoods;
}

int Communist::getTaxes()
{
	return mTaxes;
}

int Communist::getTech()
{
	return mTech;
}

int Communist::getNuclearWeapon()
{
	return mNuclearWeapon;
}

int Communist::getSpaceProgram()
{
	return mSpaceProgram;
}

int Communist::getSpyNetwork()
{
	return mSpyNetwork;
}

//President Communist::getPresident()
//{
//	return mPresident;
//}
//--------------------------------------------
/*Funktioner som ger medlemsvariabler nya v�rden*/
void Communist::setFood(int food)
{
	mFood = food;
}

void Communist::setGoods(int goods)
{
	mGoods = goods;
}

void Communist::setTaxes(int taxes)
{
	mTaxes = taxes;
}

void Communist::setTech(int tech)
{
	mTech = tech;
}

//President Communist::setPresident(President &president)
//{
//	mPresident = &president;
//}
//-----------------------------------------------------------
/*	Uppgraderar mNuclearWeapon med ett
	Kostar 10 mGoods och 5 mTech*/
void Communist::upgradeNuclearWeapon()
{
	++mNuclearWeapon;

	mGoods	-= 10;
	mTech	-= 5;
}

/*	Uppgraderar mSpaceProgram med ett
	Kostar 5 mGoods multiplicerat med den nuvarande niv�n
	och 10 mTech multiplicerat med den nuvarande niv�n*/
void Communist::upgradeSpaceProgram()
{
	++mSpaceProgram;

	mGoods	-= 5 * mSpaceProgram;
	mTech	-= 10 * mSpaceProgram;
}

/*	Uppgraderar mSpyNetwork med ett
	Kostar 10 mTech multiplicerat med den nuvarande niv�n*/
void Communist::upgradeSpyNetwork()
{
	++mSpyNetwork;

	mTech -= 10 * mSpyNetwork;
}

/*Uppgraderar mCurrency med mTaxes multiplicerat med mPopulation*/
void Communist::getTaxIncome()
{
	mCurrency += mTaxes * mPopulation;
}

/*Kontrollerar ifall det finns nog med mat till hela befolkningen*/
bool Communist::enoughFood()
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

void Communist::updateFood()
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
bool Communist::enableToIncreasePopulation()
{
	return mIncreasePopulation;
}
/*	mCurrency subtraheras med mPopulation, befolkningen i miljoner.
	�kar befolkningen med ett, en miljon.
	Och tilldelar boolean:en mIncreasePopulation till false.*/
void Communist::increasePopulation()
{
	mCurrency -= mPopulation;

	++mPopulation;

	mIncreasePopulation = false;
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

	GUIManager::getInstance()->addGUIElement(mCommunistMainWindow);

	mTaxesWindow = NULL;
}

void Communist::onGuiClick(std::shared_ptr<GUIElement> guiElement)
{
	if(guiElement == mCommunistTaxesButton)
	{
		openTaxesMenu();
	}
	else if(guiElement == mTaxesCloseButton)
	{
		closeTaxesMenu();
	}
}

void Communist::openTaxesMenu()
{
	if(mTaxesWindow == NULL)
	{
		mTaxesWindow		= std::make_shared<GUIWindow>	(227, 264, 570, 168, mCommunistMainWindow);
		mTaxesImage			= std::make_shared<GUIImage>	(-227, -264, 0, 0, "ref5.png", mTaxesWindow);
		mTaxesCloseButton	= std::make_shared<GUIButton>	(235, 110, 101, 40, mTaxesWindow);

		GUIManager::getInstance()->addGUIElement(mTaxesWindow);
	}
	if(!mTaxesWindow->getVisible())
	{
		mTaxesWindow->setVisible(true);
	}
}

void Communist::closeTaxesMenu()
{
	mTaxesWindow->setVisible(false);
}