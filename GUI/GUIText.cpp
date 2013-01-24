#include "GUIText.h"
#include <SFML\System\String.hpp>
#include <iostream>

GUIText::GUIText(int x, int y, std::string text, GUIElement *parent) :
	GUIElement(x, y, 0, 0, parent, GUIType::Text),
	mFont(sf::Font::getDefaultFont())
{
	mText.setFont(mFont);
	mText.setString(text);
	sf::FloatRect boundBox = mText.getGlobalBounds();
	setWidth(boundBox.width);
	setHeight(boundBox.height);
}

void GUIText::setText(std::string text)
{
	mText.setString(sf::String(text.c_str()));
	sf::FloatRect boundBox = mText.getGlobalBounds();
	setWidth(boundBox.width);
	setHeight(boundBox.height);
}

void GUIText::setScale(float width, float height)
{
	mText.setScale(width, height);
	sf::FloatRect boundBox = mText.getGlobalBounds();
	setWidth(boundBox.width);
	setHeight(boundBox.height);
}

void GUIText::render(sf::RenderWindow *window)
{
	float x = getX(), y = getY();
	bool visible = getVisible();
	GUIElement *parent = getParent();
	while(parent != NULL)
	{
		x += parent->getX();
		y += parent->getY();
		visible = parent->getVisible();
		if(!visible)
			break;
		parent = parent->getParent();
	}
	if(visible)
	{
		mText.setColor(sf::Color::Color(0, 255, 0, 255));
		mText.setPosition(sf::Vector2f(x, y));
		window->draw(mText);
		std::cout << "BLBALBALBALBA" << std::endl;
	}

	

	/*if(!mChilds.empty())
	{
		for(std::vector<GUIElement*>::size_type i = 0; i < mChilds.size(); ++i)
		{
			mChilds[i]->render(window);
		}
	}*/
}