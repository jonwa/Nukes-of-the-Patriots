#include "Capitalist.h"
#include "GUIElement.h"
#include "GUIManager.h"
#include "GUIWindow.h"
#include "GUIButton.h"
#include "GUIImage.h"
#include "GUIText.h"

#include <SFML\Window\Mouse.hpp>

Capitalist::Capitalist()
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
	mIncreasePopulation = false;


	initializeCapitalistWindow();
}


Capitalist::~Capitalist()
{
}

//President Capitalist::getPresident()
//{
//	return mPresident;
//}


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



	mNuclearText->setText(intToString(mNuclearWeapon));
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

	mFoodText		= std::make_shared<GUIText> (160, 16, intToString(mFood), mCapitalistMainWindow);
	mNuclearText	= std::make_shared<GUIText> (962, 16, intToString(mNuclearWeapon), mCapitalistMainWindow);

	mTaxesWindow			= std::make_shared<GUIWindow>(227, 264, 570, 168, mCapitalistMainWindow);
	mTaxesImage				= std::make_shared<GUIImage> (-227, -264, 1024, 768, "CapitalistImages/ref5.png", mTaxesWindow);
	mTaxesCloseButton		= std::make_shared<GUIButton>(235, 110, 100, 40, mTaxesWindow);
	mTaxesCloseImage		= std::make_shared<GUIImage> (235, 110, 100, 40, "CapitalistImages/button_okay.png", mTaxesWindow);

	mResourceWindow			= std::make_shared<GUIWindow>(227, 264 , 568, 165, mCapitalistMainWindow);
	mResourceImage			= std::make_shared<GUIImage> (-227, -264, 1024, 768, "CapitalistImages/ref6.png", mResourceWindow);
	mResourceCloseButton    = std::make_shared<GUIButton>(235, 110, 100, 40, mResourceWindow);
	mResourceCloseImage		= std::make_shared<GUIImage> (235, 110, 100, 40, "CapitalistImages/button_okay.png", mResourceWindow);

	mUpgradeWindow			= std::make_shared<GUIWindow>(226, 79 , 568, 534, mCapitalistMainWindow);
	mUpgradeImage			= std::make_shared<GUIImage> (-226, -79, 1024, 768, "CapitalistImages/ref7.png", mUpgradeWindow);
	mUpgradeCloseButton		= std::make_shared<GUIButton>(236, 478, 100, 40, mUpgradeWindow);
	mUpgradeCloseImage		= std::make_shared<GUIImage> (236, 478, 100, 40, "CapitalistImages/button_okay.png", mUpgradeWindow);

	mExportWindow			= std::make_shared<GUIWindow> (226, 79, 568, 534, mCapitalistMainWindow);
	mExportImage			= std::make_shared<GUIImage>  (-226, -79, 1024, 768, "CapitalistImages/ref8.png", mExportWindow);
	mExportCloseButton		 = std::make_shared<GUIButton>(236, 478, 100, 40, mExportWindow);
	mExportCloseImage		 = std::make_shared<GUIImage> (236, 478, 100, 40, "CapitalistImages/button_okay.png", mExportWindow);

	/*
	 	Lägger in föräldernoden i vektorn som finns i GUIManager
	 	och kommer automatiskt få med sig alla barnnoder till denna
	 	vilket är alla GUIElement som finns i denna klass som har 
	 	mCapitalistMainWindow som parent-argument i dess konstruktor
																		*/
	GUIManager::getInstance()->addGUIElement(mCapitalistMainWindow);
}

/*
  Om vänster musknapp har blivit nedtryckt och GUI elementet är en existerande knapp
  kommer denna att kalla på sin open menu funktion för att initiera ett nytt fönster med nya
  menyval beroende på vilken knapp som blivit vald.
 
 		Av: Jon Wahlström	2013-23-01
																		*/
void Capitalist::onGUIClick(std::shared_ptr<GUIElement> guiElement)
{
	if(guiElement == mCapitalistTaxesButton)
	{
		openTaxesMenu();
	}

	else if(guiElement == mTaxesCloseButton)
	{
		closeTaxesMenu();
	}

	else if(guiElement == mCapitalistResourceButton)
	{
		openResourceMenu();
	}

	else if(guiElement == mResourceCloseButton)
	{
		closeResourceMenu();
	}

	else if(guiElement == mCapitalistUpgradeButton)
	{
		openUpgradeMenu();
	}

	else if(guiElement == mUpgradeCloseButton)
	{
		closeUpgradeMenu();
	}

	else if(guiElement == mCapitalistExportButton)
	{
		openExportMenu();
	}

	else if(guiElement == mExportCloseButton)
	{
		closeExportMenu();
	}
}

/*
	Dessa funktioner kallas då menyfönstret väljs att stängas ner eller öppnas upp. 
	Det den gör är att sätta fönstrets synlighet till false/true och 
	därmed kommer fönstrets barnnoder även dem att sättas till false/true
		
		Av: Jon Wahlström 2013-24-01
			Arvid Backman 2013-28-01
																*/
void Capitalist::openTaxesMenu()
{
	mTaxesWindow->setVisible(true);
}

void Capitalist::closeTaxesMenu()
{
	mTaxesWindow->setVisible(false);
}

void Capitalist::openResourceMenu()
{
	mResourceWindow->setVisible(true);
}

void Capitalist::closeResourceMenu()
{
	mResourceWindow->setVisible(false);
}

void Capitalist::openUpgradeMenu()
{
	mUpgradeWindow->setVisible(true);
}

void Capitalist::closeUpgradeMenu()
{
	mUpgradeWindow->setVisible(false);
}

void Capitalist::openExportMenu()
{
	mExportWindow->setVisible(true);
} 

void Capitalist::closeExportMenu()
{
	mExportWindow->setVisible(false);
}

void Capitalist::showGUI()
{
	mCapitalistMainWindow->setVisible(false);
}

void Capitalist::hideGUI()
{
	mCapitalistMainWindow->setVisible(true);
}