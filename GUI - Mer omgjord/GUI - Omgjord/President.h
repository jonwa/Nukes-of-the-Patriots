#pragma once
#include <string>
#include "randomizer.h"
#include <vector>

#include <SFML/Graphics.hpp>

// President-klass av Joakim Stark
//randomStatFunc har en vektor med random stats, den slumpar fram 3 stats som sedan får värden mappade till sig.
//
//Användningsexempel:
//		President *mPresident;
//		mPresident = new President(filename);
//		mFood = mPresident->getFoodPriceModifier();

class President
{
public:
	President(const std::string& filename);
	~President();

	void initializeImages(const std::string &path);

	float getFoodPriceModifier();
	float getGoodsPriceModifier();
	float getTechPriceModifier();
	float getNuclearPriceModifier();
	float getSpacePriceModifier();
	float getSpyPriceModifier();
	float getPatriotismTaxModifier();
	float getPopEatsMore();


private:
	void randomStatFunc();
	sf::Image mPortrait;
	std::map <std::string,float> mValues;
	std::vector<std::string> randomStats;
	
};