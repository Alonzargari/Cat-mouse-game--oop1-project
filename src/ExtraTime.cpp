#include "ExtraTime.h"

ExtraTime::ExtraTime(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size, GameController* game)
	:Present(position, texture, size, game)
{
}
//---------------------------------------------------------
void ExtraTime::handleCollisionGameObjects(GameObject& Object, InfoBar& info)
{
	Object.handleCollisionGameObjects(*this, info);
}
//---------------------------------------------------------
void ExtraTime::handleCollisionWithMouse(Mouse& Object, InfoBar& info)
{
	ResourceManager::GetResourceManagerInstance().playSound((int)EXTRATIME_);
	setEraseCondition();
	TimeManager::GetTimeManagerInstance().SetAddForTimer(20);
}
