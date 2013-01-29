#ifndef POLITICALSYSTEM_H
#define POLITICALSYSTEM_H

#include <memory>

class GUIText;

enum PoliticalType
{
	CAPITALIST, COMMUNIST
}; 

class PoliticalSystem
{
public:
	PoliticalSystem();
	~PoliticalSystem();

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

	void		setFood(int food);
	void		setGoods(int goods);
	void		setTech(int tech);
	void		setTaxes(int taxes);
	void		setRound(int round);

	void		getTaxIncome();
	void		updateFood();
	bool		enoughFood();

	bool		enableToIncreasePopulation();
	void		increasePopulation();
	
	virtual void		upgradeNuclearWeapon() = 0;
	virtual void		upgradeSpaceProgram() = 0;
	virtual void		upgradeSpyNetwork() = 0;
	virtual void		showGUI() = 0;
	virtual void		hideGUI() = 0;
protected:
	PoliticalType mType;

	int mRound;

	int	mPatriotism;
	int	mCurrency;
	int	mPopulation;

	int	mFood;
	std::shared_ptr<GUIText> mFoodText;

	int	mGoods;
	int	mTech;
	int	mTaxes;
	int	mSpyNetwork;
	int	mNuclearWeapon;
	std::shared_ptr<GUIText> mNuclearText;
	int	mSpaceProgram;
	bool mIncreasePopulation;
};

#endif