//#include "Menu.h"
//#include "GUIManager.h"
//#include "tinyxml2.h"
//#include <sstream>
//#include <iostream>
//#include <SFML\Window\Mouse.hpp>
//#include "Capitalist.h"
// /*Konstruktorn k�r initialize-funktionen*/
//Menu::Menu(sf::RenderWindow &window) :
//	mWindow(window)	{ initialize(); }
//Menu::~Menu(){}
//
//
// /*Laddar in menyknapparnas positions- och storleksinformation
//   fr�n ett externbibliotek kallat tinyXML2
//   
//     Av: Jon Wahlstr�m 2013-30-01*/
//void Menu::loadButtonPosition()
//{
//	tinyxml2::XMLDocument doc;
//	doc.LoadFile("XML/MenuButton.xml");
//
//	if(doc.Error())
//		std::cout << "Fel!";
//	
//	tinyxml2::XMLElement *element = doc.FirstChildElement("menu");
//	tinyxml2::XMLElement *button = element->FirstChildElement("button");
//	while (button != 0)
//	{
//		std::string tempName = button->FirstChildElement("name")->GetText();
//		float posX			 = atof(button->FirstChildElement("xPos")->GetText());
//		float posY			 = atof(button->FirstChildElement("yPos")->GetText());
//		float Width			 = atof(button->FirstChildElement("width")->GetText());
//		float Height		 = atof(button->FirstChildElement("height")->GetText());
//				
//		ButtonPos[tempName].left = posX;
//		ButtonPos[tempName].top = posY;
//		ButtonPos[tempName].width = Width;
//		ButtonPos[tempName].height = Height;
//
//		button = button->NextSiblingElement();
//	}
//}
//
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
//	mParentWindow		= std::make_shared<GUIWindow>(sf::FloatRect(0, 0, 1024, 768));
//
//	/*F�nstret och dess barn f�r LOGOMENU*/
//	mLogoMenuWindow		= std::make_shared<GUIWindow>(sf::FloatRect(0, 0, 0, 0), mWindow);
//	mLogoMenuImage		= std::make_shared<GUIImage>(sf::FloatRect(0, 0, 0, 0), " ", mLogoMenuWindow);
//
//	/*F�nstret och dess barn f�r SPLASHSCREEN*/
//	mSplashScreenWindow = std::make_shared<GUIWindow>(sf::FloatRect(0, 0, 0, 0), mWindow);
//	mSplashScreenImage  = std::make_shared<GUIImage>(sf::FloatRect(0, 0, 0, 0), " ", mSplashScreenWindow);
//	mSplashScreenWindow->setVisible(false);
//
//	/*F�nstret och dess barn f�r MAIN MENU*/
//	mMainMenuWindow		= std::make_shared<GUIWindow>(sf::FloatRect(0, 0, 0, 0), mWindow);
//	mMainMenuImage		= std::make_shared<GUIImage> (sf::FloatRect(0, 0, 0, 0), " ", mMainMenuWindow);
//	mStartNewGameButton = std::make_shared<GUIButton>(ButtonPos["StartGame"], mMainMenuWindow);
//	mLoadGameButton		= std::make_shared<GUIButton>(ButtonPos["LoadGame"], mMainMenuWindow);
//	mSettingsButton		= std::make_shared<GUIButton>(ButtonPos["Settings"], mMainMenuWindow);
//	mCreditsButton		= std::make_shared<GUIButton>(ButtonPos["Credits"], mMainMenuWindow);
//	mExitButton			= std::make_shared<GUIButton>(ButtonPos["Exit"], mMainMenuWindow);
//	mMainMenuWindow->setVisible(false);
//
//	/*F�nstret och dess barn f�r SETTINGS MENU*/
//	mSettingsMenuWindow	= std::make_shared<GUIWindow>(sf::FloatRect(0, 0, 0, 0), mWindow);
//	mSettingsMenuImage	= std::make_shared<GUIImage>(sf::FloatRect(0, 0, 0, 0), " ", mSettingsMenuWindow);
//	mSettingsMenuWindow->setVisible(false);
//
//	/*F�nstret och dess barn f�r CREDITS MENU*/
//	mCreditsMenuWindow  = std::make_shared<GUIWindow>(sf::FloatRect(0, 0, 0, 0), mWindow);
//	mCreditsMenuImage   = std::make_shared<GUIImage>(sf::FloatRect(0, 0, 0, 0), " ", mCreditsMenuWindow);
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
//	mStartNewGameButton->setOnClickFunction([=]()   { mMainMenuWindow->setVisible(false); capitalist.initializeCapitalistWindow(); } );
//	mLoadGameButton->setOnClickFunction([=]()		{});
//	mSettingsButton->setOnClickFunction([=]()		{ mMainMenuWindow->setVisible(false); mSettingsMenuWindow->setVisible(true);});
//	mCreditsButton->setOnClickFunction([=]()		{ mMainMenuWindow->setVisible(false); mCreditsMenuWindow->setVisible(true);});
//	mExitButton->setOnClickFunction([=]()			{ mWindow.close(); });
//}