#pragma once 
#include "InteractableObjects.h"
#include "Mouse.h"
#include "Cat.h"

class Door :public InteractableObjects
{
public:
    Door(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size);
    ~Door() = default;
    virtual void handleCollisionGameObjects(GameObject& Object, InfoBar& info)override;
    virtual void handleCollisionWithKey(Key& Object, InfoBar& info) {}
    virtual void handleCollisionWithCheese(Cheese& Object, InfoBar& info) {}
    virtual void handleCollisionWithDoor(Door& Object,InfoBar& info){}
    virtual void handleCollisionWithWall(Wall& Object){}
    virtual void handleCollisionWithMouse(Mouse& Object, InfoBar& info)override;
    virtual void handleCollisionWithCat(Cat& Object, InfoBar& info)override;
    virtual void handleCollisionWithFreezer(Freezer& Object, InfoBar& info) {}
    virtual void handleCollisionWithCatPop(CatPop& Object, InfoBar& info) {}
    virtual void handleCollisionWithExtraTime(ExtraTime& Object, InfoBar& info) {}
    virtual void handleCollisionWithLifeSaver(LifeSaver& Object, InfoBar& info) {}

private:

};