#include "GameController.h"
#include "Menu.h"

//---------------------------------------------------------
GameController::GameController()
	:m_mouse({0,0},NULL,{0,0}),m_needToFreezeCats{false},m_LevelNo{0},m_startNewGame{false}

{
	m_infoBar.setPoints();
	initButtons();
}
//---------------------------------------------------------
void GameController::setMouse(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size)
{
	auto mouseShape = m_mouse.useShape();
	mouseShape.setPosition(position);
	m_mouse.setStartPosition(position);
	mouseShape.setTexture(texture);
	mouseShape.setSize(size);
	
	m_mouse.setShape(mouseShape);
}
//---------------------------------------------------------
void GameController::setCats(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size)
{
	m_cats.emplace_back(Cat(position, texture, size,this));
}
//---------------------------------------------------------
bool GameController::timeLeft()
{
	auto minuts = TimeManager::GetTimeManagerInstance().getTimeAsMinute();
	auto seconds = TimeManager::GetTimeManagerInstance().getTimeAsSecond();
	if (minuts == 0 && seconds==0) 
	{
		return true;
	}
	return false;
}
//---------------------------------------------------------
void GameController::setFreezeCats()
{
	m_needToFreezeCats = true;
}
//---------------------------------------------------------
void GameController::PopCats()
{
	m_cats.pop_back();
}
//---------------------------------------------------------
void GameController::setBeforeGame()
{
	m_mouse.mouseResetPoints();
	m_level.readLevel(m_levelFile, *this, m_infoBar);
	m_infoBar.setLifeInfo(m_mouse);
	m_infoBar.setCheeseAmount(m_level.getCheeseAmount());
	m_infoBar.setKeysAmount();
	m_infoBar.setTimeInfo();
	m_infoBar.SetLevelNo(m_LevelNo+1);
	TimeManager::GetTimeManagerInstance().RestartClocks();
	m_timer.restart();
}
//---------------------------------------------------------
void GameController::restart()
{
	m_infoBar.setPoints();
	m_needToFreezeCats = false;
	m_cats.clear();
	m_cats.shrink_to_fit();
	m_mouse.mouseRestart();
	m_level.ClearLevel();
	m_levelFile.close();
	TimeManager::GetTimeManagerInstance().RestartClocks();
}
//---------------------------------------------------------
void GameController::movmentsOfObjects(const sf::Time deltaTime)
{
	m_mouse.move(deltaTime);
	if (m_needToFreezeCats == false)
	{
		for (int i = 0;i < m_cats.size();i++)
		{
			m_cats[i].move(deltaTime, m_mouse);
			m_level.colideWithGameObjects(m_cats[i], m_infoBar);
			if (m_cats[i].checkCollision(m_mouse))
			{
				m_cats[i].handleCollisionWithMouse(m_mouse, m_infoBar);
				m_mouse.handleCollisionWithCat(m_cats[i], m_infoBar);
			}
		}
	}
	else
	{
		TimeManager::GetTimeManagerInstance().DecreaseFreezeTime();

		if(TimeManager::GetTimeManagerInstance().freezeIsOver())
		{
			m_needToFreezeCats = false;
		}
		
	}
	m_level.colideWithGameObjects(m_mouse, m_infoBar);
}
//---------------------------------------------------------
void GameController::gameDraw(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);
	drawBackground(window);
	m_level.Draw(window);
	m_infoBar.drawInfoBar(window);
	m_mouse.draw(window);
	for (int i = 0;i < m_cats.size();i++)
	{
		m_cats[i].draw(window);
	}
	window.draw(m_restart);
	window.draw(m_returnToMenu);
	window.display();
}
//---------------------------------------------------------
void GameController::nextLevel()
{
	m_LevelNo++;
	m_infoBar.updateLevelNo(m_LevelNo+1);
	if (m_LevelNo == ResourceManager::GetResourceManagerInstance().getLevelAmount())
	{
		return;
	}
	m_levelFileName = ResourceManager::GetResourceManagerInstance().getLevel(m_LevelNo);
	restart();
	m_levelFile = OpenLevelFile(m_levelFileName);
}
//---------------------------------------------------------
void GameController::initButtons()
{
	m_restart.setTexture(*ResourceManager::GetResourceManagerInstance().getTexture(RESTART_));
	m_restart.setPosition({1350,800});
	m_restart.setOrigin(m_restart.getLocalBounds().width / 2, m_restart.getLocalBounds().height / 2);
	m_returnToMenu.setTexture(*ResourceManager::GetResourceManagerInstance().getTexture(HOME_));
	m_returnToMenu.setPosition({ 1450,800 });
	m_returnToMenu.setOrigin(m_returnToMenu.getLocalBounds().width / 2, m_returnToMenu.getLocalBounds().height / 2);
}
//---------------------------------------------------------
void GameController::drawBackground(sf::RenderWindow& window)
{
	sf::RectangleShape backGround;
	backGround.setSize({ 1600,900 });
	backGround.setTexture(ResourceManager::GetResourceManagerInstance().getTexture((int)GAME_BG));
	window.draw(backGround);
}
//---------------------------------------------------------
void GameController::handleCLick(sf::Vector2f Location, sf::RenderWindow& window,Menu &menu)
{
	if (m_restart.getGlobalBounds().contains(Location))
	{
		setNewGame();
	}
	if (m_returnToMenu.getGlobalBounds().contains(Location))
	{
		restart();
		ResourceManager::GetResourceManagerInstance().stopBGsound();
		menu.menuRun();
	}
}
//---------------------------------------------------------
void GameController::handleMouseMove(sf::Vector2f Location)
{
	if (m_restart.getGlobalBounds().contains(Location))
	{
		m_restart.setScale({ 1.2,1.2 });
		m_restart.setOrigin(m_restart.getLocalBounds().width / 2,
			m_restart.getLocalBounds().height / 2);
	}
	else
	{
		m_restart.setScale({ 1,1 });
		m_restart.setOrigin(m_restart.getLocalBounds().width / 2,
			m_restart.getLocalBounds().height / 2);
	}
	if (m_returnToMenu.getGlobalBounds().contains(Location)) 
	{
		m_returnToMenu.setScale({ 1.2,1.2 });
		m_returnToMenu.setOrigin(m_returnToMenu.getLocalBounds().width / 2,
			m_returnToMenu.getLocalBounds().height / 2);
	}
	else
	{
		m_returnToMenu.setScale({ 1,1 });
		m_returnToMenu.setOrigin(m_returnToMenu.getLocalBounds().width / 2,
			m_returnToMenu.getLocalBounds().height / 2);
	}
}
//---------------------------------------------------------
void GameController::setNewGame()
{
	m_startNewGame = !m_startNewGame;
}
//---------------------------------------------------------
void GameController::handleEvent(sf::RenderWindow& window,Menu& menu)
{
	sf::Event evnt;
	sf::Vector2f Location;
	while (window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
		{
			ResourceManager::GetResourceManagerInstance().stopBGsound();
			window.close();
			break;
		}
		case sf::Event::MouseButtonReleased:
		{
			Location = window.mapPixelToCoords
			({ evnt.mouseButton.x, evnt.mouseButton.y });
			handleCLick(Location, window, menu);
			break;
		}
		case sf::Event::MouseMoved:
			Location = window.mapPixelToCoords
			({ evnt.mouseMove.x, evnt.mouseMove.y });
			handleMouseMove(Location);
			break;
		}

	}
}
//---------------------------------------------------------
void GameController::returnCatsToStartPosition()
{
	for (int i = 0;i < m_cats.size();i++) 
	{
		auto startPosition= m_cats[i].getStartPosition();
		m_cats[i].setLocation(startPosition,{0,0});
	}
}
//---------------------------------------------------------
void GameController::Run(sf::RenderWindow& window, Menu& menu)
{
		ResourceManager::GetResourceManagerInstance().playBGsound();
		m_LevelNo = 0;
		m_levelFileName = ResourceManager::GetResourceManagerInstance().getLevel(m_LevelNo);
		m_levelFile = OpenLevelFile(m_levelFileName);
		while (m_levelFile.is_open()&&m_LevelNo<ResourceManager::GetResourceManagerInstance().getLevelAmount())
		{
			setBeforeGame();
			while (window.isOpen()) 
			{
				
				const auto deltaTime = m_timer.restart();
				handleEvent(window,menu);
				movmentsOfObjects(deltaTime);
				m_infoBar.updateTimeInfo();
				if (timeLeft())
				{
					restart();
					m_levelFile = OpenLevelFile(m_levelFileName);
					break;
				}
				if (m_startNewGame) 
				{
					
					m_LevelNo = 0;
					m_mouse.mouseResetPoints();
					m_levelFileName = ResourceManager::GetResourceManagerInstance().getLevel(m_LevelNo);
					setNewGame();
					restart();
					m_levelFile = OpenLevelFile(m_levelFileName);
					break;
					
				}
				if (m_infoBar.getCheeseAmount() == 0)
				{
					nextLevel();
					ResourceManager::GetResourceManagerInstance().playSound((int)SUCCESS_);
					break;
				}
				if (m_mouse.getLife() == 0) 
				{
					restart();
					menu.setRunEndScreen();
					menu.runEndScreen("You Lost :(");
				}
				
				gameDraw(window);

			}
		}
		restart();
		menu.setRunEndScreen();
		menu.runEndScreen("winnerr :)");
}
//---------------------------------------------------------
std::ifstream GameController::OpenLevelFile(std::string name)
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
//------------------------------------------------------------