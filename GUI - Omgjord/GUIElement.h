#ifndef _GUIElement_H
#define _GUIElement_H
/*
	Basklass för alla GUIElement: GUIWindow, GUIButton, GUIImage, GUIText.

	Av: Aleksi Lindman
		Arvid Backman
							*/

#include <SFML\Graphics.hpp>
#include <memory>
#include <vector>
#include <functional>
enum	GUIType{WINDOW, BUTTON, TEXT, IMAGE};

class GUIElement : public std::enable_shared_from_this<GUIElement>
{
public:
	GUIElement(int x, int y, int width, int height, std::shared_ptr<GUIElement> parent, GUIType guiType);
	int				getX()const;
	int				getY()const;
	int				getWidth()const;
	int				getHeight()const;
	bool			getVisible()const;
	std::shared_ptr<GUIElement> getParent()const;
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
	void			addChild(std::shared_ptr<GUIElement> guiElement);
	std::shared_ptr<GUIElement> getPtr();
	std::vector<std::shared_ptr<GUIElement>>& getChildVector();

	virtual void	setScale(float width, float height) {}
	void			setOnClickFunction(std::function<void ()>);
	void			setMouseEnterFunction(std::function<void ()>);
	void			setMouseLeaveFunction(std::function<void ()>);
	virtual void	update();
	virtual void	render(sf::RenderWindow &window) = 0;
	virtual			~GUIElement();
protected:
	int mX, mY, mWidth, mHeight, mAlpha;
	bool mVisible, mMouseInside;
	std::shared_ptr<GUIElement> mParent;
	GUIType mGUIType;

	std::function<void ()> mOnClickFunction;
	std::function<void ()> mMouseEnterFunction;
	std::function<void ()> mMouseLeaveFunction;
	
	std::vector<std::shared_ptr<GUIElement>> mChilds;
};

#endif