#pragma once

#include "GameObjects.h"

#include <iostream>
#include <string>


class Entitys :public GameObject
{
public:
	Entitys(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size);
	~Entitys() = default;
	virtual void moveBack(GameObject& object)=0;
private:

};