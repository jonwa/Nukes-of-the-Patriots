#ifndef _GUI_MANAGER_H
#define _GUI_MANAGER_H

#include "GUIElement.h"
#include <functional>

class GUIManager
{
public:
	static GUIManager* getInstance();

	GUIManager();
	void addGUIElement(GUIElement *guiElement);
	void render(sf::RenderWindow *window);
	void update();

	void addOnMouseClickEventHandler(std::function <void (GUIElement*)>);
	void addOnMouseEnterEventHandler(std::function <void (GUIElement*)>);
	void addOnMouseLeaveEventHandler(std::function <void (GUIElement*)>);

	void triggerOnMouseClickEvent(GUIElement *guiElement);
	void triggerOnMouseEnterEvent(GUIElement *guiElement);
	void triggerOnMouseLeaveEvent(GUIElement *guiElement);
		~GUIManager(){}
private:
	static GUIManager* mInstance;


	sf::RenderWindow *mWindow;
	std::vector<GUIElement*> mGuiElements;
	std::vector<std::function <void (GUIElement*)>> mOnMouseClickFuncs;
	std::vector<std::function <void (GUIElement*)>> mOnMouseEnterFuncs;
	std::vector<std::function <void (GUIElement*)>> mOnMouseLeaveFuncs;
};

#endif
