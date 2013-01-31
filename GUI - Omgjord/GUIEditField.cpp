#include "GUIEditField.h"
#include <SFML\System\String.hpp>
#include <iostream>
#include <sstream>

GUIEditField::GUIEditField(int x, int y, int width, int height, std::string text, std::shared_ptr<GUIElement> parent) :
	GUIElement(x, y, width, height, parent, EDIT_FIELD),
	mFont(sf::Font::getDefaultFont()),mRenderTexture(),mCaretVisible(true),mCaretIndex(0),mCaretShape(sf::Vector2f(0.0, 0.0)),mSelectedCaret(-1),mSelectedShape(sf::Vector2f(0.0, 0.0))
{
	mCaretTimer = Timer::setTimer([&](){ this->setCaretVisible(!(this->getCaretVisible()));}, 500, 0);
	mRenderTexture.create(width, height);
	mText.setFont(mFont);
	mText.setString(sf::String(text.c_str()));
	//sf::FloatRect boundBox = mText.getGlobalBounds();
	//setWidth(static_cast<int>(boundBox.width));
	//setHeight(static_cast<int>(boundBox.height));
}

bool GUIEditField::getCaretVisible()
{
	return mCaretVisible;
}

void GUIEditField::setCaretVisible(bool visible)
{
	mCaretVisible = visible;
}

void GUIEditField::setText(std::string text)
{
	mText.setString(sf::String(text.c_str()));
	//sf::FloatRect boundBox = mText.getGlobalBounds();
	//setWidth(static_cast<int>(boundBox.width));
	//setHeight(static_cast<int>(boundBox.height));
}

void GUIEditField::setScale(float width, float height)
{
	if(height > getHeight()) height = getHeight();
	mText.setScale(width, height);
	//sf::FloatRect boundBox = mText.getGlobalBounds();
	//setWidth(static_cast<int>(boundBox.width));
	//setHeight(static_cast<int>(boundBox.height));
}

void GUIEditField::render(sf::RenderWindow &window)
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
		float x = static_cast<float>(getX());
		float y = static_cast<float>(getY());
		mRenderTexture.clear(sf::Color::White);
		mText.setColor(sf::Color::Color(255, 0, 0, 255));
		//mText.setPosition((sf::Vector2f(x, y)));
		mRenderTexture.draw(mText);
		if(isSelected())
		{
			if(mSelectedCaret != -1)
			{
				sf::Vector2f caretPos = mText.findCharacterPos(mCaretIndex);
				sf::Vector2f caretSelectedPos = mText.findCharacterPos(mSelectedCaret);
				mSelectedShape.setFillColor(sf::Color::Color(0, 0, 255, 150));
				mSelectedShape.setPosition(caretPos);
				mSelectedShape.setSize(sf::Vector2f(caretSelectedPos.x - caretPos.x, getHeight()));
				mRenderTexture.draw(mSelectedShape);
			}
			if(mCaretVisible)
			{
				mCaretShape.setFillColor(sf::Color::Color(0, 0, 0, 255));
				mCaretShape.setSize(sf::Vector2f(2.5, getHeight()));
				mCaretShape.setPosition(mText.findCharacterPos(mSelectedCaret != -1 ? mSelectedCaret : mCaretIndex));
				mRenderTexture.draw(mCaretShape);
			}
		}
		mRenderTexture.display();

		sf::Sprite sprite(mRenderTexture.getTexture());
		sprite.setPosition((sf::Vector2f(x, y)));
		window.draw(sprite);
	}
}

