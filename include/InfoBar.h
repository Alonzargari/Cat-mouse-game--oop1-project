#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include <string>
#include <iostream>
#include "Mouse.h"
#include <Level.h>

class InfoBar
{
public:
	InfoBar();
	~InfoBar() = default;
	void setTimeInfo();
	void setLifeInfo(Mouse mouse);
	void setCheeseAmount(int cheeseAmount);
	void setKeysAmount();
	void updateLifeInfo(Mouse mouse);
	void updateTimeInfo();
	void updateCheeseAmount();
	void setPoints();
	void updatePoints(int);
	void SetLevelNo(int);
	void updateLevelNo(int);
	void updateKeys(int);
	int getCheeseAmount();
	void drawInfoBar(sf::RenderWindow& window);
	void restartClock();
private:
	sf::RectangleShape m_barBase;
	sf::Font* m_font;

	sf::Clock m_Timer;
	int m_limitTime;
	sf::Text m_gameTime;

	int m_cheeseCounter;
	sf::RectangleShape m_cheese;
	sf::Text m_cheeseAmount;

	sf::RectangleShape m_key;
	sf::Text m_keyAmount;

	sf::Text m_levelNo;
	sf::Text m_points;
	std::vector<sf::RectangleShape>m_lifeVector;
	void setBarBase();
};