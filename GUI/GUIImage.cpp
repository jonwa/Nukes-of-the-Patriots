#include "GUIImage.h"
#include "ResourceHandler.h"

GUIImage::GUIImage(int x, int y, int width, int height, std::string string, std::shared_ptr<GUIElement> parent) : 
	GUIElement(x, y, width, height, parent, GUIType::Image)
{
	setImage(string);	
}


sf::Sprite GUIImage::getImage()const
{
	return	mSprite;
}

/*
 * Anv�nds f�r att l�gga till en bild i mappen genom att ange en str�ng(filens namn)
 * Laddar in en bild via en textur i resurshanterar-klassens std::map och sedan
 * tilldela en sprite denna textur.
 */
void GUIImage::setImage(std::string& string)
{
	mTexture.loadFromImage(*ResourceHandler::getInstance()->loadImage(string));
	mSprite.setTexture(mTexture);
	mSprite.setPosition(mX, mY);
	sf::FloatRect boundBox = mSprite.getGlobalBounds();
	setWidth(boundBox.width);
	setHeight(boundBox.height);
}

/*
 * M�jligg�r en omskalning av den angivna bilden
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
void GUIImage::render(sf::RenderWindow &window)
{
	bool visible = getVisible();
	std::shared_ptr<GUIElement> parent = getParent();
	while(parent != NULL)
	{
		visible = parent->getVisible();
		if(!visible)
		{
			break;
		}
		parent = parent->getParent();
	}
	if(visible)
	{
		window.draw(mSprite);
	}
}