#pragma once
#include <SFML/Graphics.hpp>
#include "InteractableObjects.h"
#include "Macros.h"
#include "TimeManager.h"
#include "ResourceManager.h"
class GameController;
class Present:public InteractableObjects
{
public:
	Present(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size,GameController* game);
	~Present() = default;
	void freezeCats();
	void popCats();
	

private:
	GameController* m_game;
};