#include "GUIText.h"
#include <SFML\System\String.hpp>
#include <iostream>

GUIText::GUIText(int x, int y, std::string text, std::shared_ptr<GUIElement> parent) :
	GUIElement(x, y, 0, 0, parent, TEXT),
	mFont(sf::Font::getDefaultFont())
{
	mText.setFont(mFont);
	mText.setString(text);
	sf::FloatRect boundBox = mText.getGlobalBounds();
	setWidth(static_cast<int>(boundBox.width));
	setHeight(static_cast<int>(boundBox.height));
}

void GUIText::setText(std::string text)
{
	mText.setString(sf::String(text.c_str()));
	sf::FloatRect boundBox = mText.getGlobalBounds();
	setWidth(static_cast<int>(boundBox.width));
	setHeight(static_cast<int>(boundBox.height));
}

void GUIText::setScale(float width, float height)
{
	mText.setScale(width, height);
	sf::FloatRect boundBox = mText.getGlobalBounds();
	setWidth(static_cast<int>(boundBox.width));
	setHeight(static_cast<int>(boundBox.height));
}

void GUIText::render(sf::RenderWindow &window)
{
	bool visible = getVisible();
	std::shared_ptr<GUIElement> parent = getParent();
	while(parent != NULL)
	{
		visible = parent->getVisible();
		if(!visible)
			break;
		parent = parent->getParent();
	}
	if(visible)
	{
		float x = static_cast<float>(getX());
		float y = static_cast<float>(getY());
		mText.setColor(sf::Color::Color(0, 255, 255, 255));
		mText.setPosition((sf::Vector2f(x, y)));
		window.draw(mText);
	}

	

	/*if(!mChilds.empty())
	{
		for(std::vector<GUIElement*>::size_type i = 0; i < mChilds.size(); ++i)
		{
			mChilds[i]->render(window);
		}
	}*/
}