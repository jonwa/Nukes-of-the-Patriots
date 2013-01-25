#include "GUIWindow.h"

GUIWindow::GUIWindow(int x, int y, int width, int height, std::shared_ptr<GUIElement> parent) :
	GUIElement(x, y, width, height, parent, GUIType::Window)
{
}

void GUIWindow::render(sf::RenderWindow *window)
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