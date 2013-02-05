/*
Klass för kommunisterna i spelet Nukes of the Patriots

Arvid Backman 2013-01-21

*/

#ifndef COMMUNIST_H
#define COMMUNIST_H

#include "SuperPower.h"
#include <memory>
#include <vector>
#include <map>
#include <sstream>

class President;
class GUIElement;
class GUIButton;
class GUIImage;
class GUIWindow;


class Communist : public SuperPower
{
public:
	Communist();
	~Communist();

	void		getTaxIncome();
	void		updateFood();
	bool		enoughFood();

	void		setFood(int foodCount, int currentCurrency, int value);
	void		setGoods(int goodsCount, int currentCurrency, int value);
	void		setTech(int techCount, int currentCurrency, int value);

	void		upgradeNuclearWeapon(int currentNuclearCount, int currentGoods, int currentTech);
	void		upgradeSpaceProgram(int currentSpaceCount, int currentGoods, int currentTech);
	void		upgradeSpyNetwork(int currentSpyCount, int currentTech);

	int			increaseTaxCost(int currentTax);
	int			decreaseTaxCost(int currentTax);

	int			getYearlyFood(int round);
	int			getYearlyGoods(int round);
	int			getYearlyTech(int round);
	int			getYearlyTaxes(int round);

	void		buyPropagandaFood(int round);
	void		buyPropagandaGoods(int round);
	void		buyPropagandaTech(int round);

	void showGUI();
	void hideGUI();
private:
	std::string intToString(int i)
	{
		std::stringstream converter;
		converter << i;
		return converter.str();
	}

	std::vector<std::map<std::string, int>> mYearVector;

	void fiveYearInitialize();
	void setYearlyResources(int round, std::string, int value);

	void initializeCommunistWindow();
	void initializeGuiFunctions();

	//President	*mPresident;
	

	std::shared_ptr<GUIElement> mCommunistMainWindow;
	std::shared_ptr<GUIElement> mCommunistMainImage;
	std::shared_ptr<GUIElement> mCommunistTaxesButton;		
	std::shared_ptr<GUIElement> mCommunistResourcesButton;	
	std::shared_ptr<GUIElement> mCommunistUpgradeButton;		
	std::shared_ptr<GUIElement> mCommunistExportButton;	
	std::shared_ptr<GUIElement> mCommunistTaxesImage;
	std::shared_ptr<GUIElement> mCommunistResourceImage;
	std::shared_ptr<GUIElement> mCommunistUpgradeImage;
	std::shared_ptr<GUIElement> mCommunistExportImage;

	std::shared_ptr<GUIElement> mCloseWindow;


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