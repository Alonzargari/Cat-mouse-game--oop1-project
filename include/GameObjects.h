#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>

class Key;
class Door;
class Cheese;
class Wall;
class Mouse;
class Entity;
class IteractableObjects;
class InfoBar;
class Cat;
class Freezer;
class ExtraTime;
class LifeSaver;
class CatPop;
class GameObject 

{
public:
	GameObject(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size);
	~GameObject()=default;
	void draw(sf::RenderWindow& window);
	void setShape(sf::RectangleShape shape);
	sf::RectangleShape useShape()const;
	bool checkCollision(GameObject& other) const;
	void setEraseCondition();
	bool toErase();

    // Using double-dispatch for handling collisions
    virtual void handleCollisionGameObjects(GameObject& Object,InfoBar& info) = 0;
    virtual void handleCollisionWithKey(Key& Object,InfoBar& info) = 0;
    virtual void handleCollisionWithCheese(Cheese& Object,InfoBar& info) = 0;
    virtual void handleCollisionWithDoor(Door& Object,InfoBar& info) = 0;
	virtual void handleCollisionWithWall(Wall& Object) = 0;
    virtual void handleCollisionWithMouse(Mouse& Object,InfoBar& info) = 0;
	virtual void handleCollisionWithCat(Cat& Object, InfoBar& info)=0;
	virtual void handleCollisionWithFreezer(Freezer& Object, InfoBar& info)=0;
	virtual void handleCollisionWithCatPop(CatPop& Object, InfoBar& info)=0;
	virtual void handleCollisionWithExtraTime(ExtraTime& Object, InfoBar& info)=0;
	virtual void handleCollisionWithLifeSaver(LifeSaver& Object, InfoBar& info)=0;
	void setLocation(sf::Vector2f lastposition, sf::Vector2f currentposition);
private:
	sf::RectangleShape m_object;
	bool m_eraseCondition;
};