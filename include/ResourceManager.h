#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <Macros.h>
#include <vector>
#include <fstream>

class ResourceManager 
{
public:
	
	static ResourceManager& GetResourceManagerInstance();
	void loadTextures();
	void loadMusic();
	void playSound(int);
	void playBGsound();
	void stopBGsound();
	sf::Texture* getTexture(int);
	void loadFonts();
	sf::Font* getFont(int);
	void openLevels();
	std::string getLevel(int index) const;
	std::ifstream OpenLevelFile(const std::string& name);
	int getLevelAmount()const;

	

private:
	ResourceManager();
	~ResourceManager()=default;
	ResourceManager(const ResourceManager&) = default;
	ResourceManager& operator=(const ResourceManager&) = default;
	std::vector<sf::Texture*>m_texture;
	std::vector <sf::Font*>m_menuFonts;
	std::ifstream m_levelSFile;
	std::vector< std::string>m_levelsInFile;
	std::vector<sf::SoundBuffer*>m_sounds;
	sf::Sound m_currentSound;
	sf::Sound m_BGSound;
};
