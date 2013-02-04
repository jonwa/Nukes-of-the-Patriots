/*
 * Klass för kapitalisterna i spelet Nukes of the Patriots
 * 
 *    Arvid Backman 2013-01-21
 *	  Jon Wahlström
 */

#ifndef CAPITALIST_H
#define CAPITALIST_H

class President;
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

	std::shared_ptr<President>	getPresident();
	void						setPresident(std::shared_ptr<President>);


	void upgradeNuclearWeapon(int currentNuclearCount, int currentGoods, int currentTech);
	void upgradeSpaceProgram(int currentSpaceCount, int currentGoods, int currentTech);
	void upgradeSpyNetwork(int currentSpyCount, int currentTech);
	

	void showGUI();
	void hideGUI();

	int	increaseTaxCost(int currentTax);
	int	decreaseTaxCost(int currentTax);

	void setFood(int foodCount, int currentCurrency, int value);
	void setGoods(int goodsCount, int currentCurrency, int value);
	void setTech(int techCount, int currentCurrency, int value);
private:
	std::string intToString(int i)
	{
		std::stringstream converter;
		converter << i;
		return converter.str();
	}
	
	void initializeCapitalistWindow();
	void initializeGuiFunctions();

	std::shared_ptr<President> mPresident;
	



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