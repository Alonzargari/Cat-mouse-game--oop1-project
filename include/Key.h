#pragma once 
#include "InteractableObjects.h"
#include "Mouse.h"

class Key :public InteractableObjects
{
public:
	Key(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size);
    ~Key() = default;
    virtual void handleCollisionGameObjects(GameObject& Object, InfoBar& info)override;
    virtual void handleCollisionWithKey(Key& Object, InfoBar& info) {}
    virtual void handleCollisionWithCheese(Cheese& Object, InfoBar& info) {}
    virtual void handleCollisionWithDoor(Door& Object,InfoBar& info) {}
    virtual void handleCollisionWithWall(Wall& Object) {}
    virtual void handleCollisionWithMouse(Mouse& Object, InfoBar& info)override;
    virtual void handleCollisionWithCat(Cat& cat, InfoBar& info){}
    virtual void handleCollisionWithFreezer(Freezer& Object, InfoBar& info) {}
    virtual void handleCollisionWithCatPop(CatPop& Object, InfoBar& info) {}
    virtual void handleCollisionWithExtraTime(ExtraTime& Object, InfoBar& info) {}
    virtual void handleCollisionWithLifeSaver(LifeSaver& Object, InfoBar& info) {}

private:

};