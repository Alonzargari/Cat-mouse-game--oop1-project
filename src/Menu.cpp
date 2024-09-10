#include "Menu.h"
#include "Menu.h"
#include "Macros.h"

Menu::Menu()
	:m_window{ sf::VideoMode(WINDOW_LENGTH,WINDOW_HEIGHT),"cat and mouse game" },
	m_endGameRun{false},m_showHelpScreen{false}
{
	m_window.setFramerateLimit(60);
	initStartButton();
	initHelpButton();
	initExitButton();
	initTittle("Cat & Mouse");
	initPlayAgainButton();
	initHelpScreen();

}
//---------------------------------------------------------
void Menu::menuRun()
{
	ResourceManager::GetResourceManagerInstance().playBGsound();
	sf::Vector2f Location;
	while (m_window.isOpen()&&m_endGameRun==false) 
	{
		sf::Event evnt;
		while (m_window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
				case sf::Event::Closed:
				{
					ResourceManager::GetResourceManagerInstance().stopBGsound();
					m_window.close();
					break;
				}
				case sf::Event::MouseButtonReleased: 
				{
					Location = m_window.mapPixelToCoords
					({ evnt.mouseButton.x, evnt.mouseButton.y });
					handleCLick(Location, m_window);
					break;
				}
				case sf::Event::MouseMoved:
					Location = m_window.mapPixelToCoords
					({ evnt.mouseMove.x, evnt.mouseMove.y });
					handleMouseMove(Location);
					break;
			}
			
		}
		if (m_showHelpScreen) 
		{
			drawHelpScreen();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
			{
				setShowHelpScreen();
			}
		}
		else 
		{
			drawMenu(m_window);
		}
		
	}
}
//---------------------------------------------------------
void Menu::initStartButton()
{
	sf::Sprite shape;
	shape.setTexture(*ResourceManager::GetResourceManagerInstance().getTexture((int)BUTTON_));
	shape.setScale({ 1.35,1.35 });
	shape.setOrigin({ shape.getLocalBounds().width/2,shape.getLocalBounds().height / 2 });
	shape.setPosition({800.f,300.f});
	m_buttons.push_back(shape);
	auto font = ResourceManager::GetResourceManagerInstance().getFont(0);
	m_menuText[0].setFont(*font);
	m_menuText[0].setCharacterSize(90);
	m_menuText[0].getLetterSpacing();
	m_menuText[0].setString("Play");
	m_menuText[0].setFillColor(sf::Color::White);
	m_menuText[0].setPosition({ 800.f,300.f });
	m_menuText[0].setOrigin({ 100,70 });

}
//---------------------------------------------------------
void Menu::initHelpButton()
{
	sf::Sprite shape;
	shape.setTexture(*ResourceManager::GetResourceManagerInstance().getTexture((int)BUTTON_));
	shape.setScale({ 1.35,1.35 });
	shape.setOrigin({ shape.getLocalBounds().width / 2,shape.getLocalBounds().height / 2 });
	shape.setPosition({ 800.f,550.f });
	m_buttons.push_back(shape);
	auto font = ResourceManager::GetResourceManagerInstance().getFont(0);
	m_menuText[1].setFont(*font);
	m_menuText[1].setCharacterSize(90);
	m_menuText[1].getLetterSpacing();
	m_menuText[1].setString("Help");
	m_menuText[1].setFillColor(sf::Color::White);
	m_menuText[1].setPosition({ 800.f,550.f });
	m_menuText[1].setOrigin({ 100,70 });
}
//---------------------------------------------------------
void Menu::initExitButton()
{
	sf::Sprite shape;
	shape.setTexture(*ResourceManager::GetResourceManagerInstance().getTexture((int)BUTTON_));
	shape.setScale({ 1.35,1.35 });
	shape.setOrigin({ shape.getLocalBounds().width / 2,shape.getLocalBounds().height / 2 });
	shape.setPosition({ 800.f,800.f });
	m_buttons.push_back(shape);
	auto font = ResourceManager::GetResourceManagerInstance().getFont(0);
	m_menuText[2].setFont(*font);
	m_menuText[2].setCharacterSize(90);
	m_menuText[2].getLetterSpacing();
	m_menuText[2].setString("Exit");
	m_menuText[2].setFillColor(sf::Color::White);
	m_menuText[2].setPosition({ 800.f,800.f});
	m_menuText[2].setOrigin({ 100,65 });
}
//---------------------------------------------------------
void Menu::initPlayAgainButton()
{
	sf::Sprite shape;
	shape.setTexture(*ResourceManager::GetResourceManagerInstance().getTexture((int)BUTTON_));
	shape.setScale({ 1.35,1.35 });
	shape.setOrigin({ shape.getLocalBounds().width / 2,shape.getLocalBounds().height / 2 });
	shape.setPosition({ 800.f,550.f });
	m_buttons.push_back(shape);
	auto font = ResourceManager::GetResourceManagerInstance().getFont(0);
	m_menuText[3].setFont(*font);
	m_menuText[3].setCharacterSize(70);
	m_menuText[3].getLetterSpacing();
	m_menuText[3].setString("Play Again");
	m_menuText[3].setFillColor(sf::Color::White);
	m_menuText[3].setPosition({ 800.f,550.f });
	m_menuText[3].setOrigin({ 190,65 });
}
//---------------------------------------------------------
void Menu::initTittle(std::string str)
{
	auto font = ResourceManager::GetResourceManagerInstance().getFont(1);
	m_menuText[4].setFont(*font);
	m_menuText[4].setCharacterSize(90);
	m_menuText[4].getLetterSpacing();
	m_menuText[4].setString(str);
	m_menuText[4].setFillColor(sf::Color{255,128,0});
	m_menuText[4].setOutlineColor(sf::Color::Black);
	m_menuText[4].setOutlineThickness(2);
	m_menuText[4].setPosition({ 600.f,100.f });
	m_menuText[4].setOrigin({ 100,65 });
}
//---------------------------------------------------------
void Menu::handleCLick(sf::Vector2f location, sf::RenderWindow& window)
{
	if (m_endGameRun==false) 
	{
		if (m_menuText[0].getGlobalBounds().contains(location))
		{
			ResourceManager::GetResourceManagerInstance().stopBGsound();
			game.Run(m_window, *this);
		}
		if (m_menuText[1].getGlobalBounds().contains(location)) 
		{
			setShowHelpScreen();
		}
		if (m_menuText[2].getGlobalBounds().contains(location))
		{
			ResourceManager::GetResourceManagerInstance().stopBGsound();
			window.close();
		}
	}
	else 
	{
		
		if (m_menuText[3].getGlobalBounds().contains(location))
		{
			setRunEndScreen();
		}
		if (m_menuText[2].getGlobalBounds().contains(location))
		{
			ResourceManager::GetResourceManagerInstance().stopBGsound();
			window.close();
		}

	}
	
	
}
//---------------------------------------------------------
void Menu::handleMouseMove(sf::Vector2f location)
{
	int i = 0;
	m_endGameRun == false ?i = 0 : i = 2;
	for (i;i < m_buttons.size();i++) 
	{
		if (m_menuText[i].getGlobalBounds().contains(location))
		{
			m_buttons[i].setScale({ 1.5,1.5 });
			m_buttons[i].setOrigin(m_buttons[0].getLocalBounds().width / 2,
								   m_buttons[0].getLocalBounds().height / 2);
		}
		else
		{
			m_buttons[i].setScale({ 1.35,1.35 });
			m_buttons[i].setOrigin(m_buttons[0].getLocalBounds().width / 2,
								   m_buttons[0].getLocalBounds().height / 2);

		}
	}
	
}
//---------------------------------------------------------
void Menu::drawMenu(sf::RenderWindow& window)
{
	window.clear();
	sf::RectangleShape backGround;
	backGround.setSize({ 1600,900 });
	backGround.setTexture(ResourceManager::GetResourceManagerInstance().getTexture((int)MENU_BG_));
	window.draw(backGround);
	for (int i = 0;i < m_buttons.size()-1;i++) 
	{
		window.draw(m_buttons[i]);
		window.draw(m_menuText[i]);;
	}
	window.draw(m_menuText[4]);
	window.display();
}
//---------------------------------------------------------
void Menu::runEndScreen(std::string str)
{
	if (str=="You Lost :(") 
	{
		ResourceManager::GetResourceManagerInstance().playSound((int)GAMEOVER_);
	}
	else 
	{
		ResourceManager::GetResourceManagerInstance().playSound((int)SUCCESS_);
	}
	initTittle(str);
	sf::Vector2f Location;
	while (m_window.isOpen() && m_endGameRun == true)
	{
		sf::Event evnt;
		while (m_window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
			{
				m_window.close();
				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				Location = m_window.mapPixelToCoords
				({ evnt.mouseButton.x, evnt.mouseButton.y });
				handleCLick(Location, m_window);
				break;
			}
			case sf::Event::MouseMoved:
				Location = m_window.mapPixelToCoords
				({ evnt.mouseMove.x, evnt.mouseMove.y });
				handleMouseMove(Location);
				break;
			}
		}
		if (m_endGameRun == false)
		{
			game.Run(m_window, *this);
		}

		drawEndScreenMenu(m_window);
	}
	
}
//-----------------------------------------------------
void Menu::drawEndScreenMenu(sf::RenderWindow& window)
{
	window.clear(sf::Color{51,255,255});
	for (int i = 2;i < m_buttons.size();i++)
	{
		window.draw(m_buttons[i]);
		window.draw(m_menuText[i]);;
	}
	window.draw(m_menuText[4]);
	window.display();
}
//---------------------------------------------------------
//to know what screen to display 
void Menu::setRunEndScreen()
{
	m_endGameRun = !m_endGameRun;
}
//---------------------------------------------------------
void Menu::initHelpScreen()
{
	m_helpScreen.setTexture(*ResourceManager::GetResourceManagerInstance().getTexture(HELP_SCREEN_));
}
//---------------------------------------------------------
void Menu::drawHelpScreen()
{
	m_window.clear();
	m_window.draw(m_helpScreen);
	m_window.display();
}
//---------------------------------------------------------
void Menu::setShowHelpScreen()
{
	m_showHelpScreen = !m_showHelpScreen;
}

