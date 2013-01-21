#include "ResourceHandler.h"
#include <iostream>

//Skapar en instanse av klassen genom att g�ra denna till en Singleton
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

//Destruktor, k�r internalClear funktionen f�r att rensa mapparna
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
	 * Kollar om filen laddas in korrekt. Om inte s� avallokeras minnet
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
	//skapar en imagepekare och tilldelar denna bilden som h�r till str�ngen som laddats in
	sf::Image* image = Images[path]; 

	/*
	 * Om sf::Image pekaren har v�rdet noll tilldelas dennna informationen fr�n funktionen
	 * loadImageFromFile och ger informationenen vidare i mappen med en tillh�rande str�ng 
	 */
	if(image == NULL) 
	{
		image = loadImageFromFile(path);
		Images[path] = image;
	}
	return image;
}

//Renderar bilderna p� displayen
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
	 * Kollar om filen laddas in korrekt. Om inte s� avallokeras minnet
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
	//skapar en soundbufferpekare och tilldelar denna musiken som h�r till str�ngen som laddats in
	sf::SoundBuffer* buffer = Sounds[path]; 

	/*
	 * Om sf::SoundBuffer pekaren har v�rdet noll tilldelas dennna informationen fr�n funktionen 
	 * loadSoundFromFile och ger informationenen vidare i mappen med en tillh�rande str�ng 
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
	 * Kollar om filen laddas in korrekt. Om inte s� avallokeras minnet
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
	//skapar en musicpekare och tilldelar denna musiken som h�r till str�ngen som laddats in
	sf::Music* music = Music[path]; 

	/*
	 * Om sf::Music pekaren har v�rdet noll tilldelas dennna informationen fr�n funktionen 
	 * loadMusicFromFile och ger informationenen vidare i mappen med en tillh�rande str�ng 
	 */
	if(music == NULL) 
	{
		music = loadMusicFromFile(path);
		Music[path] = music;
	}
	return music;
}


//Rensar mapparna fr�n information
void ResourceHandler::internalClear()
{
	/*
	 * l�gger in samtliga pekare fr�n std::map av sf::Image i en  
	 * tempor�r sf::Image-pekare och deletar dessa,
	 * sedan rensas hela mappen fr�n objekt
	 */
	for(std::map<std::string, sf::Image*>::iterator i = Images.begin(); i != Images.end(); i++)
	{
		delete i->second;
		Images.erase(i);
	}

	/*
	 * l�gger in samtliga pekare fr�n std::map av sf::Sound i en  
	 * tempor�r sf::Sound-pekare och deletar dessa,
	 * sedan rensas hela mappen fr�n objekt
	 */
	for(std::map<std::string, sf::SoundBuffer*>::iterator j = Sounds.begin(); j != Sounds.end(); j++)
	{
		delete j->second;
		Sounds.erase(j);
	}

	/*
	 * l�gger in samtliga pekare fr�n std::map av sf::Music i en  
	 * tempor�r sf::Music-pekare och deletar dessa,
	 * sedan rensas hela mappen fr�n objekt
	 */
	for(std::map<std::string, sf::Music*>::iterator k = Music.begin(); k != Music.end(); k++)
	{
		delete k->second;
		Music.erase(k);
	}
}