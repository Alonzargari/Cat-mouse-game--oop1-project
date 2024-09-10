#pragma once 
#include "InteractableObjects.h"
#include "Mouse.h"
#include "Cat.h"

class Wall :public InteractableObjects
{
public:
	Wall(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size);
	~Wall() = default;
	virtual void handleCollisionGameObjects(GameObject& Object, InfoBar& info)override;
	virtual void handleCollisionWithWall(Wall& Object){}
	virtual void handleCollisionWithMouse(Mouse& mouse, InfoBar& info)override;
	virtual void handleCollisionWithDoor(Door& Object,InfoBar& info) {}
	virtual void handleCollisionWithCheese(Cheese& cheese, InfoBar& info){}
	virtual void handleCollisionWithKey(Key& Object, InfoBar& info) {}
	virtual void handleCollisionWithCat(Cat& cat, InfoBar& info)override;
	virtual void handleCollisionWithFreezer(Freezer& Object, InfoBar& info) {}
	virtual void handleCollisionWithCatPop(CatPop& Object, InfoBar& info) {}
	virtual void handleCollisionWithExtraTime(ExtraTime& Object, InfoBar& info) {}
	virtual void handleCollisionWithLifeSaver(LifeSaver& Object, InfoBar& info) {}


private:

};