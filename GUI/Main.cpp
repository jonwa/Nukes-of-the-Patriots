#include <SFML/Graphics.hpp>
#include <SFML\Window\Mouse.hpp>
#include "GUIManager.h"
#include "GUIElement.h"
#include "GUIWindow.h"
#include "GUIButton.h"
#include "GUIText.h"
#include "Capitalist.h"
#include "Communist.h"
#include <string>
#include <sstream>
#include <iostream>
#include <functional>

using namespace std;

sf::RenderWindow window(sf::VideoMode(1024, 768, 32), "SFML works!", sf::Style::Fullscreen);


int main()
{

	//Communist communist;
	Capitalist capitalist;
	std::function <void (std::shared_ptr<GUIElement>)> capitalistFunctions	= std::bind(&Capitalist::onGUIClick, capitalist, std::placeholders::_1);

	GUIManager::getInstance()->addOnMouseClickEventHandler(capitalistFunctions);

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
		GUIManager::getInstance()->render(window);

        window.display();
    }
    return EXIT_SUCCESS;
}