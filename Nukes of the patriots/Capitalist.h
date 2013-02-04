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
class GUIText;
class GUIWindow;
class President;
class Randomizer;

#include "SuperPower.h"
#include <vector>
#include <memory>
#include <map>
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


	void initializeCapitalistWindow();
private:
	std::string intToString(int i)
	{
		std::stringstream converter;
		converter << i;
		return converter.str();
	}

	std::shared_ptr<President> mPresident;

	/*Skapar två std::map. En dit alla knappar för kapitalisternas läggs in i samt 
	  en dit alla kapitalisternas fönster läggs in i. Detta sker via hämtade värden
	  från XML dokument samt genom ResourceHandler  
	  Av: Jon Wahlström 2013-01-31
																				*/
	std::map<std::string, std::pair<sf::FloatRect, sf::Texture*> > CapitalistButtons;
	std::map<std::string, std::pair<sf::FloatRect, sf::Texture*> > CapitalistWindows;
	
	void loadButtonPosition();
	void loadWindowPosition();
	void initializeGuiFunctions();
	
	//President	*mPresident;
	

	/*GUI-pekare för kapitalisternas interface*/
	std::shared_ptr<GUIWindow> mCapitalistMainWindow;		
	std::shared_ptr<GUIButton> mCapitalistTaxesButton;		
	std::shared_ptr<GUIButton> mCapitalistResourceButton;	
	std::shared_ptr<GUIButton> mCapitalistUpgradeButton;		
	std::shared_ptr<GUIButton> mCapitalistExportButton;	

	/*GUI-pekare för taxes */
	std::shared_ptr<GUIWindow> mTaxesWindow;
	std::shared_ptr<GUIButton> mLowerTaxesButton;
	std::shared_ptr<GUIButton> mRaiseTaxesButton;
	std::shared_ptr<GUIButton> mTaxesCloseButton;
	/*GUI-pekare för resources*/
	std::shared_ptr<GUIWindow> mResourceWindow;
	std::shared_ptr<GUIButton> mLowerFoodByTenButton;
	std::shared_ptr<GUIButton> mLowerFoodByFiveButton;
	std::shared_ptr<GUIButton> mLowerFoodByOneButton;
	std::shared_ptr<GUIButton> mRaiseFoodByOneButton;
	std::shared_ptr<GUIButton> mRaiseFoodByFiveButton;
	std::shared_ptr<GUIButton> mRaiseFoodByTenButton;
	std::shared_ptr<GUIButton> mLowerGoodsByTenButton;
	std::shared_ptr<GUIButton> mLowerGoodsByFiveButton;
	std::shared_ptr<GUIButton> mLowerGoodsByOneButton;
	std::shared_ptr<GUIButton> mRaiseGoodsByOneButton;
	std::shared_ptr<GUIButton> mRaiseGoodsByFiveButton;
	std::shared_ptr<GUIButton> mRaiseGoodsByTenButton;
	std::shared_ptr<GUIButton> mLowerTechByTenButton;
	std::shared_ptr<GUIButton> mLowerTechByFiveButton;
	std::shared_ptr<GUIButton> mLowerTechByOneButton;
	std::shared_ptr<GUIButton> mRaiseTechByOneButton;
	std::shared_ptr<GUIButton> mRaiseTechByFiveButton;
	std::shared_ptr<GUIButton> mRaiseTechByTenButton;
	std::shared_ptr<GUIButton> mResourceCloseButton;
	/*GIU-pekare för upgrade*/
	std::shared_ptr<GUIWindow> mUpgradeWindow;
	std::shared_ptr<GUIButton> mUpgradeNuclearWeaponButton;
	std::shared_ptr<GUIButton> mUpgradeSpaceProgramButton;
	std::shared_ptr<GUIButton> mUpgradeSpyNetworkButton;
	std::shared_ptr<GUIButton> mUpgradeCloseButton;
	/*GUI-pekare för export*/
	std::shared_ptr<GUIWindow> mExportWindow;
	std::shared_ptr<GUIButton> mExportLowerFoodButton;
	std::shared_ptr<GUIButton> mExportRaiseFoodButton;
	std::shared_ptr<GUIButton> mExportLowerGoodsButton;
	std::shared_ptr<GUIButton> mExportRaiseGoodsButton;
	std::shared_ptr<GUIButton> mExportLowerTechButton;
	std::shared_ptr<GUIButton> mExportRaiseTechButton;
	std::shared_ptr<GUIButton> mExportCloseButton;
};


#endif