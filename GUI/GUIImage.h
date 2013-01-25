<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> e8055fcf44317e4746a3cdb3e75fce869a1dc5ea
/*
 *  GUIImage anv�nds f�r att ladda in bilder 
 *  denna anv�nder i sin tur ResourceHandler f�r att l�gga in dessa
 *  bilder i std::map av sf::Images
 *
 *
 *		Av : Jon Wahlstr�m 
 *           Arvid Backman
 *
 *		2013-01-22
 */


#ifndef GUIIMAGE_H
#define GUIIMAGE_H

#include "GUIElement.h"

class GUIImage : public GUIElement
{
public:
	GUIImage(int x, int y, int width, int height, std::string string, std::shared_ptr<GUIElement> parent = 0);

	~GUIImage(){}

	sf::Sprite getImage() const;

	void setImage(std::string &string);
	void setScale(float width, float height);

	void render (sf::RenderWindow &window);
	
private:
	sf::Texture mTexture;
	sf::Sprite mSprite;
};

<<<<<<< HEAD
=======
/*
 *  GUIImage anv�nds f�r att ladda in bilder 
 *  denna anv�nder i sin tur ResourceHandler f�r att l�gga in dessa
 *  bilder i std::map av sf::Images
 *
 *
 *		Av : Jon Wahlstr�m 
 *           Arvid Backman
 *
 *		2013-01-22
 */


#ifndef GUIIMAGE_H
#define GUIIMAGE_H

#include "GUIElement.h"

class GUIImage : public GUIElement
{
public:
	GUIImage(int x, int y, int width, int height, std::string string, std::shared_ptr<GUIElement> parent = 0);

	~GUIImage(){}

	sf::Sprite getImage() const;

	void setImage(std::string &string);
	void setScale(float width, float height);

	void render (sf::RenderWindow *window);
	
private:
	sf::Texture mTexture;
	sf::Sprite mSprite;
};

>>>>>>> parent of 5c595d1... asdasd
=======
>>>>>>> e8055fcf44317e4746a3cdb3e75fce869a1dc5ea
#endif