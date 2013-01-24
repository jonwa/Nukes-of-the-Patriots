#include "GUIImage.h"
#include "ResourceHandler.h"

GUIImage::GUIImage(int x, int y, int width, int height, std::string string, GUIElement *parent) : 
	GUIElement(x, y, width, height, parent, GUIType::Image)
{
	setImage(string);	
}


sf::Sprite GUIImage::getImage()const
{
	return	mSprite;
}

/*
 * Används för att lägga till en bild i mappen genom att ange en sträng(filens namn)
 * Laddar in en bild via en textur i resurshanterar-klassens std::map och sedan
 * tilldela en sprite denna textur.
 */
void GUIImage::setImage(std::string& string)
{
	mTexture.loadFromImage(*ResourceHandler::getInstance()->loadImage(string));
	mSprite.setTexture(mTexture);
	sf::FloatRect boundBox = mSprite.getGlobalBounds();
	setWidth(boundBox.width);
	setHeight(boundBox.height);
}

/*
 * Möjliggör en omskalning av den angivna bilden
 */
void GUIImage::setScale(float width, float height)
{
	mSprite.setScale(width, height);
	sf::FloatRect boundBox = mSprite.getGlobalBounds();
	setWidth(boundBox.width);
	setHeight(boundBox.height);
}

/*
 * 
 *
 */
void GUIImage::render(sf::RenderWindow * window)
{
	float x = getX();
	float y = getY();
	bool visible = getVisible();
	GUIElement *parent = getParent();
	while(parent != NULL)
	{
		x += parent->getX();
		y += parent->getY();
		visible = parent->getVisible();
		if(!visible)
		{
			break;
		}

		parent = parent->getParent();
	}

	if(visible)
	{
		mSprite.setPosition(sf::Vector2f(x, y));
		window->draw(mSprite);
	}
}