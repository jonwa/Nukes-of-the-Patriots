<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> e8055fcf44317e4746a3cdb3e75fce869a1dc5ea
#ifndef _GUI_WINDOW_H
#define _GUI_WINDOW_H

#include "GUIElement.h"

class GUIWindow: public GUIElement
{
public:
			GUIWindow(int x, int y, int width, int height, std::shared_ptr<GUIElement> parent = 0);
	void	render(sf::RenderWindow &window);
	void	setScale(float width, float height);
			~GUIWindow(){}
};

<<<<<<< HEAD
=======
#ifndef _GUI_WINDOW_H
#define _GUI_WINDOW_H

#include "GUIElement.h"

class GUIWindow: public GUIElement
{
public:
			GUIWindow(int x, int y, int width, int height, std::shared_ptr<GUIElement> parent = 0);
	void	render(sf::RenderWindow *window);
	void	setScale(float width, float height);
			~GUIWindow(){}
};

>>>>>>> parent of 5c595d1... asdasd
=======
>>>>>>> e8055fcf44317e4746a3cdb3e75fce869a1dc5ea
#endif