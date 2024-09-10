#include "Door.h"

Door::Door(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size)
	:InteractableObjects(position, texture, size)
{

}
//---------------------------------------------------------
void Door::handleCollisionGameObjects(GameObject& Object, InfoBar& info)
{
	Object.handleCollisionWithDoor(*this,info);
}
//---------------------------------------------------------
void Door::handleCollisionWithMouse(Mouse& mouse, InfoBar& info)
{
	setEraseCondition();
	mouse.handleCollisionWithDoor(*this,info);
}
//---------------------------------------------------------
void Door::handleCollisionWithCat(Cat& cat, InfoBar& info)
{
	cat.handleCollisionWithDoor(*this, info);

}
