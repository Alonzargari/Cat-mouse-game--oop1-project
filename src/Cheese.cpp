#include "Cheese.h"

Cheese::Cheese(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size)
	:InteractableObjects(position,texture,size)
{

}
//---------------------------------------------------------
void Cheese::handleCollisionGameObjects(GameObject& Object,InfoBar& info)
{
	Object.handleCollisionWithCheese(*this,info);
}
//---------------------------------------------------------
void Cheese::handleCollisionWithMouse(Mouse& mouse,InfoBar& info)
{
	setEraseCondition();
	mouse.handleCollisionWithCheese(*this,info);
}

