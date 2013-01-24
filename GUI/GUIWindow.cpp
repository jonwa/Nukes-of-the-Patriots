#include "GUIWindow.h"

GUIWindow::GUIWindow(int x, int y, int width, int height, GUIElement *parent) :
	GUIElement(x, y, width, height, parent, GUIType::Window)
{
}

void GUIWindow::render(sf::RenderWindow *window)
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
		sf::RectangleShape rect(sf::Vector2f(getWidth(), getHeight()));
		rect.setPosition(x, y);
		rect.setFillColor(sf::Color::Color(255, 0, 0, 255));
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

void GUIWindow::setScale(float width, float height)
{
	mWidth	*= width;
	mHeight *= height;
}