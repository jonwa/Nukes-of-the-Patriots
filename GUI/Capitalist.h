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
#include <SFML\Graphics\RenderWindow.hpp>

class Capitalist
{
public:
	Capitalist();
	~Capitalist();

	int			getFood();
	int			getGoods();
	int			getTech();
	int			getTaxes();
	int			getNuclearWeapon();
	int			getSpaceProgram();
	int			getSpyNetwork();
	int			getCurrency();
	//President	getPresident();

	void		setFood(int food);
	void		setGoods(int goods);
	void		setTech(int tech);
	void		setTaxes(int taxes);
	//void		setPresident(President &president);

	void		getTaxIncome();
	void		updateFood();
	bool		enoughFood();


	void		initializeCapitalistWindowInformation();

	/*updatefunktion f�r menyknappar*/
	void		update(GUIElement *guiElement);
	void		render();

	/*Menyknappar f�r kapitalister n�r de har aktiverats*/
	void		triggerTaxesMenu();


	void		closeWindow(GUIWindow *guiWindow);

	void		upgradeNuclearWeapon();
	void		upgradeSpaceProgram();
	void		upgradeSpyNetwork();

	bool		enableToIncreasePopulation();
	void		increasePopulation();

private:
	int			mPatriotism;
	int			mCurrency;
	int			mPopulation;
	int			mFood;
	int			mGoods;
	int			mTech;
	int			mTaxes;
	int			mSpyNetwork;
	int			mNuclearWeapon;
	int			mSpaceProgram;
	//President	*mPresident;
	bool		mIncreasePopulation;


	GUIWindow *mTaxesWindow;
	GUIImage  *mTaxesImage;
	

	/*GUI-knappar som h�r till taxes menyn*/
	GUIButton *mIncreaseTaxes;
	GUIButton *mDecreaseTaxes;
	GUIImage *mIncreaseTaxesImage;
	GUIImage *mDecreaseTaxesImage;


	GUIButton *mCloseWindow;


	GUIManager *guiManager;





	/*
	 * Medlemsvariabler f�r GUI
	 */

	GUIWindow *mCapitalistMainWindow;		
	GUIImage  *mCapitalistMainWindowImage;	
	GUIButton *mCapitalistTaxesButton;		
	GUIButton *mCapitalistResourcesButton;	
	GUIButton *mCapitalistUpgradeButton;		
	GUIButton *mCapitalistExportButton;	
	GUIImage  *mCapitalistTaxesImage;
	GUIImage  *mCapitalistResourceImage;
	GUIImage  *mCapitalistUpgradeImage;
	GUIImage  *mCapitalistExportImage;

	

};


#endif