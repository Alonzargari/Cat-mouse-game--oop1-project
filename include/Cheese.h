#pragma once 
#include <SFML/Graphics.hpp>
#include "InteractableObjects.h"
#include "InfoBar.h"
#include "Mouse.h"

class Cheese:public InteractableObjects
{
public:
	Cheese(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size);
    ~Cheese() = default;
    // Using double-dispatch for handling collisions
    virtual void handleCollisionGameObjects(GameObject& Object,InfoBar& info)override;
    virtual void handleCollisionWithKey(Key& Object,InfoBar& info){}
    virtual void handleCollisionWithCheese(Cheese& Object, InfoBar& info) {}
    virtual void handleCollisionWithDoor(Door& Object,InfoBar& info) {}
    virtual void handleCollisionWithWall(Wall& Objec) {}
    virtual void handleCollisionWithMouse(Mouse& mouse,InfoBar& info) override;
    virtual void handleCollisionWithCat(Cat& cat, InfoBar& info){}
    virtual void handleCollisionWithFreezer(Freezer& Object, InfoBar& info) {}
    virtual void handleCollisionWithCatPop(CatPop& Object, InfoBar& info) {}
    virtual void handleCollisionWithExtraTime(ExtraTime& Object, InfoBar& info) {}
    virtual void handleCollisionWithLifeSaver(LifeSaver& Object, InfoBar& info) {}

private:

};