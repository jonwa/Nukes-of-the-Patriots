<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> e8055fcf44317e4746a3cdb3e75fce869a1dc5ea
#ifndef _GUIElement_H
#define _GUIElement_H

#include <SFML\Graphics.hpp>
#include <memory>
#include <vector>
enum	GUIType{Window, Button, Text, Image};

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
	virtual void	render(sf::RenderWindow &window) {}
	virtual			~GUIElement();
protected:
	int mX, mY, mWidth, mHeight, mAlpha;
	bool mVisible, mMouseInside;
	std::shared_ptr<GUIElement> mParent;
	GUIType mGUIType;
	
	std::vector<std::shared_ptr<GUIElement>> mChilds;
};

<<<<<<< HEAD
=======
#ifndef _GUIElement_H
#define _GUIElement_H

#include <SFML\Graphics.hpp>
#include <memory>
#include <vector>
enum	GUIType{Window, Button, Text, Image};

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
	virtual void	render(sf::RenderWindow *window) {}
	virtual			~GUIElement();
protected:
	int mX, mY, mWidth, mHeight, mAlpha;
	bool mVisible, mMouseInside;
	std::shared_ptr<GUIElement> mParent;
	GUIType mGUIType;
	
	std::vector<std::shared_ptr<GUIElement>> mChilds;
};

>>>>>>> parent of 5c595d1... asdasd
=======
>>>>>>> e8055fcf44317e4746a3cdb3e75fce869a1dc5ea
#endif