#include <SFML\Graphics.hpp>
#include <SFML\Window\Mouse.hpp>
#include "GUIManager.h"
#include "GUIElement.h"
#include "GUIWindow.h"
#include "GUIButton.h"
#include "GUIText.h"
#include "Capitalist.h"
#include "Communist.h"
#include "Menu.h"
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include "ResourceHandler.h"


using namespace std;

sf::RenderWindow window(sf::VideoMode(1024, 768, 32), "SFML works!", sf::Style::Fullscreen);

int main()
{
	ResourceHandler::getInstance()->load();
	//Communist communist;
	//Capitalist capitalist;
	Menu menu(window);
	

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