void GUIEditField::update(sf::RenderWindow &window, sf::Event event)
{
	TimerHandler::getInstance()->tick();
	//int value = 0;
	//std::istringstream("1337")>>value;
	//std::cout<<value<<std::endl;

	if(event.type == sf::Event::KeyPressed)
	{
		int key = event.key.code;
		if(key == 71 && mCaretIndex >= 0)
		{
			mCaretTimer->resetTimer();
			mCaretVisible = true;
			if(isSelected() && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				if(mSelectedCaret == -1)
					mSelectedCaret = mCaretIndex - 1;
				else
					mSelectedCaret--;

				if(mSelectedCaret < 0)
					mSelectedCaret = 0;
			}
			if(!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				if(mSelectedCaret == -1)
					mCaretIndex--;
				if(mSelectedCaret != -1)
					mCaretIndex = mSelectedCaret--;
				mSelectedCaret = -1;
			}
			if(mCaretIndex < 0)
				mCaretIndex = 0;
		}
		else if(key == 72 && mCaretIndex <= mText.getString().getSize())
		{
			mCaretTimer->resetTimer();
			mCaretVisible = true;
			if(isSelected() && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				if(mSelectedCaret == -1)
					mSelectedCaret = mCaretIndex + 1;
				else
					mSelectedCaret++;

				if(mSelectedCaret > mText.getString().getSize())
					mSelectedCaret = mText.getString().getSize();
			}
			if(!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				if(mSelectedCaret == -1)
					mCaretIndex++;
				if(mSelectedCaret != -1)
					mCaretIndex = mSelectedCaret++;
				mSelectedCaret = -1;
			}
			if(mCaretIndex > mText.getString().getSize())
				mCaretIndex = mText.getString().getSize();
		}
		else if(key == 59 && mCaretIndex >= 0)
		{
			mCaretTimer->resetTimer();
			mCaretVisible = true;
			sf::String str = mText.getString();
			if(mSelectedCaret == -1)
			{
				if(mCaretIndex > 0)
				{
					str.erase(mCaretIndex - 1);
					mCaretIndex--;
				}
			}
			else
			{
				int characters = mSelectedCaret - mCaretIndex;
				int eraseIndex = (characters < 0 ? mCaretIndex - std::abs(characters) : mCaretIndex);
				characters = (characters == 0 ? 1 : characters);
				str.erase(eraseIndex, std::abs(characters));
				if(characters < 0)
					mCaretIndex -= std::abs(characters);
			}
			mText.setString(str);
			mSelectedCaret = -1;
			if(mCaretIndex < 0)
				mCaretIndex = 0;
		}
		else if(key == 66)
		{
			mCaretTimer->resetTimer();
			mCaretVisible = true;
			sf::String str = mText.getString();
			if(mSelectedCaret == -1)
			{
				str.erase(mCaretIndex);
			}
			else
			{
				int characters = mSelectedCaret - mCaretIndex;
				int eraseIndex = (characters < 0 ? mCaretIndex - std::abs(characters) : mCaretIndex);
				characters = (characters == 0 ? 1 : characters);
				str.erase(eraseIndex, std::abs(characters));
				if(characters < 0)
					mCaretIndex -= std::abs(characters);
			}
			mText.setString(str);
			mSelectedCaret = -1;
		}
	}
	if(event.type == sf::Event::TextEntered)
	{
		mCaretTimer->resetTimer();
		mCaretVisible = true;
		char key = static_cast<char>(event.text.unicode);
		if(event.text.unicode < 128 && event.text.unicode != 13 && event.text.unicode != 8)
		{
			sf::String str = mText.getString();
			if(mSelectedCaret != -1)
			{
				int characters = mSelectedCaret - mCaretIndex;
				int eraseIndex = (characters < 0 ? mCaretIndex - std::abs(characters) : mCaretIndex);
				characters = (characters == 0 ? 1 : characters);
				str.erase(eraseIndex, std::abs(characters));
				if(characters < 0)
					mCaretIndex -= std::abs(characters);
				str.insert(mCaretIndex, key);
			}
			else
				str.insert(mCaretIndex, key);
			mCaretIndex++;
			mText.setString(str);
			mSelectedCaret = -1;
		}
	}
	if(isSelected() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mCaretTimer->resetTimer();
		mCaretVisible = true;
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		mousePos.x -= getX();
		mousePos.y -= getY();
		sf::String str = mText.getString();
		int newCaret = str.getSize();
		for(size_t i = 0; i < str.getSize(); i++)
		{
			sf::Vector2f strPos = mText.findCharacterPos(i);
			sf::Text text;
			text.setFont(mFont);
			sf::String str = mText.getString();
			text.setString(str[i]);
			sf::FloatRect boundBox = text.getGlobalBounds();
			if(mousePos.x < strPos.x + boundBox.width/2)
			{
				newCaret = i;
				break;
			}
		}
		mSelectedCaret = newCaret;
		if(mSelectedCaret == mCaretIndex)
			mSelectedCaret = -1;
	}
	GUIElement::update(window, event);
}

void GUIEditField::onGUIClick(int mouseX, int mouseY)
{
	mSelectedCaret = -1;
	mCaretTimer->resetTimer();
	mCaretVisible = true;
	sf::String str = mText.getString();
	int newCaret = str.getSize();
	for(size_t i = 0; i < str.getSize(); i++)
	{
		sf::Vector2f strPos = mText.findCharacterPos(i);
		sf::Text text;
		text.setFont(mFont);
		sf::String str = mText.getString();
		text.setString(str[i]);
		sf::FloatRect boundBox = text.getGlobalBounds();
		if(mouseX < strPos.x + boundBox.width/2)
		{
			newCaret = i;
			break;
		}
	}
	mCaretIndex = newCaret;
	//std::cout<<"on gui click!"<<std::endl;
}

void GUIEditField::onGUIDeselected()
{

}