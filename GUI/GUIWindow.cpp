#include "GUIWindow.h"

GUIWindow::GUIWindow(int x, int y, int width, int height, std::shared_ptr<GUIElement> parent) :
	GUIElement(x, y, width, height, parent, WINDOW)
{
}

void GUIWindow::render(sf::RenderWindow &window)
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
		float width = static_cast<float>(getWidth() );
		float height = static_cast<float>(getHeight() );
		float xPos = static_cast<float>(mX);
		float yPos = static_cast<float>(mY);
		sf::RectangleShape rect(sf::Vector2f(width, height));
		rect.setPosition(xPos, yPos);
		rect.setFillColor(sf::Color::Color(255, 0, 0, 255));
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

void GUIWindow::setScale(float width, float height)
{
	mWidth	*= width;
	mHeight *= height;
}