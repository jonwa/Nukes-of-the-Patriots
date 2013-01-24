#include "GUIManager.h"

GUIManager* GUIManager::mInstance = NULL;
GUIManager* GUIManager::getInstance()
{
	if(mInstance == NULL)
	{
		mInstance = new GUIManager();
	}
	return mInstance;
}

GUIManager::GUIManager() :
	
	mGuiElements(),
	mOnMouseClickFuncs(),
	mOnMouseEnterFuncs(),
	mOnMouseLeaveFuncs()
{
}

void GUIManager::addGUIElement(GUIElement *guiElement)
{
	mGuiElements.push_back(guiElement);
	if(!guiElement->getChildVector().empty())
	{
		for(std::vector<GUIElement*>::size_type i = 0; i < guiElement->getChildVector().size(); ++i)
		{
			mGuiElements.push_back(guiElement->getChildVector()[i]);
			if(!guiElement->getChildVector().empty())
			{
				for(std::vector<GUIElement*>::size_type j = 0; j < guiElement->getChildVector()[i]->getChildVector().size(); ++j)
				{
					mGuiElements.push_back(guiElement->getChildVector()[i]->getChildVector()[j]);
				}
			}
		}
	}
}

void GUIManager::render(sf::RenderWindow *window)
{
	for(std::vector<GUIElement*>::iterator it = mGuiElements.begin(); it != mGuiElements.end(); it++)
	{
		if((*it)->getVisible())
		{
				(*it)->render(window);
		}
	}
}

void GUIManager::update()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	for(std::vector<GUIElement*>::iterator it = mGuiElements.begin(); it != mGuiElements.end(); it++)
	{
		GUIElement *guiElement = (*it);
		bool isMouseInside = guiElement->getMouseIsInside();
		// Check if mouse is colliding with gui element
		if(mousePos.x > guiElement->getX() && mousePos.x < guiElement->getX() + guiElement->getWidth() && mousePos.y > guiElement->getY() && mousePos.y < guiElement->getY() + guiElement->getHeight())
		{
			if(!isMouseInside)
			{
				guiElement->setMouseIsInside(true);
				triggerOnMouseEnterEvent(guiElement);
			}
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				triggerOnMouseClickEvent(guiElement);
			}
		}
		else
		{
			if(isMouseInside)
			{
				guiElement->setMouseIsInside(false);
				triggerOnMouseLeaveEvent(guiElement);
			}
		}
	}
}

void GUIManager::addOnMouseClickEventHandler(std::function <void (GUIElement*)> func)
{
	mOnMouseClickFuncs.push_back(func);
}


void GUIManager::addOnMouseEnterEventHandler(std::function <void (GUIElement*)> func)
{
	mOnMouseEnterFuncs.push_back(func);
}

void GUIManager::addOnMouseLeaveEventHandler(std::function <void (GUIElement*)> func)
{
	mOnMouseLeaveFuncs.push_back(func);
}

//Trigger events (call the callback functions)
void GUIManager::triggerOnMouseClickEvent(GUIElement *guiElement)
{
	for(std::vector<std::function <void (GUIElement*)>>::iterator it = mOnMouseClickFuncs.begin(); it != mOnMouseClickFuncs.end(); it++)
	{
		if((*it) != NULL)
			(*it)(guiElement);
	}
}

void GUIManager::triggerOnMouseEnterEvent(GUIElement *guiElement)
{
	for(std::vector<std::function <void (GUIElement*)>>::iterator it = mOnMouseEnterFuncs.begin(); it != mOnMouseEnterFuncs.end(); it++)
	{
		if((*it) != NULL)
			(*it)(guiElement);
	}
}

void GUIManager::triggerOnMouseLeaveEvent(GUIElement *guiElement)
{
	for(std::vector<std::function <void (GUIElement*)>>::iterator it = mOnMouseLeaveFuncs.begin(); it != mOnMouseLeaveFuncs.end(); it++)
	{
		if((*it) != NULL)
			(*it)(guiElement);
	}
}
