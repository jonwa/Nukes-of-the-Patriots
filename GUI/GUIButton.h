<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> e8055fcf44317e4746a3cdb3e75fce869a1dc5ea
 #ifndef _GUI_BUTTON_H
#define _GUI_BUTTON_H

#include "GUIElement.h"

class GUIButton: public GUIElement
{
public:
			GUIButton(int x, int y, int width, int height, std::shared_ptr<GUIElement> parent = 0);
	void	render(sf::RenderWindow &window);
	void	setScale(float width, float height);
			~GUIButton(){}
};

<<<<<<< HEAD
=======
 #ifndef _GUI_BUTTON_H
#define _GUI_BUTTON_H

#include "GUIElement.h"

class GUIButton: public GUIElement
{
public:
			GUIButton(int x, int y, int width, int height, std::shared_ptr<GUIElement> parent = 0);
	void	render(sf::RenderWindow *window);
	void	setScale(float width, float height);
			~GUIButton(){}
};

>>>>>>> parent of 5c595d1... asdasd
=======
>>>>>>> e8055fcf44317e4746a3cdb3e75fce869a1dc5ea
#endif