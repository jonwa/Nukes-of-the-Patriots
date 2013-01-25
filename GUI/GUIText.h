<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> e8055fcf44317e4746a3cdb3e75fce869a1dc5ea
#ifndef _GUI_TEXT_H
#define _GUI_TEXT_H

#include "GUIElement.h"
#include <string>

class GUIText: public GUIElement
{
public:
				GUIText(int x, int y, std::string text, std::shared_ptr<GUIElement> parent = 0);
	std::string getText()const{ return mText.getString(); }
	void		setText(std::string text);
	void		setScale(float width, float height);
	void		render(sf::RenderWindow &window);
				~GUIText(){}
private:
	sf::Text mText;
	sf::Font mFont;
};

<<<<<<< HEAD
=======
#ifndef _GUI_TEXT_H
#define _GUI_TEXT_H

#include "GUIElement.h"
#include <string>

class GUIText: public GUIElement
{
public:
				GUIText(int x, int y, std::string text, std::shared_ptr<GUIElement> parent = 0);
	std::string getText()const{ return mText.getString(); }
	void		setText(std::string text);
	void		setScale(float width, float height);
	void		render(sf::RenderWindow *window);
				~GUIText(){}
private:
	sf::Text mText;
	sf::Font mFont;
};

>>>>>>> parent of 5c595d1... asdasd
=======
>>>>>>> e8055fcf44317e4746a3cdb3e75fce869a1dc5ea
#endif