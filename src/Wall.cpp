#include "Wall.h"

Wall::Wall(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size)
	:InteractableObjects(position, texture, size)
{

}
//---------------------------------------------------------
void Wall::handleCollisionGameObjects(GameObject& Object,InfoBar& info)
{
	Object.handleCollisionWithWall(*this);
}
//---------------------------------------------------------
void Wall::handleCollisionWithMouse(Mouse& mouse, InfoBar& info)
{
	mouse.handleCollisionWithWall(*this);
}
//---------------------------------------------------------
void Wall::handleCollisionWithCat(Cat& cat, InfoBar& info)
{
	cat.handleCollisionWithWall(*this);
}
//---------------------------------------------------------

