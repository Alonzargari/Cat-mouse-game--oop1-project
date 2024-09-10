#include "LifeSaver.h"
#include "Mouse.h"
LifeSaver::LifeSaver(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size, GameController* game)
	:Present(position, texture, size, game)
{

}
//---------------------------------------------------------
void LifeSaver::handleCollisionGameObjects(GameObject& Object, InfoBar& info)
{
	Object.handleCollisionGameObjects(*this, info);
}
//---------------------------------------------------------
void LifeSaver::handleCollisionWithMouse(Mouse& Object, InfoBar& info)
{
	Object.handleCollisionWithLifeSaver(*this, info);
}
