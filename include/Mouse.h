#pragma once
#include "Macros.h"
#include "Entitys.h"

class Wall;
class InfoBar;
class GameController;
class Mouse :public Entitys
{
public:
	Mouse(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size);
	~Mouse() = default;
	virtual void handleCollisionGameObjects(GameObject& Object, InfoBar& info)override;
	virtual void handleCollisionWithKey(Key& Object, InfoBar& info)override;
	virtual void handleCollisionWithWall(Wall& Object)override;
	virtual void handleCollisionWithMouse(Mouse& Object, InfoBar& info) {}
	virtual void handleCollisionWithCheese(Cheese& Object, InfoBar& info)override;
	virtual void handleCollisionWithDoor(Door& door,InfoBar& info)override;
	virtual void handleCollisionWithCat(Cat& Object, InfoBar& info)override;
	virtual void handleCollisionWithFreezer(Freezer& Object, InfoBar& info) override;
	virtual void handleCollisionWithCatPop(CatPop& Object, InfoBar& info) override;
	virtual void handleCollisionWithExtraTime(ExtraTime& Object, InfoBar& info)override;
	virtual void handleCollisionWithLifeSaver(LifeSaver& Object, InfoBar& info) override;
	virtual void moveBack(GameObject& object)override;
	void setStartPosition(sf::Vector2f);
	void mouseRestart();
	void mouseResetPoints();


	int getLife()const;
	void move(sf::Time deltaTime);
private:
	sf::Vector2f m_lastPosition;
	sf::Vector2f m_direction;
	sf::Vector2f m_startPosition;
	int m_life;
	int m_points;
	int m_keys;
};