#include "Capitalist.h"
#include "GUIElement.h"
#include "GUIManager.h"
#include "GUIWindow.h"
#include "GUIButton.h"
#include "GUIImage.h"

#include <SFML\Window\Mouse.hpp>

Capitalist::Capitalist() :
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
	//initializeCapitalistWindowInformation();
}


Capitalist::~Capitalist()
{
}

//-------------------------------------
/*Funktioner som returnerar medlemsvariablernas v�rden*/
int Capitalist::getCurrency()
{
	return mCurrency;
}

int Capitalist::getFood()
{
	return mFood;
}

int Capitalist::getGoods()
{
	return mGoods;
}

int Capitalist::getTaxes()
{
	return mTaxes;
}

int Capitalist::getTech()
{
	return mTech;
}

int Capitalist::getNuclearWeapon()
{
	return mNuclearWeapon;
}

int Capitalist::getSpaceProgram()
{
	return mSpaceProgram;
}

int Capitalist::getSpyNetwork()
{
	return mSpyNetwork;
}

//President Capitalist::getPresident()
//{
//	return mPresident;
//}
//--------------------------------------------
/*Funktioner som ger medlemsvariabler nya v�rden*/
void Capitalist::setFood(int food)
{
	mFood = food;
}

void Capitalist::setGoods(int goods)
{
	mGoods = goods;
}

void Capitalist::setTaxes(int taxes)
{
	mTaxes = taxes;
}

void Capitalist::setTech(int tech)
{
	mTech = tech;
}

//President Capitalist::setPresident(President &president)
//{
//	mPresident = president;
//}
//-----------------------------------------------------------
/*	Uppgraderar mNuclearWeapon med ett
	Kostar 10 mGoods och 5 mTech*/
void Capitalist::upgradeNuclearWeapon()
{
	++mNuclearWeapon;

	mGoods	-= 10;
	mTech	-= 5;
}

/*	Uppgraderar mSpaceProgram med ett
	Kostar 5 mGoods multiplicerat med den nuvarande niv�n
	och 10 mTech multiplicerat med den nuvarande niv�n*/
void Capitalist::upgradeSpaceProgram()
{
	++mSpaceProgram;

	mGoods	-= 5 * mSpaceProgram;
	mTech	-= 10 * mSpaceProgram;
}

/*	Uppgraderar mSpyNetwork med ett
	Kostar 10 mTech multiplicerat med den nuvarande niv�n*/
void Capitalist::upgradeSpyNetwork()
{
	++mSpyNetwork;

	mTech -= 10 * mSpyNetwork;
}

/*Uppgraderar mCurrency med mTaxes multiplicerat med mPopulation*/
void Capitalist::getTaxIncome()
{
	mCurrency += mTaxes * mPopulation;
}

/*Kontrollerar ifall det finns nog med mat till hela befolkningen*/
bool Capitalist::enoughFood()
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

/*
 * Initierar huvudf�nster med all GUI-information som beh�vs
 *
 *				Av: Jon Wahlstr�m		2013-01-23
 */
void Capitalist::initializeCapitalistWindowInformation()
{
	mCapitalistMainWindow		= new GUIWindow	(0, 0, 1024, 768);
	mCapitalistMainWindowImage	= new GUIImage	(0, 0, 0, 0, "ref.png", mCapitalistMainWindow);
	mCapitalistTaxesButton		= new GUIButton	(112, 636, 200, 132, mCapitalistMainWindow);
	mCapitalistResourcesButton	= new GUIButton	(0, 0, 0, 0, mCapitalistMainWindow);
	mCapitalistUpgradeButton	= new GUIButton	(0, 0, 0, 0, mCapitalistMainWindow);
	mCapitalistExportButton		= new GUIButton	(0, 0, 0, 0, mCapitalistMainWindow);
	mCapitalistTaxesImage		= new GUIImage	(112, 636, 200, 132, "7_kap_tax.png", mCapitalistMainWindow);
	//mCapitalistResourceImage	= new GUIImage	(0, 0, 200, 132, "7_kom_res.png", mCapitalistMainWindow);
	//mCapitalistUpgradeImage		= new GUIImage	(0, 0, 200, 132, "7_kom_upg.png", mCapitalistMainWindow);
	//mCapitalistExportImage		= new GUIImage	(0, 0, 200, 132, "7_kom_exp.png", mCapitalistMainWindow);


	/*
	 *	L�gger in f�r�ldernoden i vektorn som finns i GUIManager
	 *	och kommer automatiskt f� med sig alla barnnoder till denna
	 *	vilet �r alla GUIElement som finns i denna klass som har 
	 *	mCapitalistMainWindow som parent-argument i dess konstruktor
	 */
	GUIManager::getInstance()->addGUIElement(mCapitalistMainWindow);
}


/*
 * Om v�nster musknapp har blivit nedtryckt och GUI elementet �r en existerande knapp
 * kommer denna att kalla p� sin funktion f�r att initiera ett nytt f�nster med nya
 * menyval beroende p� vilken knapp som blivit vald.
 *
 *
 *		Av: Jon Wahlstr�m	2013-23-01
 */
void Capitalist::update(GUIElement *guiElement)
{
	if(guiElement == mCapitalistTaxesButton)
	{
		triggerTaxesMenu();	
	}
}


// Av: Jon Wahlstr�m
void Capitalist::render()
{
	initializeCapitalistWindowInformation();
}


/* */
void Capitalist::triggerTaxesMenu()
{
	mTaxesWindow			= new GUIWindow(200, 200, 600, 300, mCapitalistMainWindow);
	mTaxesImage				= new GUIImage(224, 264, 568, 165, "ref5.png", mTaxesWindow);
	
	GUIManager::getInstance()->addGUIElement(mTaxesWindow);
}





/*
 * St�nger ner det f�nstret som �r aktivt
 * 
 *	 Av: Jon Wahlstr�m 2013-01-23
 */
void Capitalist::closeWindow(GUIWindow *guiWindow)
{
	
	if(mCloseWindow->getParent() == mTaxesWindow)
	{
		mTaxesWindow->setVisible(false);
	}

}



void Capitalist::updateFood()
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
bool Capitalist::enableToIncreasePopulation()
{
	return mIncreasePopulation;
}
/*	mCurrency subtraheras med mPopulation, befolkningen i miljoner.
	�kar befolkningen med ett, en miljon.
	Och tilldelar boolean:en mIncreasePopulation till false.*/
void Capitalist::increasePopulation()
{
	mCurrency -= mPopulation;

	++mPopulation;

	mIncreasePopulation = false;
}