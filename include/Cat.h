#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Entitys.h"
#include "Mouse.h"
#include "Door.h"
#include "Wall.h"
#include <cmath>
#include <iostream>

class GameController;

class Cat:public Entitys
{
public:
	Cat(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size,GameController* game);
	~Cat() = default;
	void move(sf::Time deltaTime,Mouse mouse);

	virtual void handleCollisionGameObjects(GameObject& Object, InfoBar& info)override;
	virtual void handleCollisionWithKey(Key& Object, InfoBar& info) {}
	virtual void handleCollisionWithCheese(Cheese& Object, InfoBar& info){}
	virtual void handleCollisionWithDoor(Door& Object, InfoBar& info)override;
	virtual void handleCollisionWithWall(Wall& Object) override;
	virtual void handleCollisionWithMouse(Mouse& Object, InfoBar& info) override;
	virtual void handleCollisionWithCat(Cat& Object, InfoBar& info){}
	virtual void handleCollisionWithFreezer(Freezer& Object, InfoBar& info) {}
	virtual void handleCollisionWithCatPop(CatPop& Object, InfoBar& info) {}
	virtual void handleCollisionWithExtraTime(ExtraTime& Object, InfoBar& info) {}
	virtual void handleCollisionWithLifeSaver(LifeSaver& Object, InfoBar& info) {}
	virtual void moveBack(GameObject& object)override;
	sf::Vector2f getStartPosition()const;

private:
	GameController* m_game;
	int distance(sf::Vector2f, sf::Vector2f);
	sf::Vector2f priorityDirection(int, int, int, int);
	void setDirection();
	sf::Vector2f m_startPostion;
	sf::Vector2f m_LastPostion;
	sf::Vector2f m_direction;
	sf::Vector2f m_lasdDirection;
	sf::Vector2f m_mousePosision;
	sf::Clock m_turnTimer;
	bool m_blocked;
};