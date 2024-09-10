#include "GameObjects.h"

GameObject::GameObject(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size)
	:m_eraseCondition{false}
{
	
	m_object.setSize(size);
	m_object.setPosition(position);
	m_object.setTexture(texture);
	/*m_object.setOutlineColor(sf::Color::Green);
	m_object.setOutlineThickness(1);*/
}
//---------------------------------------------------------
void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_object);
}
//---------------------------------------------------------
void GameObject::setShape(sf::RectangleShape shape)
{
	m_object = shape;
}
//---------------------------------------------------------
sf::RectangleShape GameObject::useShape() const
{
	return m_object;
}
//---------------------------------------------------------
bool GameObject::checkCollision(GameObject& other) const
{
	return m_object.getGlobalBounds().intersects(other.m_object.getGlobalBounds());
	
}
//---------------------------------------------------------
void GameObject::setEraseCondition()
{
	this->m_eraseCondition = true;
}
//---------------------------------------------------------
bool GameObject::toErase()
{
	if (m_eraseCondition) 
	{
		return true;
	}
	return false;
}
//---------------------------------------------------------

void GameObject::setLocation(sf::Vector2f lastposition, sf::Vector2f currentposition)
{
	m_object.setPosition(lastposition + currentposition);

}
