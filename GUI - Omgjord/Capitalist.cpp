#include "Capitalist.h"
#include "GUIElement.h"
#include "GUIManager.h"
#include "GUIWindow.h"
#include "GUIButton.h"
#include "GUIImage.h"
#include "GUIText.h"
#include "President.h"
#include <iostream>
#include "Randomizer.h"

#include <SFML\Window\Mouse.hpp>


static int foodCost		= 10;
static int goodsCost	= 20;
static int techCost		= 30;
static int taxChange	= 5;

Capitalist::Capitalist() :
	mPresident(nullptr)
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
	mType				= CAPITALIST;


	initializeCapitalistWindow();
	initializeGuiFunctions();
}


Capitalist::~Capitalist()
{
}

std::shared_ptr<President> Capitalist::getPresident()
{
	return mPresident;
}

int Capitalist::increaseTaxCost(int currentTax)
{						
	currentTax += taxChange + mPresident->getPatriotismTaxModifier();

	return currentTax;
}

int Capitalist::decreaseTaxCost(int currentTax)
{
	currentTax -= taxChange + mPresident->getPatriotismTaxModifier();

	return currentTax;
}

void Capitalist::setPresident(std::shared_ptr<President> president)
{

	mPresident = president;
	
	foodCost	+= president->getFoodPriceModifier();
	goodsCost	+= president->getGoodsPriceModifier();
	techCost	+= president->getTechPriceModifier();
}

void Capitalist::setFood(int foodCount, int currentCurrency, int amount)
{
	foodCount += amount;
	currentCurrency -= amount * foodCost;
}

void Capitalist::setGoods(int goodsCount, int currentCurrency, int amount)
{
	goodsCount += amount;
	currentCurrency -= amount * goodsCost;
}

void Capitalist::setTech(int techCount, int currentCurrency, int amount)
{
	techCount += amount;
	currentCurrency -= amount * techCost;
}

//-----------------------------------------------------------
/*	
	Uppgraderar mNuclearWeapon med ett
	Kostar 10 mGoods och 5 mTech
										*/
void Capitalist::upgradeNuclearWeapon(int currentNuclearCount, int currentGoods, int currentTech)
{
	currentGoods	-= 10 * mPresident->getNuclearPriceModifier();
	currentTech		-= 5  * mPresident->getNuclearPriceModifier();

	++currentNuclearCount;

	mNuclearText->setText(intToString(mNuclearWeapon));
}

/*	
	Uppgraderar mSpaceProgram med ett
	Kostar 5 mGoods multiplicerat med den nuvarande nivån
	och 10 mTech multiplicerat med den nuvarande nivån
															*/
void Capitalist::upgradeSpaceProgram(int currentSpaceCount, int currentGoods, int currentTech)
{
	currentGoods	-= 5 * currentSpaceCount * mPresident->getSpacePriceModifier();
	currentTech		-= 10 * currentSpaceCount * mPresident->getSpacePriceModifier();

	++currentSpaceCount;
}

/*	
	Uppgraderar mSpyNetwork med ett
	Kostar 10 mTech multiplicerat med den nuvarande nivån
															*/
void Capitalist::upgradeSpyNetwork(int currentSpyCount, int currentTech)
{
	currentTech -= 10 * currentSpyCount * mPresident->getSpyPriceModifier();

	++currentSpyCount;
}
/*  Köper en dos propaganda för 100 kr/dos som kan ge upp till 10 av en resurs, 
antalet man får är ==  10 rolls med en %chans baserat på resursens andel av 
det årets planerade totala mängd resurser. (Därav måste 5-årsplanen komma före)
Man kan inte med hjälp av propaganda producera mer av en 
resurs än den mängd som står i femårsplanen för det året.
								*/
