#ifndef _GUIEDITFIELD_H
#define _GUIEDITFIELD_H

#include <string>
#include "GUIElement.h"
#include "Timer.h"
#include "TimerHandler.h"

class GUIEditField: public GUIElement
{
public:
				GUIEditField(int x, int y, int width, int height, std::string text = "", std::shared_ptr<GUIElement> parent = 0);
	std::string getText()const{ return mText.getString(); }
	bool		getCaretVisible();
	void		setCaretVisible(bool visible);
	void		setText(std::string text);
	void		setScale(float width, float height);
	void		render(sf::RenderWindow &window);
	virtual void		update(sf::RenderWindow &window, sf::Event event);
	virtual void		onGUIClick(int mouseX, int mouseY);
	virtual void		onGUIDeselected();
				~GUIEditField(){}
private:
	sf::Text mText;
	sf::Font mFont;
	sf::RenderTexture mRenderTexture;
	Timer *mCaretTimer;
	bool mCaretVisible;
	int mCaretIndex, mSelectedCaret;
	sf::RectangleShape mCaretShape, mSelectedShape;
};

#endif