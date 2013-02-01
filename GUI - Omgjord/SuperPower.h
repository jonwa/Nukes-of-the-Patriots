#ifndef SUPERPOWER_H
#define SUPERPOWER_H

#include <memory>

class GUIText;

enum PoliticalType
{
	CAPITALIST, COMMUNIST
}; 

class SuperPower
{
public:
	SuperPower();
	~SuperPower();

	int			getFood();
	int			getGoods();
	int			getTech();
	int			getTaxes();
	int			getPopulation();
	int			getNuclearWeapon();
	int			getSpaceProgram();
	int			getSpyNetwork();
	int			getCurrency();
	int			getRound();

	PoliticalType getType();

	void		setRound(int round);

	void		getTaxIncome();
	void		updateFood();
	bool		enoughFood();

	bool		enableToIncreasePopulation();
	void		increasePopulation();
	
	virtual void		upgradeNuclearWeapon(int currentNuclearCount, int currentGoods, int currentTech) = 0;
	virtual void		upgradeSpaceProgram(int currentSpaceCount, int currentGoods, int currentTech) = 0;
	virtual void		upgradeSpyNetwork(int currentSpyCount, int currentTech) = 0;
	virtual int			increaseTaxCost(int currentTax) = 0;
	virtual int			decreaseTaxCost(int currentTax) = 0;
	virtual void		setFood(int foodCount, int currentCurrency, int value) = 0;
	virtual void		setGoods(int goodsCount, int currentCurrency, int value) = 0;
	virtual void		setTech(int techCount, int currentCurrency, int value) = 0;
	virtual void		showGUI() = 0;
	virtual void		hideGUI() = 0;
protected:
	PoliticalType mType;

	int mRound;

	int	mPatriotism;
	int	mCurrency, mCurrencyUpdate;
	int	mPopulation;

	int	mFood, mFoodUpdate;
	std::shared_ptr<GUIText> mFoodText;

	int	mGoods, mGoodsUpdate;
	int	mTech, mTechUpdate;
	int	mTaxes, mTaxesUpdate;
	int	mSpyNetwork, mSpyNetworkUpdate;
	int	mNuclearWeapon, mNuclearWeaponUpdate;
	std::shared_ptr<GUIText> mNuclearText;
	int	mSpaceProgram, mSpaceProgramUpdate;
	bool mIncreasePopulation;
};

#endif