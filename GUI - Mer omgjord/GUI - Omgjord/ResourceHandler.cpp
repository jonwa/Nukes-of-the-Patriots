#include "ResourceHandler.h"
#include "tinyxml2.h"
#include <iostream>
#include <cassert>

//Skapar en instans av klassen genom att göra denna till en Singleton
ResourceHandler* ResourceHandler::mInstance = NULL;
ResourceHandler* ResourceHandler::getInstance()
{
	if(mInstance == NULL)
	{
		mInstance = new ResourceHandler();
	}
	return mInstance;	
}

ResourceHandler::ResourceHandler() { }

//Destruktor, kör internalClear funktionen för att rensa mapparna
ResourceHandler::~ResourceHandler() { }


/*********************	
 *	IMAGE FUNKTIONER *
 *********************/

//Laddar in bilder i en std::map
void ResourceHandler::loadTexture(const std::string &path, const std::string &key)
{
	if(Images.count(key) == NULL)
	{
		Images[key].loadFromFile(path);
	}
}

 /*Möjliggör att det går att hämta ut bilder från std::map som laddas
   in från XML dokumentet
   
     Av: Jon Wahlström 2013-31-01*/
sf::Texture& ResourceHandler::getTexture(std::string &string)
{
	//assert(Images.count(string) == 1);
	return Images[string];
}

 /*
	Ladda in samtliga bilder som anges i XML dokumentet Images 
	och lägger in dessa i en std::map
	
	  Av: Jon Wahlström 2013-31-01					*/
void ResourceHandler::load()
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile("XML/Images.xml");

	if(doc.Error())
		std::cout << "Fel!";
	
	tinyxml2::XMLElement *element = doc.FirstChildElement("images");
	while (element != 0)
	{
		tinyxml2::XMLElement *textures = element->FirstChildElement("image");
		std::string directory = element->Attribute("directory");
		while (textures != 0)
		{
			std::string filename = textures->Attribute("filename");
			std::string key		 = filename.substr(0, filename.length() - 4);
			loadTexture("Images/" + directory + "/" + filename, directory + "/" + key);	

			textures = textures->NextSiblingElement();
		}
		element = element->NextSiblingElement();
	}
}

/*********************	
 *	SOUND FUNKTIONER *
 *********************/

//Laddar in ett ljud i en sf::SoundBuffer pekare. 
sf::SoundBuffer* ResourceHandler::loadSoundFromFile(const std::string &path)
{
	sf::SoundBuffer* buffer = new sf::SoundBuffer; 
	buffer->loadFromFile(path);

	/*
	 * Kollar om filen laddas in korrekt. Om inte så avallokeras minnet
	 * och returnerar en tom pekare.
	 */
	if(!buffer->loadFromFile(path))
	{
		std::cout << "ERROR! kan inte ladda in ljud" << std::endl;
		delete buffer;
	}

	return buffer;
}

//Laddar in ljud i en std::map
sf::SoundBuffer* ResourceHandler::loadSound(const std::string &path) 
{
	//skapar en soundbufferpekare och tilldelar denna musiken som hör till strängen som laddats in
	sf::SoundBuffer* buffer = Sounds[path]; 

	/*
	 * Om sf::SoundBuffer pekaren har värdet noll tilldelas dennna informationen från funktionen 
	 * loadSoundFromFile och ger informationenen vidare i mappen med en tillhörande sträng 
	 */
	if(buffer == NULL) 
	{
		buffer = loadSoundFromFile(path);
		Sounds[path] = buffer;
	}
	return buffer;
}


/*********************	
 *	MUSIC FUNKTIONER *
 *********************/

//Laddar in ett musik i en sf::Music pekare.
sf::Music* ResourceHandler::loadMusicFromFile(const std::string &path)
{
	sf::Music* music = new sf::Music;
	music->openFromFile(path);

	/*
	 * Kollar om filen laddas in korrekt. Om inte så avallokeras minnet
	 * och returnerar en tom pekare.
	 */
	if(!music->openFromFile(path))
	{
		std::cout << "ERROR! kan inte ladda in musik" << std::endl;
		delete music;
	}
	return music;
}

//Laddar in musik i en std::map
sf::Music* ResourceHandler::loadMusic(const std::string &path)
{
	//skapar en musicpekare och tilldelar denna musiken som hör till strängen som laddats in
	sf::Music* music = Music[path]; 

	/*
	 * Om sf::Music pekaren har värdet noll tilldelas dennna informationen från funktionen 
	 * loadMusicFromFile och ger informationenen vidare i mappen med en tillhörande sträng 
	 */
	if(music == NULL) 
	{
		music = loadMusicFromFile(path);
		Music[path] = music;
	}
	return music;
}
