#ifndef MENU_H
#define MENU_H

#include "GUIElement.h"
#include "GUIWindow.h"
#include "GUIImage.h"
#include "GUIButton.h"
#include <memory>

#include <SFML\Graphics\RenderWindow.hpp>

class Menu
{
public:
	Menu(sf::RenderWindow &window);
	~Menu();

	
private:
	void initialize();
	void initializeGUIFuctions();

	std::shared_ptr<GUIWindow> mParentWindow;
	std::shared_ptr<GUIWindow> mMainMenuWindow;
	std::shared_ptr<GUIWindow> mSettingsMenuWindow;
	std::shared_ptr<GUIWindow> mCreditsMenuWindow;
	std::shared_ptr<GUIWindow> mLogoMenuWindow;
	std::shared_ptr<GUIElement> mSplashScreenWindow;

	std::shared_ptr<GUIImage> mMainMenuImage;
	std::shared_ptr<GUIImage> mSettingsMenuImage;
	std::shared_ptr<GUIImage> mCreditsMenuImage;
	std::shared_ptr<GUIImage> mLogoMenuImage;
	std::shared_ptr<GUIImage> mSplashScreenImage;

	std::shared_ptr<GUIButton> mStartNewGameButton;
	std::shared_ptr<GUIButton> mLoadGameButton;
	std::shared_ptr<GUIButton> mSettingsButton;
	std::shared_ptr<GUIButton> mCreditsButton;
	std::shared_ptr<GUIButton> mExitButton;

	sf::RenderWindow mWindow;

};

#endif