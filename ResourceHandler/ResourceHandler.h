/*
 *	Denna klass tar hand om alla typer av resurshanteringar som används i spelet
 *	Nukes of the Patriots.
 *
 *	Dessa resurser är inhämtning av : 
 *	 
 *	 -Bilder
 *	 -Ljud
 *	 -Musik
 *  
 *  För att använda klassen inkluderas denna där den behövs och klassen i fråga får i konstruktorn skriva följande
 *  först får en medlemsvariabel av typen sf::Texture samt sf::Sprite skapas i klassen. Dessa används sedan i konstruktorn. 
 *  Dessa skall vara statiska.
 *
 *   EXEMPEL : 
 *				mPlayerTexture.loadFromImage(*ResourceHandler::getInstance()->loadImage("Player.png"));
 *	
 *				mPlayerSprite.setTexture(mPlayerTexture);
 *
 *										
 *		Av: Jon Wahlström 20-01-2013 
 */

#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H

#include <SFML\Graphics\Image.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Audio\Music.hpp>
#include <SFML\Audio\Sound.hpp>
#include <SFML\Audio\SoundBuffer.hpp>
#include <SFML\System\Clock.hpp>

#include <string>
#include <map>

class ResourceHandler
{
public:
	~ResourceHandler();
	
	//Singleton mönster för instansiering
	static ResourceHandler* getInstance();

	//Image funktioner
	static sf::Image* loadImageFromFile(const std::string &path);
	sf::Image* loadImage(const std::string &path);
	static void render(sf::Drawable *drawable);
	//sf::Image* getImageFromMap();

	//Sound funktioner
	static sf::SoundBuffer* loadSoundFromFile(const std::string &path);
	sf::SoundBuffer* loadSound(const std::string &path);
	/*sf::Sound* getSoundFromMap();*/

	//Music funktioner
	static sf::Music* loadMusicFromFile(const std::string &path);
	sf::Music* loadMusic(const std::string &path);
	sf::Music* getMusicFromMap();

private:
	ResourceHandler();
	ResourceHandler operator = (const ResourceHandler& resourceHandler) { }
	ResourceHandler(const ResourceHandler& copy) { }

	//Singleton mönster för instansiering
	static ResourceHandler* mInstance;

	//std::map :ar innehållandes Images, SoundBuffers and Music
	std::map<std::string, sf::Image*> Images;
	std::map<std::string, sf::Music*> Music;
	std::map<std::string, sf::SoundBuffer*> Sounds;
	
	//används för att rensa mapparna på information
	void internalClear();
};
#endif