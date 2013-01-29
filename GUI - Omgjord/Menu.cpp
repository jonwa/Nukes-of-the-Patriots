//#include "Menu.h"
//#include "GUIManager.h"
//#include <SFML\Window\Mouse.hpp>
//
///*Konstruktorn k�r initialize-funktionen*/
//Menu::Menu(sf::RenderWindow &window) :
//	mWindow(window)	{ initialize(); }
//Menu::~Menu(){}
//
// /*
//	Initierar menyernas f�nster, bilder samt knappar som skall finnas med.
//	dessa �r av olika typer av GUIElement. Beroende p� vilken knapp som 
//	blir vald s� kommer olika GUIWindow att renderas ut som i detta fall
//	representerar de olika menyernas f�nster. 
//
//	Av: Jon Wahlstr�m  2013-28-01
//																		*/
//void Menu::initialize()
//{
//	/*F�r�lder-f�nstret f�r alla menyer*/
//	mParentWindow		= std::make_shared<GUIWindow>(0, 0, 1024, 768);
//
//	/*F�nstret och dess barn f�r LOGOMENU*/
//	mLogoMenuWindow		= std::make_shared<GUIWindow>(0, 0, 0, 0, mWindow);
//	mLogoMenuImage		= std::make_shared<GUIImage>(0, 0, 0, 0, " ", mLogoMenuWindow);
//
//	/*F�nstret och dess barn f�r SPLASHSCREEN*/
//	mSplashScreenWindow = std::make_shared<GUIWindow>(0, 0, 0, 0, mWindow);
//	mSplashScreenImage  = std::make_shared<GUIImage>(0, 0, 0, 0, " ", mSplashScreenWindow);
//	mSplashScreenWindow->setVisible(false);
//
//	/*F�nstret och dess barn f�r MAIN MENU*/
//	mMainMenuWindow		= std::make_shared<GUIWindow>(0, 0, 0, 0, mWindow);
//	mMainMenuImage		= std::make_shared<GUIImage>(0, 0, 0, 0, " ", mMainMenuWindow);
//	mStartNewGameButton = std::make_shared<GUIButton>(0, 0, 0, 0, mMainMenuWindow);
//	mLoadGameButton		= std::make_shared<GUIButton>(0, 0, 0, 0, mMainMenuWindow);
//	mSettingsButton		= std::make_shared<GUIButton>(0, 0, 0, 0, mMainMenuWindow);
//	mCreditsButton		= std::make_shared<GUIButton>(0, 0, 0, 0, mMainMenuWindow);
//	mExitButton			= std::make_shared<GUIButton>(0, 0, 0, 0, mMainMenuWindow);
//	mMainMenuWindow->setVisible(false);
//
//	/*F�nstret och dess barn f�r SETTINGS MENU*/
//	mSettingsMenuWindow	= std::make_shared<GUIWindow>(0, 0, 0, 0, mWindow);
//	mSettingsMenuImage	= std::make_shared<GUIImage>(0, 0, 0, 0, " ", mSettingsMenuWindow);
//	mSettingsMenuWindow->setVisible(false);
//
//	/*F�nstret och dess barn f�r CREDITS MENU*/
//	mCreditsMenuWindow  = std::make_shared<GUIWindow>(0, 0, 0, 0, mWindow);
//	mCreditsMenuImage   = std::make_shared<GUIImage>(0, 0, 0, 0, " ", mCreditsMenuWindow);
//	mCreditsMenuWindow->setVisible(false);
//
//	/*L�gger in f�nstrerna i vectorn f�r GUIElement*/
//	GUIManager::getInstance()->addGUIElement(mParentWindow);
//}
//
// /*
//	Initierar lambda funktioner f�r GUIknapparna. Allts� vad som skall
//	h�nda d� dessa har blivit tryckta p�. 
//
//	  Av: Jon Wahlstr�m  2013-29-01
//																	*/
//void Menu::initializeGUIFuctions()
//{
//	mStartNewGameButton->setOnClickFunction([=]() {} );
//	mLoadGameButton->setOnClickFunction([=]() {});
//	mSettingsButton->setOnClickFunction([=]() {});
//	mCreditsButton->setOnClickFunction([=]() {});
//	mExitButton->setOnClickFunction([=]() { mWindow.close(); });
//}