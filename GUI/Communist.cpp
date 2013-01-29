#include "Communist.h"
#include "GUIManager.h"
#include "GUIWindow.h"
#include "GUIButton.h"
#include "GUIImage.h"
#include "GUIText.h"

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
	mIncreasePopulation = false;

	initializeCommunistWindow();
}


Communist::~Communist()
{
}

//-------------------------------------
/*Funktioner som returnerar medlemsvariablernas värden*/

//President Communist::getPresident()
//{
//	return mPresident;
//}

//--------------------------------------------
/*Funktioner som ger medlemsvariabler nya värden*/

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
	Kostar 5 mGoods multiplicerat med den nuvarande nivån
	och 10 mTech multiplicerat med den nuvarande nivån*/
void Communist::upgradeSpaceProgram()
{
	++mSpaceProgram;

	mGoods	-= 5 * mSpaceProgram;
	mTech	-= 10 * mSpaceProgram;
}

/*	Uppgraderar mSpyNetwork med ett
	Kostar 10 mTech multiplicerat med den nuvarande nivån*/
void Communist::upgradeSpyNetwork()
{
	++mSpyNetwork;

	mTech -= 10 * mSpyNetwork;
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

void Communist::showGUI()
{
	mCommunistMainWindow->setVisible(false);
}

void Communist::hideGUI()
{
	mCommunistMainWindow->setVisible(true);
}