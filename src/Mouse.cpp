#include "Mouse.h"
#include "InfoBar.h"

Mouse::Mouse(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size)
	:Entitys(position, texture, size), m_life{ 3 }, m_direction {RIGHT}, 
	m_lastPosition{ 0, 0 },m_points{0},m_keys{0},m_startPosition{position}
{
	
}
//----------------------------------------------------------
void Mouse::handleCollisionGameObjects(GameObject& Object,InfoBar& info)
{
	Object.handleCollisionWithMouse(*this,info);
}
//---------------------------------------------------------
void Mouse::handleCollisionWithKey(Key& Object, InfoBar& info)
{
	m_keys++;
	info.updateKeys(m_keys);
	Object.setEraseCondition();
	ResourceManager::GetResourceManagerInstance().playSound((int)KEYSOUND_);
}
//---------------------------------------------------------
void Mouse::handleCollisionWithWall(Wall& wall)
{
	moveBack(wall);
}
//---------------------------------------------------------
void Mouse::handleCollisionWithCheese(Cheese& cheese, InfoBar& info)
{
	m_points += 10;
	info.updateCheeseAmount();
	info.updatePoints(m_points);
	cheese.setEraseCondition();
	ResourceManager::GetResourceManagerInstance().playSound((int)EATING_);
}
//---------------------------------------------------------
void Mouse::handleCollisionWithDoor(Door& door,InfoBar& info)
{
	if (m_keys > 0) 
	{
		ResourceManager::GetResourceManagerInstance().playSound((int)DOOR_SOUND_);

		door.setEraseCondition();
		m_keys--;
		info.updateKeys(m_keys);
	}
	else 
	{
		moveBack(door);
	}
}
//---------------------------------------------------------
void Mouse::handleCollisionWithCat(Cat& Object, InfoBar& info)
{
	m_life--;
	setLocation(m_startPosition,{ 0,0 });
	info.updateLifeInfo(*this);
	ResourceManager::GetResourceManagerInstance().playSound((int)ANGRY_);
}
//---------------------------------------------------------
void Mouse::handleCollisionWithFreezer(Freezer& Object, InfoBar& info)
{
	Object.setEraseCondition();
	Object.handleCollisionWithMouse(*this,info);

}
//---------------------------------------------------------
void Mouse::handleCollisionWithCatPop(CatPop& Object, InfoBar& info)
{
	Object.setEraseCondition();
	Object.handleCollisionWithMouse(*this, info);
}
//---------------------------------------------------------
void Mouse::handleCollisionWithExtraTime(ExtraTime& Object, InfoBar& info)
{
	Object.setEraseCondition();
	Object.handleCollisionWithMouse(*this, info);
}
//---------------------------------------------------------
void Mouse::handleCollisionWithLifeSaver(LifeSaver& Object, InfoBar& info)
{
	if (m_life < 3) 
	{
		ResourceManager::GetResourceManagerInstance().playSound((int)EXTRALIFE_);
		m_life++;
		info.updateLifeInfo(*this);
		Object.setEraseCondition();
	}
}
//---------------------------------------------------------
int Mouse::getLife() const
{
	return m_life;
}
//---------------------------------------------------------
void Mouse::move(sf::Time deltaTime)
{
	auto mouseShape = useShape();
	m_lastPosition = mouseShape.getPosition();
	auto currentPosition = m_lastPosition;
	//auto pixelsPerSeconds = mouseShape.getSize();
	sf::Vector2f direction;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
	{
		mouseShape.setOrigin(mouseShape.getGlobalBounds().width,0);
		mouseShape.setScale(-1.f, 1.f);
		setShape(mouseShape);
		
		direction = { -5,0 };
		currentPosition = { direction* /** pixelsPerSeconds.x **/ deltaTime.asSeconds() };

		setLocation(m_lastPosition, currentPosition);
		m_lastPosition = mouseShape.getPosition();
		m_direction = LEFT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mouseShape.setOrigin(0.f, 0.f);
		mouseShape.setScale(1.f, 1.f);
		setShape(mouseShape);

		direction = { 5,0 };
		currentPosition = { direction* /** pixelsPerSeconds.x **/ deltaTime.asSeconds() };
		
		setLocation(m_lastPosition, currentPosition);
		m_lastPosition = mouseShape.getPosition();
		m_direction = RIGHT;
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction = { 0,-5 };
		currentPosition = { direction */** pixelsPerSeconds.x*/ deltaTime.asSeconds() };
		setLocation(m_lastPosition, currentPosition);
		m_lastPosition = mouseShape.getPosition();
		m_direction = UP;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction = { 0,5 };
		currentPosition = { direction */** pixelsPerSeconds.x **/ deltaTime.asSeconds() };
		setLocation(m_lastPosition, currentPosition);
		m_lastPosition = mouseShape.getPosition();
		m_direction = DOWN;
	}
}
//---------------------------------------------------------
void Mouse::moveBack(GameObject& object)
{
	sf::FloatRect cuttingRectangle;
	auto shape = useShape();
	auto shapeObject = object.useShape();
	shape.getGlobalBounds().intersects(shapeObject.getGlobalBounds(), cuttingRectangle);
	if (m_direction == LEFT || m_direction == RIGHT) 
	{
		if (cuttingRectangle.width > shape.getSize().x || cuttingRectangle.height > 10)
		{
			setLocation(m_lastPosition, { 0,0 });
		}
	}
	if (m_direction == UP || m_direction == DOWN) 
	{
		if (cuttingRectangle.width >shape.getSize().x/2.5 || cuttingRectangle.height > 30)
		{
			setLocation(m_lastPosition, { 0,0 });
		}

	}
	
}
//---------------------------------------------------------
//when scanning the level we get the start position 
void Mouse::setStartPosition(sf::Vector2f position)
{
	m_startPosition = position;
}
//---------------------------------------------------------
//when restart a game or reach new level 
void Mouse::mouseRestart()
{
	m_life = 3;
	m_keys = 0;
}
//---------------------------------------------------------
void Mouse::mouseResetPoints()
{
	m_points = 0;
}
//---------------------------------------------------------

