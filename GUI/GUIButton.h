 #ifndef _GUI_BUTTON_H
#define _GUI_BUTTON_H

#include "GUIElement.h"

class GUIButton: public GUIElement
{
public:
			GUIButton(int x, int y, int width, int height, GUIElement *parent = 0);
	void	render(sf::RenderWindow *window);
	void	setScale(float width, float height);
			~GUIButton(){}
};

#endif