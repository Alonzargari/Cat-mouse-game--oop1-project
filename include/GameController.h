#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "GameObjects.h"
#include "Macros.h"
#include "Level.h"
#include "Mouse.h"
#include "InfoBar.h"
#include "Cat.h"
#include <SFML/Graphics.hpp>

class Menu;

class GameController
{
public:
	GameController();
	~GameController()=default;
	void Run(sf::RenderWindow&, Menu& menu);
	void setMouse(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size);
	void setCats(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size);
	bool timeLeft();
	void setFreezeCats();
	void PopCats();
	void setBeforeGame();
	void restart();
	void movmentsOfObjects(const sf::Time);
	void gameDraw(sf::RenderWindow& window);
	void nextLevel();
	void initButtons();
	void drawBackground(sf::RenderWindow& window);
	void handleCLick(sf::Vector2f Location, sf::RenderWindow& window,Menu& menu);
	void handleMouseMove(sf::Vector2f Location);
	void setNewGame();
	void handleEvent(sf::RenderWindow& window, Menu& menu);
	void returnCatsToStartPosition();
private:
	std::ifstream OpenLevelFile(std::string name);
	std::ifstream m_levelFile;
	std::string m_levelFileName;
	sf::Sprite m_returnToMenu;
	sf::Sprite m_restart;
	int m_LevelNo;
	InfoBar m_infoBar;
	Level m_level;
	Mouse m_mouse;
	std::vector<Cat> m_cats;
	sf::Clock m_timer;
	bool m_needToFreezeCats;
	bool m_startNewGame;
};