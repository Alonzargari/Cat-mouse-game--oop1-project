#pragma once
#include "GameObjects.h"


class InteractableObjects :public GameObject 
{
public:
	InteractableObjects(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size);
	~InteractableObjects() = default;
};