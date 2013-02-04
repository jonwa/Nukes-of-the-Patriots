#include "ResourceHandler.h"
#include "tinyxml2.h"
#include <iostream>
#include <cassert>

//Skapar en instans av klassen genom att g�ra denna till en Singleton
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

 /*M�jligg�r att det g�r att h�mta ut bilder fr�n std::map som laddas
   in fr�n XML dokumentet
   
     Av: Jon Wahlstr�m 2013-31-01*/
sf::Texture& ResourceHandler::getTexture(std::string &path)
{
	//assert(Images.count(string) == 1);
	return Images[path];
}

 /*
	Ladda in samtliga bilder som anges i XML dokumentet Images 
	och l�gger in dessa i en std::map
	
	  Av: Jon Wahlstr�m 2013-31-01					*/
void ResourceHandler::load()
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile("XML/Images.xml");

	if(doc.Error())
		std::cout << "Fel! inh�mtning av alla bilder";
	
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




/*********************	
 *	MUSIC FUNKTIONER *
 *********************/
