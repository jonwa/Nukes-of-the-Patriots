#include "ResourceHandler.h"
#include <iostream>

//Skapar en instanse av klassen genom att göra denna till en Singleton
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
ResourceHandler::~ResourceHandler() { internalClear(); }


/*********************	
 *	IMAGE FUNKTIONER *
 *********************/

//Laddar in en bild i en sf::Image pekare. 
sf::Image* ResourceHandler::loadImageFromFile(const std::string &path)
{
	sf::Image* image = new sf::Image;
	image->loadFromFile(path);

	/*
	 * Kollar om filen laddas in korrekt. Om inte så avallokeras minnet
	 * och returnerar en tom pekare.
	 */
	if(!image->loadFromFile(path))
	{
		std::cout << "ERROR! kan inte ladda in bild" << std::endl;
		delete image;
	}
	return image;
}

//Laddar in bilder i en std::map
sf::Image* ResourceHandler::loadImage(const std::string &path)
{
	//skapar en imagepekare och tilldelar denna bilden som hör till strängen som laddats in
	sf::Image* image = Images[path]; 

	/*
	 * Om sf::Image pekaren har värdet noll tilldelas dennna informationen från funktionen
	 * loadImageFromFile och ger informationenen vidare i mappen med en tillhörande sträng 
	 */
	if(image == NULL) 
	{
		image = loadImageFromFile(path);
		Images[path] = image;
	}
	return image;
}

//Renderar bilderna på displayen
void ResourceHandler::render(sf::Drawable *drawable)
{
	
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


//Rensar mapparna från information
void ResourceHandler::internalClear()
{
	/*
	 * lägger in samtliga pekare från std::map av sf::Image i en  
	 * temporär sf::Image-pekare och deletar dessa,
	 * sedan rensas hela mappen från objekt
	 */
	for(std::map<std::string, sf::Image*>::iterator i = Images.begin(); i != Images.end(); i++)
	{
		delete i->second;
		Images.erase(i);
	}

	/*
	 * lägger in samtliga pekare från std::map av sf::Sound i en  
	 * temporär sf::Sound-pekare och deletar dessa,
	 * sedan rensas hela mappen från objekt
	 */
	for(std::map<std::string, sf::SoundBuffer*>::iterator j = Sounds.begin(); j != Sounds.end(); j++)
	{
		delete j->second;
		Sounds.erase(j);
	}

	/*
	 * lägger in samtliga pekare från std::map av sf::Music i en  
	 * temporär sf::Music-pekare och deletar dessa,
	 * sedan rensas hela mappen från objekt
	 */
	for(std::map<std::string, sf::Music*>::iterator k = Music.begin(); k != Music.end(); k++)
	{
		delete k->second;
		Music.erase(k);
	}
}