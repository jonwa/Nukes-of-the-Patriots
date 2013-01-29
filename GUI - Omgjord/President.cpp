#include "president.h"
#include <iostream>

President::President(const std::string &filename)
	
	
{
	
	initializeImages(filename);
	randomStatFunc();
}

President::~President()
{

}

void President::randomStatFunc()
{
	Randomizer *randomizer;
	randomizer = Randomizer::getInstance();

	randomStats.push_back("foodPrice");
	randomStats.push_back("goodsPrice");
	randomStats.push_back("techPrice");
	randomStats.push_back("nuclearPrice");
	randomStats.push_back("spacePrice");
	randomStats.push_back("spyPrice");
	randomStats.push_back("patriotismTax");
	

	std::map<std::string, float> posStatMap;
	posStatMap.insert(std::pair<std::string,float>("foodPrice", -2));
	posStatMap.insert(std::pair<std::string,float>("goodsPrice", -2));
	posStatMap.insert(std::pair<std::string,float>("techPrice", -2));
	posStatMap.insert(std::pair<std::string,float>("nuclearPrice", -0.2));
	posStatMap.insert(std::pair<std::string,float>("spacePrice", -0.2));
	posStatMap.insert(std::pair<std::string,float>("spyPrice", -0.2));
	posStatMap.insert(std::pair<std::string,float>("patriotismTax", 1));

	std::map<std::string, float> negStatMap;
	negStatMap.insert(std::pair<std::string,float>("foodPrice", 2));
	negStatMap.insert(std::pair<std::string,float>("goodsPrice", 2));
	negStatMap.insert(std::pair<std::string,float>("techPrice", 2));
	negStatMap.insert(std::pair<std::string,float>("nuclearPrice", 0.2));
	negStatMap.insert(std::pair<std::string,float>("spacePrice", 0.2));
	negStatMap.insert(std::pair<std::string,float>("spyPrice", 0.2));
	negStatMap.insert(std::pair<std::string,float>("popEatsMore", 0.1));

	int random = ( randomizer->randomNr(randomStats.size(),0) );

	mValues.insert(std::pair<std::string,float>(randomStats[random], posStatMap.find(randomStats[random])->second));
	randomStats[random] = randomStats.back();
	randomStats.pop_back();

	random = ( randomizer->randomNr(randomStats.size(),0) );
	mValues.insert(std::pair<std::string,float>(randomStats[random], posStatMap.find(randomStats[random])->second));
	randomStats[random] = randomStats.back();
	randomStats.pop_back();

	
	randomStats.push_back("popEatsMore");
	random = ( randomizer->randomNr(randomStats.size(),0) );

	if(randomStats[random] == "patriotismTax")
	{
		randomStats[random] = randomStats.back();
		randomStats.pop_back();
		random = ( randomizer->randomNr(randomStats.size(),0) );
	}

	mValues.insert(std::pair<std::string,float>(randomStats[random], negStatMap.find(randomStats[random])->second));
	randomStats[random] = randomStats.back();
	randomStats.pop_back();

	for(std::vector<std::string>::iterator it = randomStats.begin(); it != randomStats.end(); it++)
	{
		float a = 0;
		mValues.insert(std::pair<std::string, float>((*it), a));
	}

	randomStats.clear();
}



float President::getFoodPriceModifier()
{
	return mValues["foodPrice"];
}

float President::getGoodsPriceModifier()
{
	return mValues["goodsPrice"];
}

float President::getTechPriceModifier()
{
	return mValues["techPrice"];
}

float President::getNuclearPriceModifier()
{
	return mValues["nuclearPrice"];
}

float President::getSpacePriceModifier()
{
	return mValues["spacePrice"];
}

float President::getSpyPriceModifier()
{
	return mValues["spyPrice"];
}

float President::getPatriotismTaxModifier()
{
	return mValues["patriotismTax"];
}

float President::getPopEatsMore()
{
	return mValues["popEatsMore"];
}

void President::initializeImages(const std::string &path)
{
	mPortrait.loadFromFile(path);

}

