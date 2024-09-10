#pragma once 
#include "CatPop.h"

CatPop::CatPop(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size, GameController* game)
	:Present(position, texture, size, game)
{
}
//---------------------------------------------------------
void CatPop::handleCollisionGameObjects(GameObject& Object, InfoBar& info)
{
	Object.handleCollisionGameObjects(*this, info);
}
//---------------------------------------------------------
void CatPop::handleCollisionWithMouse(Mouse& Object, InfoBar& info)
{
	ResourceManager::GetResourceManagerInstance().playSound((int)CATBOMB_);
	setEraseCondition();
	popCats();
}
