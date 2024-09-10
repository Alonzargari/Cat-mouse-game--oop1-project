
#include "Level.h"
#include "GameController.h"

Level::Level()
	:m_mouse({0,0},NULL,{0,0}), m_shapeSize{0,0}, m_levelSize{0,0},m_cheeseCount{0}
{	
}
//---------------------------------------------------------
void Level::readLevel(std::ifstream& file, GameController& game,InfoBar& info)
{
	char c;
	std::string line;
	int y = 0,levelLength,levelHeight,time;
	std::getline(file, line);
	auto iss = std::istringstream(line);
	iss >>time >> levelHeight >> levelLength;
	TimeManager::GetTimeManagerInstance().setLevelTime(time);
	m_levelSize.x = levelLength;
	m_levelSize.y = levelHeight;
	createBase();
	sf::Vector2f position(m_base.getPosition().x,m_base.getPosition().y);
	while (file >> std::noskipws >>c&& y<m_levelSize.y)
	{
		int x = 0;
		while (c != '\n'&& x<m_levelSize.x) 
		{
		
			position.x = m_base.getPosition().x + m_shapeSize.x * x;
			position.y = m_base.getPosition().y + m_shapeSize.y * y;
			handelCurrentChar(c, position,m_shapeSize,game,info);
			
			file >> std::noskipws >> c;
			x++;
		}
		y++;
	}
}
//---------------------------------------------------------
void Level::createBase()
{
	while (m_shapeSize.x * m_levelSize.x <=BOARD_LENGTH && m_shapeSize.y * m_levelSize.y <=BOARD_HEIGHT)
	{
		m_shapeSize.x++;
		m_shapeSize.y++;
	}
	auto size = sf::Vector2f(m_shapeSize.x * m_levelSize.x, m_shapeSize.y * m_levelSize.y);
	auto position = sf::Vector2f(50,50);
	m_base = createShape(size, position);
}
//----------------------------------------------------------
sf::RectangleShape Level::createShape(sf::Vector2f size, sf::Vector2f position)
{
	sf::RectangleShape shape;
	size.x;
	shape.setSize(size);
	shape.setPosition(position);
	shape.setOutlineThickness(5);
	shape.setOutlineColor(sf::Color::Black);
	shape.setFillColor(sf::Color{ 0,0,0,127 });
	return shape;
}
//---------------------------------------------------------
sf::Vector2f Level::getShapeSize() const
{
	return m_shapeSize;
}
//---------------------------------------------------------
void Level::Draw(sf::RenderWindow& window)
{
	window.draw(m_base);
	for (int i = 0;i < m_interactObjects.size();i++) 
	{
		m_interactObjects[i]->draw(window);
	}
	for (int i = 0;i < m_presents.size();i++) 
	{
		m_presents[i]->draw(window);
	}
	
}
//---------------------------------------------------------

//---------------------------------------------------------
void Level::colideWithGameObjects(GameObject& Object,InfoBar& info)
{
	for (int i = 0;i < m_interactObjects.size();i++) 
	{
		if (m_interactObjects[i]->checkCollision(Object))
		{
			m_interactObjects[i]->handleCollisionGameObjects(Object,info);
		}
	}
	std::erase_if(m_interactObjects, [](const auto& interactObject) { return interactObject->toErase();});
	for (int i = 0;i < m_presents.size();i++)
	{
		if (m_presents[i]->checkCollision(Object))
		{
			m_presents[i]->handleCollisionGameObjects(Object, info);
		}
	}
	std::erase_if(m_presents, [](const auto& object) { return object->toErase();});

}
//---------------------------------------------------------
int Level::getCheeseAmount() const
{
	return m_cheeseCount;
}
//---------------------------------------------------------
int Level::getLevelTime()
{
	return m_levelTime;
}
//---------------------------------------------------------
void Level::ClearLevel()
{
	m_shapeSize = { 0,0 };
	m_cheeseCount = 0;
	m_interactObjects.clear();
	m_presents.clear();
	m_presents.shrink_to_fit();
	m_interactObjects.shrink_to_fit();
}
//---------------------------------------------------------
void Level::handelCurrentChar(char c,sf::Vector2f position ,
				sf::Vector2f tileSize, GameController& game,InfoBar& infoBar)
{
	sf::Texture* textur;
	switch (c)
	{
	case MOUSE:
		textur = ResourceManager::GetResourceManagerInstance().getTexture((int)MOUSE_);
		game.setMouse(position, textur,{ tileSize.x-4,tileSize.y-4});
		break;
	case CAT:
		textur = ResourceManager::GetResourceManagerInstance().getTexture((int)CAT_);
		game.setCats(position, textur, { tileSize.x-4,tileSize.y-4 });
		break;
	case CHEESSE:
		m_cheeseCount++;
		textur = ResourceManager::GetResourceManagerInstance().getTexture((int)CHEESSE_);
		m_interactObjects.emplace_back(std::make_unique<Cheese>(position, textur,tileSize));
		break;
	case DOOR:
		textur = ResourceManager::GetResourceManagerInstance().getTexture((int)DOOR_);
		m_interactObjects.emplace_back(std::make_unique<Door>(position, textur, tileSize));
		break;
	case KEY:
		textur = ResourceManager::GetResourceManagerInstance().getTexture((int)KEY_);
		m_interactObjects.emplace_back(std::make_unique<Key>(position, textur, tileSize));
		break;
	case WALL:
		textur = ResourceManager::GetResourceManagerInstance().getTexture((int)WALL_);
		m_interactObjects.emplace_back(std::make_unique<Wall>(position, textur, tileSize));
		break;
	case CAT_POP:
		textur = ResourceManager::GetResourceManagerInstance().getTexture((int)CAT_POP_);
		m_presents.emplace_back(std::make_unique<CatPop>(position, textur, tileSize, &game));
		break;
	case FREEZE_CAT:
		textur = ResourceManager::GetResourceManagerInstance().getTexture((int)FREEZE_CAT_);
		m_presents.emplace_back(std::make_unique<Freezer>(position, textur, tileSize, &game));
		break;
	case EXTRA_TIME:
		textur = ResourceManager::GetResourceManagerInstance().getTexture((int)EXTRA_TIME_);
		m_presents.emplace_back(std::make_unique<ExtraTime>(position, textur, tileSize, &game));
		break;
	case LIFE_SAVER:
		textur = ResourceManager::GetResourceManagerInstance().getTexture((int)LIFE_SAVER_);
		m_presents.emplace_back(std::make_unique<LifeSaver>(position, textur, tileSize, &game));
		break;

	default:
		break;
	}
}
//-----------------------------------------------------------

