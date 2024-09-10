#include "InfoBar.h"

InfoBar::InfoBar()
	:m_cheeseCounter{0}
{
	setBarBase();
	
	m_font = ResourceManager::GetResourceManagerInstance().getFont(2);
	m_limitTime = 0;
}
//---------------------------------------------------------
void InfoBar::setTimeInfo()
{
	m_gameTime.setFont(*m_font);
	m_gameTime.setString("Time Left: " + std::to_string (m_limitTime));
	m_gameTime.setFillColor(sf::Color::Yellow);
	m_gameTime.setOutlineColor(sf::Color::Black);
	m_gameTime.setOutlineThickness(3);
	m_gameTime.setOrigin({ 32.f / 2,32.f / 2 });
	m_gameTime.setPosition({1050,350});
}
//---------------------------------------------------------
void InfoBar::setLifeInfo(Mouse mouse)
{
	sf::Texture* texture;
	texture = ResourceManager::GetResourceManagerInstance().getTexture((int)LIFE_SAVER_);
	int life = mouse.getLife();
	sf::RectangleShape shape;
	shape.setSize({ 32,32 });
	shape.setOrigin(sf::Vector2f{32/2,32/2});
	shape.setTexture(texture);
	for (int i=0;i<life;i++)
	{
		shape.setPosition({ 1050.f + i * 32.f,500.f });
		m_lifeVector.push_back(shape);
	}
}
//---------------------------------------------------------
void InfoBar::setCheeseAmount(int cheeseAmount)
{
	sf::Texture* texture;
	texture = ResourceManager::GetResourceManagerInstance().getTexture((int)CHEESSE_);

	m_cheeseCounter =cheeseAmount;
	m_cheese.setSize({ 32.f,32.f });
	m_cheese.setOrigin({ 32.f / 2,32.f / 2 });
	m_cheese.setPosition({ 1050.f,650.f });
	m_cheese.setTexture(texture);

	m_cheeseAmount.setFont(*m_font);
	m_cheeseAmount.setOrigin({ 32.f / 2,32.f / 2 });
	m_cheeseAmount.setString("Cheese Amount: " + std::to_string(m_cheeseCounter));
	m_cheeseAmount.setPosition({ 1100.f, 650.f });
	m_cheeseAmount.setFillColor(sf::Color::Yellow);
	m_cheeseAmount.setOutlineColor(sf::Color::Black);
	m_cheeseAmount.setOutlineThickness(3);
}
//---------------------------------------------------------
int InfoBar::getCheeseAmount()
{
	return m_cheeseCounter;
}
//---------------------------------------------------------
void InfoBar::setKeysAmount()
{
	sf::Texture* texture;
	texture = ResourceManager::GetResourceManagerInstance().getTexture((int)KEY_);
	m_key.setSize({ 32.f,32.f });
	m_key.setOrigin({ 32.f / 2,32.f / 2 });
	m_key.setPosition({ 1050.f,800.f });
	m_key.setTexture(texture);

	m_keyAmount.setFont(*m_font);
	m_keyAmount.setOrigin({ 32.f / 2,32.f / 2 });
	m_keyAmount.setString("key Amount: " + std::to_string(0));
	m_keyAmount.setPosition({ 1100.f, 800.f });
	m_keyAmount.setFillColor(sf::Color::Yellow);
	m_keyAmount.setOutlineColor(sf::Color::Black);
	m_keyAmount.setOutlineThickness(3);

}
//---------------------------------------------------------
void InfoBar::updateLifeInfo(Mouse mouse)
{
	sf::Texture* texture;
	texture = ResourceManager::GetResourceManagerInstance().getTexture((int)LIFE_SAVER_);
	int life = mouse.getLife();
	sf::RectangleShape shape;
	shape.setSize({ 32,32 });
	shape.setOrigin(sf::Vector2f{ 32 / 2,32 / 2 });
	shape.setTexture(texture);
	if(mouse.getLife()<m_lifeVector.size())
	{
		if (m_lifeVector.size() > 0)
		{
			m_lifeVector.clear();
		}
		
		for (int i = 0;i < life;i++)
		{
			shape.setPosition({ 1050.f + i * 32.f,500.f });
			m_lifeVector.push_back(shape);
		}
	}

	if(mouse.getLife() > m_lifeVector.size())
	{
		if (m_lifeVector.size() > 0)
		{
			m_lifeVector.clear();
		}
		for (int i = 0;i < life;i++)
		{
			shape.setPosition({ 1050.f + i * 32.f,500.f });
			m_lifeVector.push_back(shape);
		}
	}
	

}
//---------------------------------------------------------
void InfoBar::updateTimeInfo()
{
	auto time = 0;
	auto elapsed =TimeManager::GetTimeManagerInstance().getInfoClock().getElapsedTime().asSeconds();
	auto leveltime = TimeManager::GetTimeManagerInstance().getLevelTime()*60;
	time -= elapsed-leveltime;
	auto adder = TimeManager::GetTimeManagerInstance().getAddForTimer();
	TimeManager::GetTimeManagerInstance().setMinuts(time+adder);
	TimeManager::GetTimeManagerInstance().setSecondes(time+adder);
	auto seconds = TimeManager::GetTimeManagerInstance().getTimeAsSecond();
	auto minutes = TimeManager::GetTimeManagerInstance().getTimeAsMinute();
	m_gameTime.setString("Time Left: 0" + std::to_string(minutes) + ":" + std::to_string(seconds));
	if (seconds < 10) 
	{
		m_gameTime.setString("Time Left: 0" + std::to_string(minutes) + ":" +"0"+ std::to_string(seconds));

	}
	if (seconds < 20&&minutes==0)
	{
		m_gameTime.setFillColor(sf::Color::Red);
	}
}
//---------------------------------------------------------
void InfoBar::updateCheeseAmount()
{
	m_cheeseCounter--;
	m_cheeseAmount.setString("Cheese Amount: " + std::to_string(m_cheeseCounter));
}
//---------------------------------------------------------
void InfoBar::updatePoints(int points)
{
	m_points.setString("Total Point: " + std::to_string(points));
}
//---------------------------------------------------------
void InfoBar::SetLevelNo(int levelNo)
{
	m_levelNo.setFont(*m_font);
	m_levelNo.setOrigin({ 32.f / 2,32.f / 2 });
	m_levelNo.setString("Level Number: " + std::to_string(levelNo));
	m_levelNo.setPosition({ 1050.f, 50.f });
	m_levelNo.setFillColor(sf::Color::Yellow);
	m_levelNo.setOutlineColor(sf::Color::Black);
	m_levelNo.setOutlineThickness(3);
}
//---------------------------------------------------------
void InfoBar::updateLevelNo(int levelNo)
{
	m_levelNo.setString("Level Number: " + std::to_string(levelNo));
}
//---------------------------------------------------------
void InfoBar::setPoints()
{
	m_points.setFont(*m_font);
	m_points.setOrigin({ 32.f / 2,32.f / 2 });
	m_points.setString("Total Point: " + std::to_string(0));
	m_points.setPosition({ 1050.f, 200.f });
	m_points.setFillColor(sf::Color::Yellow);
	m_points.setOutlineColor(sf::Color::Black);
	m_points.setOutlineThickness(3);
}
//---------------------------------------------------------
void InfoBar::updateKeys(int keys)
{
	m_keyAmount.setString("key Amount: " + std::to_string(keys));
}
//---------------------------------------------------------
void InfoBar::drawInfoBar(sf::RenderWindow& window)
{
	window.draw(m_barBase);
	window.draw(m_gameTime);
	for (int i = 0;i < m_lifeVector.size();i++)
	{
		window.draw(m_lifeVector[i]);
	}
	window.draw(m_cheese);
	window.draw(m_cheeseAmount);
	window.draw(m_key);
	window.draw(m_keyAmount);
	window.draw(m_points);
	window.draw(m_levelNo);
}
//---------------------------------------------------------
void InfoBar::restartClock()
{
	m_Timer.restart();
}
//---------------------------------------------------------
void InfoBar::setBarBase()
{
	m_barBase.setFillColor(sf::Color{136,69,19,200});
	m_barBase.setPosition({ 1000,0});
	m_barBase.setSize({500,900});
	m_barBase.setOutlineColor(sf::Color::Black);
	m_barBase.setOutlineThickness(3);
}
//---------------------------------------------------------
