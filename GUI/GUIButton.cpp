<<<<<<< HEAD
#include "GUIButton.h"

GUIButton::GUIButton(int x, int y, int width, int height, std::shared_ptr<GUIElement> parent) :
	GUIElement(x, y, width, height, parent, GUIType::Button)
{
}

void GUIButton::render(sf::RenderWindow &window)
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
		sf::RectangleShape rect(sf::Vector2f(getWidth(), getHeight()));
		rect.setPosition(mX, mY);
		rect.setFillColor(sf::Color::Color(255, 255, 255, 255));
		window.draw(rect);
	}

	/*if(!mChilds.empty())
	{
		for(std::vector<GUIElement*>::size_type i = 0; i < mChilds.size(); ++i)
		{
			mChilds[i]->render(window);
		}
	}*/
}

void GUIButton::setScale(float width, float height)
{
	mWidth	*= width;
	mHeight *= height;
=======
#include "GUIButton.h"

GUIButton::GUIButton(int x, int y, int width, int height, std::shared_ptr<GUIElement> parent) :
	GUIElement(x, y, width, height, parent, GUIType::Button)
{
}

void GUIButton::render(sf::RenderWindow *window)
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
		sf::RectangleShape rect(sf::Vector2f(getWidth(), getHeight()));
		rect.setPosition(mX, mY);
		rect.setFillColor(sf::Color::Color(255, 255, 255, 255));
		window->draw(rect);
	}

	/*if(!mChilds.empty())
	{
		for(std::vector<GUIElement*>::size_type i = 0; i < mChilds.size(); ++i)
		{
			mChilds[i]->render(window);
		}
	}*/
}

void GUIButton::setScale(float width, float height)
{
	mWidth	*= width;
	mHeight *= height;
>>>>>>> parent of 5c595d1... asdasd
}