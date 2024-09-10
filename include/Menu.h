#pragma once
#include <SFML/Graphics.hpp>
#include "GameController.h"
#include "ResourceManager.h"

class Menu 
{
public:
	Menu();
	~Menu() = default;
	void menuRun();
	//init buttons in the menu
	void initStartButton();
	void initHelpButton();
	void initExitButton();
	void initPlayAgainButton();
	void initTittle(std::string str);
	//handle mouse events (click on button or to make the button bigger)
	void handleCLick(sf::Vector2f,sf::RenderWindow&);
	void handleMouseMove(sf::Vector2f);
	void drawMenu(sf::RenderWindow& window);
	void runEndScreen(std::string str);
	void drawEndScreenMenu(sf::RenderWindow& window);

	void setRunEndScreen();
	void initHelpScreen();
	void drawHelpScreen();
	void setShowHelpScreen();
private:
	GameController game;
	sf::RenderWindow m_window;
	sf::Text m_menuText[5];
	std::vector<sf::Sprite>m_buttons;
	sf::Sprite m_helpScreen;
	bool m_isButtonHovered;
	bool m_endGameRun;
	bool m_showHelpScreen;

};