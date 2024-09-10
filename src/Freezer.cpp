#include "Freezer.h"

Freezer::Freezer(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size, GameController* game)
	:Present(position, texture, size, game)
{
}
//---------------------------------------------------------
void Freezer::handleCollisionGameObjects(GameObject& Object, InfoBar& info)
{
	Object.handleCollisionGameObjects(*this, info);
}
//---------------------------------------------------------
void Freezer::handleCollisionWithMouse(Mouse& Object, InfoBar& info)
{
	ResourceManager::GetResourceManagerInstance().playSound((int)FREEZE_);
	setEraseCondition();
	freezeCats();
}
