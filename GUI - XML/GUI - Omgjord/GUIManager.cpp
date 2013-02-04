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

void GUIManager::addGUIElement(std::shared_ptr<GUIElement> guiElement)
{
	mGuiElements.push_back(guiElement);
	if(!guiElement->getChildVector().empty())
	{
		for(std::vector<std::shared_ptr<GUIElement>>::size_type i = 0; i < guiElement->getChildVector().size(); ++i)
		{
			mGuiElements.push_back(guiElement->getChildVector()[i]);
			if(!guiElement->getChildVector().empty())
			{
				for(std::vector<std::shared_ptr<GUIElement>>::size_type j = 0; j < guiElement->getChildVector()[i]->getChildVector().size(); ++j)
				{
					mGuiElements.push_back(guiElement->getChildVector()[i]->getChildVector()[j]);
				}
			}
		}
	}
}

void GUIManager::render(sf::RenderWindow &window)
{
	for(std::vector<std::shared_ptr<GUIElement>>::iterator it = mGuiElements.begin(); it != mGuiElements.end(); ++it)
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
	for(std::vector<std::shared_ptr<GUIElement>>::size_type i = 0; i < mGuiElements.size(); ++i)
	{
		if(!mGuiElements[i]->getChildVector().empty())
			mGuiElements[i]->update();
	}
	//for(std::vector<std::shared_ptr<GUIElement>>::size_type i = 0; i < mGuiElements.size(); ++i)
	//{
	//	std::shared_ptr<GUIElement> guiElement = mGuiElements[i];
	//	guiElement->update();
	//	bool isMouseInside = guiElement->getMouseIsInside();
	//	// Check if mouse is colliding with gui element
	//	if(mousePos.x > guiElement->getX() && mousePos.x < guiElement->getX() + guiElement->getWidth() && mousePos.y > guiElement->getY() && mousePos.y < guiElement->getY() + guiElement->getHeight())
	//	{
	//		if(!isMouseInside)
	//		{
	//			guiElement->setMouseIsInside(true);
	//			triggerOnMouseEnterEvent(guiElement);
	//		}
	//		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	//		{
	//			triggerOnMouseClickEvent(guiElement);
	//		}
	//	}
	//	else
	//	{
	//		if(isMouseInside)
	//		{
	//			guiElement->setMouseIsInside(false);
	//			triggerOnMouseLeaveEvent(guiElement);
	//		}
	//	}
	//}
}

void GUIManager::addOnMouseClickEventHandler(std::function <void (std::shared_ptr<GUIElement>)> func)
{
	mOnMouseClickFuncs.push_back(func);
}


void GUIManager::addOnMouseEnterEventHandler(std::function <void (std::shared_ptr<GUIElement>)> func)
{
	mOnMouseEnterFuncs.push_back(func);
}

void GUIManager::addOnMouseLeaveEventHandler(std::function <void (std::shared_ptr<GUIElement>)> func)
{
	mOnMouseLeaveFuncs.push_back(func);
}

//Trigger events (call the callback functions)
void GUIManager::triggerOnMouseClickEvent(std::shared_ptr<GUIElement> guiElement)
{
	for(std::vector<std::function <void (std::shared_ptr<GUIElement>)>>::iterator it = mOnMouseClickFuncs.begin(); it != mOnMouseClickFuncs.end(); it++)
	{
		if((*it) != NULL)
			(*it)(guiElement);
	}
}

void GUIManager::triggerOnMouseEnterEvent(std::shared_ptr<GUIElement> guiElement)
{
	for(std::vector<std::function <void (std::shared_ptr<GUIElement>)>>::iterator it = mOnMouseEnterFuncs.begin(); it != mOnMouseEnterFuncs.end(); it++)
	{
		if((*it) != NULL)
			(*it)(guiElement);
	}
}

void GUIManager::triggerOnMouseLeaveEvent(std::shared_ptr<GUIElement> guiElement)
{
	for(std::vector<std::function <void (std::shared_ptr<GUIElement>)>>::iterator it = mOnMouseLeaveFuncs.begin(); it != mOnMouseLeaveFuncs.end(); it++)
	{
		if((*it) != NULL)
			(*it)(guiElement);
	}
}