//#include "Menu.h"
//#include "GUIManager.h"
//#include <SFML\Window\Mouse.hpp>
//
///*Konstruktorn kör initialize-funktionen*/
//Menu::Menu(sf::RenderWindow &window) :
//	mWindow(window)	{ initialize(); }
//Menu::~Menu(){}
//
// /*
//	Initierar menyernas fönster, bilder samt knappar som skall finnas med.
//	dessa är av olika typer av GUIElement. Beroende på vilken knapp som 
//	blir vald så kommer olika GUIWindow att renderas ut som i detta fall
//	representerar de olika menyernas fönster. 
//
//	Av: Jon Wahlström  2013-28-01
//																		*/
//void Menu::initialize()
//{
//	/*Förälder-fönstret för alla menyer*/
//	mParentWindow		= std::make_shared<GUIWindow>(0, 0, 1024, 768);
//
//	/*Fönstret och dess barn för LOGOMENU*/
//	mLogoMenuWindow		= std::make_shared<GUIWindow>(0, 0, 0, 0, mWindow);
//	mLogoMenuImage		= std::make_shared<GUIImage>(0, 0, 0, 0, " ", mLogoMenuWindow);
//
//	/*Fönstret och dess barn för SPLASHSCREEN*/
//	mSplashScreenWindow = std::make_shared<GUIWindow>(0, 0, 0, 0, mWindow);
//	mSplashScreenImage  = std::make_shared<GUIImage>(0, 0, 0, 0, " ", mSplashScreenWindow);
//	mSplashScreenWindow->setVisible(false);
//
//	/*Fönstret och dess barn för MAIN MENU*/
//	mMainMenuWindow		= std::make_shared<GUIWindow>(0, 0, 0, 0, mWindow);
//	mMainMenuImage		= std::make_shared<GUIImage>(0, 0, 0, 0, " ", mMainMenuWindow);
//	mStartNewGameButton = std::make_shared<GUIButton>(0, 0, 0, 0, mMainMenuWindow);
//	mLoadGameButton		= std::make_shared<GUIButton>(0, 0, 0, 0, mMainMenuWindow);
//	mSettingsButton		= std::make_shared<GUIButton>(0, 0, 0, 0, mMainMenuWindow);
//	mCreditsButton		= std::make_shared<GUIButton>(0, 0, 0, 0, mMainMenuWindow);
//	mExitButton			= std::make_shared<GUIButton>(0, 0, 0, 0, mMainMenuWindow);
//	mMainMenuWindow->setVisible(false);
//
//	/*Fönstret och dess barn för SETTINGS MENU*/
//	mSettingsMenuWindow	= std::make_shared<GUIWindow>(0, 0, 0, 0, mWindow);
//	mSettingsMenuImage	= std::make_shared<GUIImage>(0, 0, 0, 0, " ", mSettingsMenuWindow);
//	mSettingsMenuWindow->setVisible(false);
//
//	/*Fönstret och dess barn för CREDITS MENU*/
//	mCreditsMenuWindow  = std::make_shared<GUIWindow>(0, 0, 0, 0, mWindow);
//	mCreditsMenuImage   = std::make_shared<GUIImage>(0, 0, 0, 0, " ", mCreditsMenuWindow);
//	mCreditsMenuWindow->setVisible(false);
//
//	/*Lägger in fönstrerna i vectorn för GUIElement*/
//	GUIManager::getInstance()->addGUIElement(mParentWindow);
//}
//
// /*
//	Initierar lambda funktioner för GUIknapparna. Alltså vad som skall
//	hända då dessa har blivit tryckta på. 
//
//	  Av: Jon Wahlström  2013-29-01
//																	*/
//void Menu::initializeGUIFuctions()
//{
//	mStartNewGameButton->setOnClickFunction([=]() {} );
//	mLoadGameButton->setOnClickFunction([=]() {});
//	mSettingsButton->setOnClickFunction([=]() {});
//	mCreditsButton->setOnClickFunction([=]() {});
//	mExitButton->setOnClickFunction([=]() { mWindow.close(); });
//}