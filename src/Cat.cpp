#include "Cat.h"
#include "GameController.h"


Cat::Cat(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size, GameController* game)
	:Entitys(position, texture, size), m_LastPostion{ position }, m_startPostion{ position }, m_blocked{ false }
{
	m_game = game;
	sf::RectangleShape Shape;
	Shape.setPosition(position);
	Shape.setTexture(texture);
	Shape.setSize(size);
	setShape(Shape);
	m_turnTimer.restart();
}
//---------------------------------------------------------
 void Cat::move(sf::Time deltaTime, Mouse mouse)
{
	auto catShape = useShape();
	m_mousePosision = mouse.useShape().getPosition();
	int left, right, up, down;
	auto currentPosition=m_LastPostion;
	auto pixelsPerSeconds = useShape().getSize();
	sf::Vector2f direction;

	if (m_turnTimer.getElapsedTime().asSeconds() >= 0.2f)
	{
		if (!m_blocked)
		{
			left = distance({ m_mousePosision.x - 1.f, m_mousePosision.y }, m_LastPostion);
			right = distance({ m_mousePosision.x + 1.f, m_mousePosision.y }, m_LastPostion);
			up = distance({ m_mousePosision.x, m_mousePosision.y - 1.f }, m_LastPostion);
			down = distance({ m_mousePosision.x, m_mousePosision.y + 1.f }, m_LastPostion);
			m_direction = priorityDirection(left, right, up, down);
			m_turnTimer.restart();
		}
		else
		{
			setDirection();
			m_turnTimer.restart();
		}
	}
	// Set direction based on the calculated m_direction
	if (m_direction == LEFT)
	{
		catShape.setOrigin(0.f,0.f);
		catShape.setScale(1.f, 1.f);
		setShape(catShape);
	}
	else if (m_direction == RIGHT)
	{
		catShape.setOrigin(catShape.getGlobalBounds().width, 0);
		catShape.setScale(-1.f, 1.f);
		setShape(catShape);
		
	}

	// Update currentPosition based on direction and deltaTime
	currentPosition = { m_direction * pixelsPerSeconds.y * deltaTime.asSeconds()*5.f};

	// Set the new location
	setLocation(m_LastPostion, currentPosition);
	m_LastPostion = useShape().getPosition();
	m_blocked = false;


}
//---------------------------------------------------------
void Cat::handleCollisionGameObjects(GameObject& Object, InfoBar& info)
{
	Object.handleCollisionWithCat(*this, info);
}
//---------------------------------------------------------
void Cat::handleCollisionWithDoor(Door& door, InfoBar& info)
{
	moveBack(door);
	m_blocked = true;//for activate the recalculate
	
}
//---------------------------------------------------------
void Cat::handleCollisionWithWall(Wall& wall)
{
	moveBack(wall);
	m_blocked = true;
}
//---------------------------------------------------------
void Cat::handleCollisionWithMouse(Mouse& Object, InfoBar& info)
{
	m_LastPostion = m_startPostion;
	m_game->returnCatsToStartPosition();
}
//---------------------------------------------------------
//here not like the mouse the calculating is diffrent here the cat always in move so if he 
// colide on wall or dor we want to push him back to the last position
void Cat::moveBack(GameObject& object)
{
	sf::FloatRect cuttingRectangle;
	auto shape = useShape();
	auto shapeObject = object.useShape();
	shape.getGlobalBounds().intersects(shapeObject.getGlobalBounds(), cuttingRectangle);
	
	if (cuttingRectangle.width > shape.getSize().x|| cuttingRectangle.height >1)
	{
		sf::Vector2f currentPosition;

		if (m_direction == LEFT)
		{
			currentPosition.x += cuttingRectangle.width;
		}
		else if (m_direction == RIGHT)
		{
			currentPosition.x -= cuttingRectangle.width;
		}
		else if (m_direction == UP)
		{
			currentPosition.y += cuttingRectangle.height;

		}
		else if (m_direction == DOWN)
		{
			currentPosition.y -= cuttingRectangle.height;
		}

		setLocation(m_LastPostion, currentPosition);
		m_LastPostion = useShape().getPosition();
	}
}
//for the game to know where to replace the cats 
//---------------------------------------------------------
sf::Vector2f Cat::getStartPosition() const
{
	return m_startPostion;
}
//---------------------------------------------------------
int Cat::distance(sf::Vector2f pos1, sf::Vector2f pos2)
{
	return std::sqrt(pow((pos1.x-pos2.x),2)+ pow((pos1.y - pos2.y), 2));
}
//---------------------------------------------------------
//the best way to move there
sf::Vector2f Cat::priorityDirection(int left, int right, int up, int down)
{
	int current = left;
	auto result = LEFT;
	if (right > current)
	{
		current = right;
		result = RIGHT;
	}
	if (up > current)
	{
		current = up;
		result = UP;
	}
	if (down > current)
	{
		current = down;
		result = DOWN;
	}
	return result;
}
//---------------------------------------------------------
//in case cat coliision in wall this is the recalculate
void Cat::setDirection()
{
	int left = 0, right = 0, up = 0, down = 0;
	
	if (m_direction == LEFT)
	{
		right = distance({ m_mousePosision.x +10.f,m_mousePosision.y}, m_LastPostion);
		up = distance({ m_mousePosision.x ,m_mousePosision.y - 10.f }, m_LastPostion);
		down = distance({ m_mousePosision.x,m_mousePosision.y +10.f }, m_LastPostion);
		m_direction = priorityDirection(0,right, up, down);
		return;
	}
	else if (m_direction == RIGHT)
	{
		left = distance({ m_mousePosision.x - 10.f,m_mousePosision.y }, m_LastPostion);
		up = distance({ m_mousePosision.x ,m_mousePosision.y - 10.f }, m_LastPostion);
		down = distance({ m_mousePosision.x,m_mousePosision.y + 10.f }, m_LastPostion);
		m_direction = priorityDirection(left,0, up, down);
		return;

	}
	else if (m_direction == UP)
	{
		left = distance({ m_mousePosision.x - 10.f,m_mousePosision.y }, m_LastPostion);
		right = distance({ m_mousePosision.x + 10.f,m_mousePosision.y }, m_LastPostion);
		down = distance({ m_mousePosision.x,m_mousePosision.y + 10.f }, m_LastPostion);
		m_direction = priorityDirection(left, right, 0, down);
		return;
	}
	else if (m_direction == DOWN)
	{
		left = distance({ m_mousePosision.x - 1.f,m_mousePosision.y }, m_LastPostion);
		right = distance({ m_mousePosision.x + 1.f,m_mousePosision.y }, m_LastPostion);
		up = distance({ m_mousePosision.x ,m_mousePosision.y - 1.f }, m_LastPostion);
		m_direction = priorityDirection(left, right, up, 0);
		return;
	}
}
//---------------------------------------------------------



