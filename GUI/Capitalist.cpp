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
	initializeCapitalistWindow();
}


Capitalist::~Capitalist()
{
}

//-------------------------------------
/*Funktioner som returnerar medlemsvariablernas värden*/
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
/*Funktioner som ger medlemsvariabler nya värden*/
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
	Kostar 5 mGoods multiplicerat med den nuvarande nivån
	och 10 mTech multiplicerat med den nuvarande nivån*/
void Capitalist::upgradeSpaceProgram()
{
	++mSpaceProgram;

	mGoods	-= 5 * mSpaceProgram;
	mTech	-= 10 * mSpaceProgram;
}

/*	Uppgraderar mSpyNetwork med ett
	Kostar 10 mTech multiplicerat med den nuvarande nivån*/
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
 * Initierar huvudfönster med all GUI-information som behövs
 *
 *				Av: Jon Wahlström		2013-01-23
 */
void Capitalist::initializeCapitalistWindow()
{
	mCapitalistMainWindow		= std::make_shared<GUIElement>( GUIWindow(0, 0, 1024, 768));
	mCapitalistMainWindowImage	= std::make_shared<GUIElement>( GUIImage(0, 0, 0, 0, "CapitalistImages/ref.png", mCapitalistMainWindow));//(0, 0, 0, 0, "CapitalistImages/ref.png", mCapitalistMainWindow));
	mCapitalistTaxesButton		= std::make_shared<GUIElement>( GUIButton(112, 636, 200, 132, mCapitalistMainWindow));
	mCapitalistResourceButton	= std::make_shared<GUIElement>( GUIButton(312, 636, 200, 132, mCapitalistMainWindow));
	mCapitalistUpgradeButton	= std::make_shared<GUIElement>( GUIButton(517, 636, 200, 132, mCapitalistMainWindow));
	mCapitalistExportButton		= std::make_shared<GUIElement>( GUIButton(711, 636, 200, 132, mCapitalistMainWindow));
	mCapitalistTaxesImage		= std::make_shared<GUIElement>( GUIImage (112, 636, 200, 132, "CapitalistImages/7_kap_tax.png", mCapitalistMainWindow));
	mCapitalistResourceImage	= std::make_shared<GUIElement>( GUIImage (312, 636, 200, 132, "CapitalistImages/7_kap_res.png", mCapitalistMainWindow));
	mCapitalistUpgradeImage		= std::make_shared<GUIElement>( GUIImage (517, 636, 200, 132, "CapitalistImages/7_kap_upg.png", mCapitalistMainWindow));
	mCapitalistExportImage		= std::make_shared<GUIElement>( GUIImage (711, 636, 200, 132, "CapitalistImages/7_kap_exp.png", mCapitalistMainWindow));



	mTaxesWindow	= NULL;
	mResourceWindow	= NULL;
	mUpgradeWindow	= NULL;
	mExportWindow	= NULL;

	/*
	 	Lägger in föräldernoden i vektorn som finns i GUIManager
	 	och kommer automatiskt få med sig alla barnnoder till denna
	 	vilket är alla GUIElement som finns i denna klass som har 
	 	mCapitalistMainWindow som parent-argument i dess konstruktor
																		*/
	GUIManager::getInstance()->addGUIElement(mCapitalistMainWindow);
}

/*
 * Om vänster musknapp har blivit nedtryckt och GUI elementet är en existerande knapp
 * kommer denna att kalla på sin funktion för att initiera ett nytt fönster med nya
 * menyval beroende på vilken knapp som blivit vald.
 *
 *		Av: Jon Wahlström	2013-23-01
 */
void Capitalist::onGUIClick(std::shared_ptr<GUIElement> guiElement)
{
	if(guiElement == mCapitalistTaxesButton)
	{
		openTaxesMenu();	
	}

	if(guiElement == mTaxesCloseButton)
	{
		closeTaxesMenu();
	}

	if(guiElement == mCapitalistResourceButton)
	{
		openResourceMenu();
	}

	if(guiElement == mResourceCloseButton)
	{
		closeResourceMenu();
	}

	if(guiElement == mCapitalistUpgradeButton)
	{
		openUpgradeMenu();
	}

	if(guiElement == mUpgradeCloseButton)
	{
		closeUpgradeMenu();
	}

	if(guiElement == mCapitalistExportButton)
	{
		openExportMenu();
	}

	if(guiElement == mExportCloseButton)
	{
		closeExportMenu();
	}
}

