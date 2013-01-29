/*
 * Klass för kapitalisterna i spelet Nukes of the Patriots
 * 
 *    Arvid Backman 2013-01-21
 *	  Jon Wahlström
 */

#ifndef CAPITALIST_H
#define CAPITALIST_H

//class President;
class GUIManager;
class GUIElement;
class GUIButton;
class GUIImage;
class GUIText;
class GUIWindow;

#include "SuperPower.h"
#include <vector>
#include <memory>
#include <sstream>
#include <SFML\Graphics\RenderWindow.hpp>

class Capitalist : public SuperPower 
{
public:
	Capitalist();
	~Capitalist();

	void initializeCapitalistWindow();

	void onGUIClick(std::shared_ptr<GUIElement> guiElement);

	void openTaxesMenu();
	void openResourceMenu();
	void openUpgradeMenu();
	void openExportMenu();

	void closeTaxesMenu();
	void closeResourceMenu();
	void closeUpgradeMenu();
	void closeExportMenu();

	void upgradeNuclearWeapon();
	void upgradeSpaceProgram();
	void upgradeSpyNetwork();

	bool enableToIncreasePopulation();
	void increasePopulation();

	void showGUI();
	void hideGUI();
private:
	std::string intToString(int i)
	{
		std::stringstream converter;
		converter << i;
		return converter.str();
	}
	
	void initializeGuiFunctions();

	//President	*mPresident;
	



	//Huvudfönstret för kapitalisterna
	std::shared_ptr<GUIElement> mCapitalistMainWindow;		
	std::shared_ptr<GUIElement> mCapitalistTaxesButton;		
	std::shared_ptr<GUIElement> mCapitalistResourceButton;	
	std::shared_ptr<GUIElement> mCapitalistUpgradeButton;		
	std::shared_ptr<GUIElement> mCapitalistExportButton;	
	std::shared_ptr<GUIElement> mCapitalistMainWindowImage;	
	std::shared_ptr<GUIElement> mCapitalistTaxesImage;
	std::shared_ptr<GUIElement> mCapitalistResourceImage;
	std::shared_ptr<GUIElement> mCapitalistUpgradeImage;
	std::shared_ptr<GUIElement> mCapitalistExportImage;

	//GUI för taxes
	std::shared_ptr<GUIElement> mTaxesWindow;
	std::shared_ptr<GUIElement> mTaxesImage;
	
	std::shared_ptr<GUIElement> mIncreaseTaxesButton;
	std::shared_ptr<GUIElement> mDecreaseTaxesButton;
	std::shared_ptr<GUIElement> mIncreaseTaxesImage;
	std::shared_ptr<GUIElement> mDecreaseTaxesImage;

	std::shared_ptr<GUIElement> mTaxesCloseButton;
	std::shared_ptr<GUIElement> mTaxesCloseImage;


	//GUI för resurser
	std::shared_ptr<GUIElement> mResourceWindow;
	std::shared_ptr<GUIElement> mResourceImage;

	std::shared_ptr<GUIElement> mResourceCloseButton;
	std::shared_ptr<GUIElement> mResourceCloseImage;


	//GUI för uppgradering
	std::shared_ptr<GUIElement> mUpgradeWindow;
	std::shared_ptr<GUIElement> mUpgradeImage;

	std::shared_ptr<GUIElement> mUpgradeCloseButton;
	std::shared_ptr<GUIElement> mUpgradeCloseImage;

	//GUI för uppgradering
	std::shared_ptr<GUIElement> mExportWindow;
	std::shared_ptr<GUIElement> mExportImage;

	std::shared_ptr<GUIElement> mExportCloseButton;
	std::shared_ptr<GUIElement> mExportCloseImage;
};


#endif