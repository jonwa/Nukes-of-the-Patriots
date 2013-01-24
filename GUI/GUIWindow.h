#ifndef _GUI_WINDOW_H
#define _GUI_WINDOW_H

#include "GUIElement.h"

class GUIWindow: public GUIElement
{
public:
			GUIWindow(int x, int y, int width, int height, GUIElement *parent = 0);
	void	render(sf::RenderWindow *window);
	void	setScale(float width, float height);
			~GUIWindow(){}
};

#endif