void Capitalist::buyPropaganda()
{
	
	mPropagandacount = 0;
	int percent=0;

	if(true)	//Food
		percent = mFood/mResourceTotal;
		percent*=100;

	for(int i=0;i<10;i++)
	{
		float randNr=Randomizer::getInstance()->randomNr(100,1);

		if(randNr<percent)
		{
		mFood++;
		}
	}
	if(false)	//Goods
		percent = mGoods/mResourceTotal;
		percent*=100;

	for(int i=0;i<10;i++)
	{
		float randNr=Randomizer::getInstance()->randomNr(100,1);

		if(randNr<percent)
		{
		mGoods++;
		}
	}
	if(true)	//Tech
		percent = mTech/mResourceTotal;
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


/*
  Initierar huvudfönster med all GUI-information som behövs
 
 				Av: Jon Wahlström		2013-01-23
																*/
void Capitalist::initializeCapitalistWindow()
{
	mCapitalistMainWindow		= std::make_shared<GUIWindow>(0, 0, 1024, 768);
	mCapitalistMainWindowImage	= std::make_shared<GUIImage> (0, 0, 0, 0, "CapitalistImages/ref.png", mCapitalistMainWindow);
	mCapitalistTaxesButton		= std::make_shared<GUIButton>(112, 636, 200, 132, mCapitalistMainWindow);
	mCapitalistResourceButton	= std::make_shared<GUIButton>(312, 636, 200, 132, mCapitalistMainWindow);
	mCapitalistUpgradeButton	= std::make_shared<GUIButton>(517, 636, 200, 132, mCapitalistMainWindow);
	mCapitalistExportButton		= std::make_shared<GUIButton>(711, 636, 200, 132, mCapitalistMainWindow);
	mCapitalistTaxesImage		= std::make_shared<GUIImage> (112, 636, 200, 132, "CapitalistImages/7_kap_tax.png", mCapitalistMainWindow);
	mCapitalistResourceImage	= std::make_shared<GUIImage> (312, 636, 200, 132, "CapitalistImages/7_kap_res.png", mCapitalistMainWindow);
	mCapitalistUpgradeImage		= std::make_shared<GUIImage> (517, 636, 200, 132, "CapitalistImages/7_kap_upg.png", mCapitalistMainWindow);
	mCapitalistExportImage		= std::make_shared<GUIImage> (711, 636, 200, 132, "CapitalistImages/7_kap_exp.png", mCapitalistMainWindow);

	mTaxesWindow			= std::make_shared<GUIWindow>(227, 264, 570, 168, mCapitalistMainWindow);
	mTaxesImage				= std::make_shared<GUIImage> (-227, -264, 1024, 768, "CapitalistImages/ref5.png", mTaxesWindow);
	mTaxesCloseButton		= std::make_shared<GUIButton>(235, 110, 100, 40, mTaxesWindow);
	mTaxesCloseImage		= std::make_shared<GUIImage> (235, 110, 100, 40, "CapitalistImages/button_okay.png", mTaxesWindow);
	mTaxesWindow->setVisible(false);

	mResourceWindow			= std::make_shared<GUIWindow>(227, 264 , 568, 165, mCapitalistMainWindow);
	mResourceImage			= std::make_shared<GUIImage> (-227, -264, 1024, 768, "CapitalistImages/ref6.png", mResourceWindow);
	mResourceCloseButton    = std::make_shared<GUIButton>(235, 110, 100, 40, mResourceWindow);
	mResourceCloseImage		= std::make_shared<GUIImage> (235, 110, 100, 40, "CapitalistImages/button_okay.png", mResourceWindow);
	mResourceWindow->setVisible(false);

	mUpgradeWindow			= std::make_shared<GUIWindow>(226, 79 , 568, 534, mCapitalistMainWindow);
	mUpgradeImage			= std::make_shared<GUIImage> (-226, -79, 1024, 768, "CapitalistImages/ref7.png", mUpgradeWindow);
	mUpgradeCloseButton		= std::make_shared<GUIButton>(236, 478, 100, 40, mUpgradeWindow);
	mUpgradeCloseImage		= std::make_shared<GUIImage> (236, 478, 100, 40, "CapitalistImages/button_okay.png", mUpgradeWindow);
	mUpgradeWindow->setVisible(false);

	mExportWindow			= std::make_shared<GUIWindow> (226, 79, 568, 534, mCapitalistMainWindow);
	mExportImage			= std::make_shared<GUIImage>  (-226, -79, 1024, 768, "CapitalistImages/ref8.png", mExportWindow);
	mExportCloseButton		 = std::make_shared<GUIButton>(236, 478, 100, 40, mExportWindow);
	mExportCloseImage		 = std::make_shared<GUIImage> (236, 478, 100, 40, "CapitalistImages/button_okay.png", mExportWindow);
	mExportWindow->setVisible(false);

	/*
	 	Lägger in föräldernoden i vektorn som finns i GUIManager
	 	och kommer automatiskt få med sig alla barnnoder till denna
	 	vilket är alla GUIElement som finns i denna klass som har 
	 	mC apitalistMainWindow som parent-argument i dess konstruktor
																		*/
	GUIManager::getInstance()->addGUIElement(mCapitalistMainWindow);
}

/*
	Ger alla GUIButton:s en funktion som körs när den klickas på

																	*/
void Capitalist::initializeGuiFunctions()
{
	mCapitalistTaxesButton->setOnClickFunction([=]() { mTaxesWindow->setVisible(true); });
	mCapitalistResourceButton->setOnClickFunction([=]() { mResourceWindow->setVisible(true); });
	mCapitalistUpgradeButton->setOnClickFunction([=]() { mUpgradeWindow->setVisible(true); });
	mCapitalistExportButton->setOnClickFunction([=]() { mExportWindow->setVisible(true); });

	mTaxesCloseButton->setOnClickFunction([=]() { mTaxesWindow->setVisible(false); });
	mResourceCloseButton->setOnClickFunction([=]() { mResourceWindow->setVisible(false); });
	mUpgradeCloseButton->setOnClickFunction([=]() { mUpgradeWindow->setVisible(false); });
	mExportCloseButton->setOnClickFunction([=]() { mExportWindow->setVisible(false); });
}

void Capitalist::showGUI()
{
	mCapitalistMainWindow->setVisible(false);
}

void Capitalist::hideGUI()
{
	mCapitalistMainWindow->setVisible(true);
}