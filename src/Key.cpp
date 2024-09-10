#include "Key.h"

Key::Key(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size)
	:InteractableObjects(position, texture, size)
{

}
//---------------------------------------------------------
void Key::handleCollisionGameObjects(GameObject& Object, InfoBar& info)
{
	Object.handleCollisionWithKey(*this, info);
}
//---------------------------------------------------------
void Key::handleCollisionWithMouse(Mouse& mouse, InfoBar& info)
{
	mouse.handleCollisionWithKey(*this, info);
}
