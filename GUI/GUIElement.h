#ifndef _GUIElement_H
#define _GUIElement_H

#include <SFML\Graphics.hpp>
#include <vector>
enum			GUIType{Window, Button, Text, Image};

class GUIElement
{
public:

					GUIElement(int x, int y, int width, int height, GUIElement *parent, GUIType guiType);
	int				getX()const;
	int				getY()const;
	int				getWidth()const;
	int				getHeight()const;
	bool			getVisible()const;
	GUIElement *	getParent()const;
	GUIType			getGUIType()const;
	int				getAlpha()const;
	bool			getMouseIsInside()const;

	void			setX(int x);
	void			setY(int y);
	void			setWidth(int width);
	void			setHeight(int height);
	void			setVisible(bool visible);
	void			setAlpha(int alpha);
	void			setMouseIsInside(bool inside);
	void			addChild(GUIElement *guiElement);
	std::vector<GUIElement*>& getChildVector();

	virtual void	setScale(float width, float height) = 0;
	virtual void	render(sf::RenderWindow *window) = 0;
	virtual			~GUIElement(){}
protected:
	int mX, mY, mWidth, mHeight, mAlpha;
	bool mVisible, mMouseInside;
	GUIElement *mParent;
	GUIType mGUIType;
	
	std::vector<GUIElement*> mChilds;
};

#endif