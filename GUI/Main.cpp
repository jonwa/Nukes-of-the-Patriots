#include <SFML/Graphics.hpp>
#include "GUIManager.h"
#include "GUIElement.h"
#include "GUIWindow.h"
#include "GUIButton.h"
#include "GUIText.h"
#include "Capitalist.h"
#include <string>
#include <sstream>
#include <iostream>
#include <functional>

using namespace std;

std::string intToString(int i)
{
	std::stringstream converter;
	converter << i;
	return converter.str();
}

sf::RenderWindow window(sf::VideoMode(1024, 768, 32), "SFML works!", sf::Style::Fullscreen);

//Capitalist capitalist;
//GUIElement *menuWindow = new GUIWindow(0, 0, 500, 500);
//GUIElement *button1 = new GUIButton(100, 100, 100, 50, menuWindow);
//GUIElement *text1 = new GUIText(100, 100, "Testing...", menuWindow); // utritningar av text gör att programmet krashar när det stängs av; av någon anledning
//
//GUIElement *hideMenuWindow = new GUIButton(300, 500, 100, 50, menuWindow);
//GUIElement *showMenuWindow = new GUIButton(500, 500, 100, 50, menuWindow);
//GUIElement *text2 = new GUIText(0, 0, "Close window", hideMenuWindow);
//GUIElement *text3 = new GUIText(0, 0, "Show window", showMenuWindow);


//TESTAR OM UPPGRADERING AV NUCLEAR FUNKAR: KAN TAS BORT SNART
//GUIElement *add = new GUIButton(50, 50, 50, 20);
//GUIElement *addera = new GUIText(20, 20, "+", menuWindow);

//GUIElement *nuclearWeapon = new GUIText(0, 300, "Nuclear Weapon: " + intToString(capitalist.getNuclearWeapon()), menuWindow);

//struct Test
//{
//	void onMouseClick(GUIElement *guiElement){
//		if(guiElement == hideMenuWindow)
//			std::cout << capitalist.getCurrency() << std::endl;
//
//		/*if(guiElement == nuclearWeapon)
//			std::cout << capitalist.getNuclearWeapon() << std::endl*/;
//	}
//};
//
//// Här hanteras alla tryckningar på gui element - Windows style
//void onGUIClick(GUIElement *guiElement)
//{
//	
//	
//	if(guiElement == hideMenuWindow)
//	{
//		//EventHandler::openCommunistUpgradeMenu(capitalist, guiManager);
//		menuWindow->setVisible(false);
//	}
//	else if(guiElement == showMenuWindow && showMenuWindow->getVisible() == true)
//	{
//		menuWindow->setVisible(true);
//	}
//
//	/*else if(guiElement == addera)
//	{
//		capitalist.upgradeNuclearWeapon();
//	}*/
//}



int a(double);
int b(double);

int main()
{

	Capitalist capitalist;

	capitalist.render();
	//Test test;
	
	std::function <void (GUIElement*)> Function = std::bind(&Capitalist::update, capitalist, std::placeholders::_1);
	
//	text1->setScale(0.5, 1);
	/*text2->setScale(0.5, 1);
	text3->setScale(0.5, 1);
	guiManager.addGUIElement(menuWindow);*/
	//guiManager.addGUIElement(button1);
	//guiManager.addGUIElement(text1);
	//guiManager.addGUIElement(hideMenuWindow);
	//guiManager.addGUIElement(showMenuWindow);
	//guiManager.addGUIElement(text2);
	//guiManager.addGUIElement(text3);
	//guiManager.addGUIElement(nuclearWeapon);

	//TESTAR BARA OM UPPGRADERING AV NUCLEAR FUNGERAR: KAN TAS BORT
	//guiManager.addGUIElement(add);
	//guiManager.addGUIElement(addera);

	GUIManager::getInstance()->addOnMouseClickEventHandler(Function);
//	guiManager.addOnMouseClickEventHandler(Function);
	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			GUIManager::getInstance()->update();
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        window.clear();
		GUIManager::getInstance()->render(&window);

        window.display();
    }
    return EXIT_SUCCESS;
}