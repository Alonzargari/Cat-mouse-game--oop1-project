#include "ResourceManager.h"


ResourceManager& ResourceManager::GetResourceManagerInstance()
{
	static ResourceManager resourceManager;
	return resourceManager;
}
ResourceManager::ResourceManager()
{
	m_levelSFile=OpenLevelFile("Playlist.txt");
	openLevels();
	loadTextures();
	loadFonts();
	loadMusic();
}
//---------------------------------------------------------
void ResourceManager::loadTextures()
{
	std::string strings[16] = { "mouse.png","cat.png","cheese.png","wall.png",
		"door.png","key.png","bomber.png","life.png","timer.png","freeze.png",
		"menuBG.png","button.png","gameBG.png","restartB.png","homeB.png","helpScreen.png"};
	for (int i = 0;i < 16;i++)
	{
		sf::Texture* texture=new sf::Texture();
		if (!texture->loadFromFile(strings[i]))
		{
			std::cout << "could not load picture" << std::endl;
			exit(EXIT_FAILURE);
		}
		m_texture.push_back(texture);
	}
}
//---------------------------------------------------------
void ResourceManager::loadMusic()
{
	std::string strings[12] = {"BGmusic.ogg","angrycat.ogg","catbomb.ogg","eating.ogg",
		"extralife.ogg","extratime.ogg","freeze.ogg","gameover.ogg","successlevel.ogg",
		"timeleft.ogg","keysound.ogg","dooropen.ogg"};
	for (int i = 0;i < 12;i++)
	{
		sf::SoundBuffer* sound = new sf::SoundBuffer();
		if (!sound->loadFromFile(strings[i]))
		{
			std::cout << "could not load font" << std::endl;
			exit(EXIT_FAILURE);
		}
		m_sounds.push_back(sound);
	}
	

}
//---------------------------------------------------------
void ResourceManager::playSound(int index)
{
	m_currentSound.setBuffer( *m_sounds[index]);
	m_currentSound.play();
}
//---------------------------------------------------------
void ResourceManager::playBGsound()
{
	m_BGSound.setBuffer(*m_sounds[(int)BGMUSIC_]);
	m_BGSound.play();
}
//---------------------------------------------------------
void ResourceManager::stopBGsound()
{
	m_BGSound.stop();
}
//---------------------------------------------------------
sf::Texture* ResourceManager::getTexture(int index)
{
	return m_texture[index];
}
//---------------------------------------------------------
void ResourceManager::loadFonts()
{
	std::string strings[3] = { "C:/Windows/Fonts/COOPBL.ttf","C:/Windows/Fonts/ALGER.ttf","C:/Windows/Fonts/CHILLER.ttf" };
	for (int i = 0;i < 3;i++) 
	{
		sf::Font* font = new sf::Font();
		if (!font->loadFromFile(strings[i]))
		{
			std::cout << "could not load font" << std::endl;
			exit(EXIT_FAILURE);
		}
		m_menuFonts.push_back(font);
	}

}
//---------------------------------------------------------
sf::Font* ResourceManager::getFont(int index)
{
	return m_menuFonts[index];
}
//---------------------------------------------------------
//open the playlist file
std::ifstream ResourceManager::OpenLevelFile(const std::string& name)
{
	std::ifstream level;
	level.open(name);
	if (!level.is_open())
	{
		std::cerr << "cannot open level";
		exit(EXIT_FAILURE);
	}
	return level;
}

//---------------------------------------------------------
//open the levels that in the playlist 
void ResourceManager::openLevels()
{
	std::string str;
	while (std::getline(m_levelSFile, str))
	{
		m_levelsInFile.emplace_back(str);
	}
}
//---------------------------------------------------------
 std::string ResourceManager::getLevel(int index) const
{
	return m_levelsInFile[index];
}
 //----------------------------------------------------------
 int ResourceManager::getLevelAmount() const
 {
	 return m_levelsInFile.size();
 }