// JON WAHLSTRÖM
void Capitalist::openTaxesMenu()
{
	if(mTaxesWindow == NULL) 
	{
		mTaxesWindow			= std::make_shared<GUIElement>( GUIWindow(227, 264, 570, 168, mCapitalistMainWindow));
		mTaxesImage				= std::make_shared<GUIElement>( GUIImage (-227, -264, 1024, 768, "CapitalistImages/ref5.png", mTaxesWindow));
	
		mTaxesCloseButton		= std::make_shared<GUIElement>( GUIButton(235, 110, 100, 40, mTaxesWindow));
		mTaxesCloseImage		= std::make_shared<GUIElement>( GUIImage (235, 110, 100, 40, "CapitalistImages/button_okay.png", mTaxesWindow));

		GUIManager::getInstance()->addGUIElement(mTaxesWindow);
	}

	if(!mTaxesWindow->getVisible())
	{
		mTaxesWindow->setVisible(true);
	}
}
// JON WAHLSTRÖM
void Capitalist::openResourceMenu()
{
	if(mResourceWindow == NULL)
	{
		mResourceWindow			= std::make_shared<GUIElement>( GUIWindow(227, 264 , 568, 165, mCapitalistMainWindow));
		mResourceImage			= std::make_shared<GUIElement>( GUIImage(-227, -264, 1024, 768, "CapitalistImages/ref6.png", mResourceWindow));

		mResourceCloseButton    = std::make_shared<GUIElement>( GUIButton(235, 110, 100, 40, mResourceWindow));
		mResourceCloseImage		= std::make_shared<GUIElement>( GUIImage (235, 110, 100, 40, "CapitalistImages/button_okay.png", mResourceWindow));

		GUIManager::getInstance()->addGUIElement(mResourceWindow);
	}

	if(!mResourceWindow->getVisible())
	{
		mResourceWindow->setVisible(true);
	}
}

// JON WAHLSTRÖM
void Capitalist::openUpgradeMenu()
{
	if(mUpgradeWindow == NULL)
	{
		mUpgradeWindow			= std::make_shared<GUIElement>( GUIWindow(226, 79 , 568, 534, mCapitalistMainWindow));
		mUpgradeImage			= std::make_shared<GUIElement>( GUIImage(-226, -79, 1024, 768, "CapitalistImages/ref7.png", mUpgradeWindow));

		mUpgradeCloseButton		= std::make_shared<GUIElement>( GUIButton(236, 478, 100, 40, mUpgradeWindow));
		mUpgradeCloseImage		= std::make_shared<GUIElement>( GUIImage (236, 478, 100, 40, "CapitalistImages/button_okay.png", mUpgradeWindow));

		GUIManager::getInstance()->addGUIElement(mUpgradeWindow);
		
	}

	if(!mUpgradeWindow->getVisible())
	{
		mUpgradeWindow->setVisible(true);
	}
}

// JON WAHLSTRÖM
void Capitalist::openExportMenu()
{
	if(mExportWindow == NULL)
	{
		mExportWindow			= std::make_shared<GUIElement>( GUIWindow(226, 79, 568, 534, mCapitalistMainWindow));
		mExportImage			= std::make_shared<GUIElement>( GUIImage(-226, -79, 1024, 768, "CapitalistImages/ref8.png", mExportWindow));

		mExportCloseButton		 = std::make_shared<GUIElement>( GUIButton(236, 478, 100, 40, mExportWindow));
		mExportCloseImage		 = std::make_shared<GUIElement>( GUIImage (236, 478, 100, 40, "CapitalistImages/button_okay.png", mExportWindow));

		GUIManager::getInstance()->addGUIElement(mExportWindow);
	}

	if(!mExportWindow->getVisible())
	{
		mExportWindow->setVisible(true);
	}
}


// JON WAHLSTRÖM
void Capitalist::closeTaxesMenu()
{
	mTaxesWindow->setVisible(false);
	
}

// JON WAHLSTRÖM
void Capitalist::closeResourceMenu()
{
	mResourceWindow->setVisible(false);
}

void Capitalist::closeUpgradeMenu()
{
	mUpgradeWindow->setVisible(false);
}


void Capitalist::closeExportMenu()
{
	mExportWindow->setVisible(false);
}


void Capitalist::updateFood()
{
	/*	Om mängden mat är tillräcklig blir mängden mat subtraherad med antalet befolkningen i miljoner
		Populationen ökar och om landet har mer eller lika mycket pengar som befolkning blir mIncreasePopulation true.
		Den används sedan för att ge möjligheten att betala en viss summa för att öka befolkningen*/
	if(enoughFood())
	{
		mFood -= mPopulation;
		++mPopulation;
		if(mCurrency >= mPopulation)
		{
			mIncreasePopulation = true;
		}
	}
	/*	Om mängden mat är mindre än häflten av befolkningen tilldelas mFood noll
		mPatriotism subtraheras även med två*/
	else if(mFood <= mPopulation / 2)
	{
		mFood = 0;
		mPatriotism -= 2;
	}
	/*	Om det inte finns tillräckligt med mat och mFood inte är lika med noll
		ökar inte patriotismen men mFood tilldelas noll*/
	else if(!enoughFood() && mFood != 0)
	{
		mFood = 0;
	}
	/*	Om inga av det överstående stämmer, innebär det att maten är lika med noll och befolkningen inte fått någon mat
		Detta ger minus fyra i patriotism*/
	else
	{
		mFood = 0;
		mPatriotism -= 4;
	}
}
/*Kontrollerar ifall det är möjligt att öka sin population*/
bool Capitalist::enableToIncreasePopulation()
{
	return mIncreasePopulation;
}
/*	mCurrency subtraheras med mPopulation, befolkningen i miljoner.
	Ökar befolkningen med ett, en miljon.
	Och tilldelar boolean:en mIncreasePopulation till false.*/
void Capitalist::increasePopulation()
{
	mCurrency -= mPopulation;

	++mPopulation;

	mIncreasePopulation = false;
}