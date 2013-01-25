<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> e8055fcf44317e4746a3cdb3e75fce869a1dc5ea
#include "GUIElement.h"

GUIElement::GUIElement(int x, int y, int width, int height, std::shared_ptr<GUIElement> parent, GUIType guiType) : 
	mX(x),
	mY(y),
	mWidth(width),
	mHeight(height),
	mVisible(true),
	mParent(parent),
	mGUIType(guiType),
	mMouseInside(false)
{
	if(mParent != NULL)
	{
		mParent->addChild(getPtr());
		setX(mX += mParent->getX());
		setY(mY += mParent->getY());
	}
}

GUIElement::~GUIElement()
{
}

std::shared_ptr<GUIElement> GUIElement::getPtr()
{
	return std::shared_ptr<GUIElement>(this);
	//return shared_from_this();
}

void GUIElement::addChild(std::shared_ptr<GUIElement> guiElement)
{
	mChilds.push_back(guiElement);
}

std::vector<std::shared_ptr<GUIElement>>& GUIElement::getChildVector()
{
	return mChilds;
}

void GUIElement::setMouseIsInside(bool inside)
{
	mMouseInside = inside;
};

int	GUIElement::getX()const
{ 
	return mX; 
}
int	GUIElement::getY()const
{ 
	return mY; 
}
int	GUIElement::getWidth()const
{ 
	return mWidth; 
}
int	GUIElement::getHeight()const
{ 
	return mHeight;
}
bool GUIElement::getVisible()const
{ 
	return mVisible; 
}
std::shared_ptr<GUIElement> GUIElement::getParent()const
{
	return mParent;
}
GUIType	GUIElement::getGUIType()const
{ 
	return mGUIType; 
}
int	GUIElement::getAlpha()const
{ 
	return mAlpha; 
}
bool GUIElement::getMouseIsInside()const
{ 
	return mMouseInside;
}

void GUIElement::setX(int x)
{
	mX = x; 
}
void GUIElement::setY(int y)
{ 
	mY = y;
}
void GUIElement::setWidth(int width)
{
	mWidth = width;
}
void GUIElement::setHeight(int height)
{ 
	mHeight = height;
}
void GUIElement::setVisible(bool visible)
{ 
	mVisible = visible;
	for(std::vector<std::shared_ptr<GUIElement>>::size_type i = 0; i < mChilds.size(); ++i)
	{
		mChilds[i]->setVisible(visible);
	}
}
void GUIElement::setAlpha(int alpha)
{
	mAlpha = alpha; 
<<<<<<< HEAD
=======
#include "GUIElement.h"

GUIElement::GUIElement(int x, int y, int width, int height, std::shared_ptr<GUIElement> parent, GUIType guiType) : 
	mX(x),
	mY(y),
	mWidth(width),
	mHeight(height),
	mVisible(true),
	mParent(parent),
	mGUIType(guiType),
	mMouseInside(false)
{
	if(mParent != NULL)
	{
		mParent->addChild(getPtr());
		setX(mX += mParent->getX());
		setY(mY += mParent->getY());
	}
}

GUIElement::~GUIElement()
{
}

std::shared_ptr<GUIElement> GUIElement::getPtr()
{
	return std::shared_ptr<GUIElement>(this);
}

void GUIElement::addChild(std::shared_ptr<GUIElement> guiElement)
{
	mChilds.push_back(guiElement);
}

std::vector<std::shared_ptr<GUIElement>>& GUIElement::getChildVector()
{
	return mChilds;
}

void GUIElement::setMouseIsInside(bool inside)
{
	mMouseInside = inside;
};

int	GUIElement::getX()const
{ 
	return mX; 
}
int	GUIElement::getY()const
{ 
	return mY; 
}
int	GUIElement::getWidth()const
{ 
	return mWidth; 
}
int	GUIElement::getHeight()const
{ 
	return mHeight;
}
bool GUIElement::getVisible()const
{ 
	return mVisible; 
}
std::shared_ptr<GUIElement> GUIElement::getParent()const
{
	return mParent;
}
GUIType	GUIElement::getGUIType()const
{ 
	return mGUIType; 
}
int	GUIElement::getAlpha()const
{ 
	return mAlpha; 
}
bool GUIElement::getMouseIsInside()const
{ 
	return mMouseInside;
}

void GUIElement::setX(int x)
{
	mX = x; 
}
void GUIElement::setY(int y)
{ 
	mY = y;
}
void GUIElement::setWidth(int width)
{
	mWidth = width;
}
void GUIElement::setHeight(int height)
{ 
	mHeight = height;
}
void GUIElement::setVisible(bool visible)
{ 
	mVisible = visible;
	for(std::vector<std::shared_ptr<GUIElement>>::size_type i = 0; i < mChilds.size(); ++i)
	{
		mChilds[i]->setVisible(visible);
	}
}
void GUIElement::setAlpha(int alpha)
{
	mAlpha = alpha; 
>>>>>>> parent of 5c595d1... asdasd
=======
>>>>>>> e8055fcf44317e4746a3cdb3e75fce869a1dc5ea
}