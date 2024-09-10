#include "Present.h"
#include "GameController.h"

Present::Present(sf::Vector2f position, const sf::Texture* texture, sf::Vector2f size,GameController* game)
	:InteractableObjects(position, texture, size)
{
	m_game = game;
}
//---------------------------------------------------------
void Present::freezeCats()
{
	m_game->setFreezeCats();
}
//---------------------------------------------------------
void Present::popCats()
{
	m_game->PopCats();
}

