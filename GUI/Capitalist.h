/*
 * Klass f�r kapitalisterna i spelet Nukes of the Patriots
 * 
 *    Arvid Backman 2013-01-21
 *	  Jon Wahlstr�m
 */



#ifndef CAPITALIST_H
#define CAPITALIST_H

//class President;
class GUIManager;
class GUIElement;
class GUIButton;
class GUIImage;
class GUIWindow;

#include <vector>
#include <memory>
#include <SFML\Graphics\RenderWindow.hpp>

class Capitalist
{
public:
	Capitalist();
	~Capitalist();

	int	getFood();
	int	getGoods();
	int	getTech();
	int	getTaxes();
	int	getNuclearWeapon();
	int	getSpaceProgram();
	int	getSpyNetwork();
	int	getCurrency();
	//President	getPresident();

	void setFood(int food);
	void setGoods(int goods);
	void setTech(int tech);
	void setTaxes(int taxes);
	//void		setPresident(President &president);

	void getTaxIncome();
	void updateFood();
	bool enoughFood();


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

private:
	int	mPatriotism;
	int	mCurrency;
	int	mPopulation;
	int	mFood;
	int	mGoods;
	int	mTech;
	int	mTaxes;
	int	mSpyNetwork;
	int	mNuclearWeapon;
	int	mSpaceProgram;
	//President	*mPresident;
	bool mIncreasePopulation;



	//Huvudf�nstret f�r kapitalisterna
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

	//GUI f�r taxes
	std::shared_ptr<GUIElement> mTaxesWindow;
	std::shared_ptr<GUIElement> mTaxesImage;
	
	std::shared_ptr<GUIElement> mIncreaseTaxesButton;
	std::shared_ptr<GUIElement> mDecreaseTaxesButton;
	std::shared_ptr<GUIElement> mIncreaseTaxesImage;
	std::shared_ptr<GUIElement> mDecreaseTaxesImage;

	std::shared_ptr<GUIElement> mTaxesCloseButton;
	std::shared_ptr<GUIElement> mTaxesCloseImage;


	//GUI f�r resurser
	std::shared_ptr<GUIElement> mResourceWindow;
	std::shared_ptr<GUIElement> mResourceImage;

	std::shared_ptr<GUIElement> mResourceCloseButton;
	std::shared_ptr<GUIElement> mResourceCloseImage;


	//GUI f�r uppgradering
	std::shared_ptr<GUIElement> mUpgradeWindow;
	std::shared_ptr<GUIElement> mUpgradeImage;

	std::shared_ptr<GUIElement> mUpgradeCloseButton;
	std::shared_ptr<GUIElement> mUpgradeCloseImage;

	//GUI f�r uppgradering
	std::shared_ptr<GUIElement> mExportWindow;
	std::shared_ptr<GUIElement> mExportImage;

	std::shared_ptr<GUIElement> mExportCloseButton;
	std::shared_ptr<GUIElement> mExportCloseImage;
};


#endif