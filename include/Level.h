#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include <fstream>
#include <Macros.h>
#include "GameObjects.h"
#include "Entitys.h"
#include "Mouse.h"
#include "Wall.h"
#include "Key.h"
#include "Door.h"
#include "Cheese.h"
#include "CatPop.h"
#include "Freezer.h"
#include "ExtraTime.h"
#include "LifeSaver.h"
#include "Present.h"
#include "InteractableObjects.h"
#include "Macros.h"
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include "TimeManager.h"
#include "ResourceManager.h"

class GameController;
class Cheese;
class Door;
class Key;
class Wall;


class Level
{
public:
	Level();
	~Level() = default;
	void readLevel(std::ifstream& file,GameController& game,InfoBar&);
	void createBase();
	sf::RectangleShape createShape(sf::Vector2f size, sf::Vector2f position);
	sf::Vector2f getShapeSize()const;
	void Draw(sf::RenderWindow& window);
	void colideWithGameObjects(GameObject& Object,InfoBar& info);
	int getCheeseAmount()const;
	int getLevelTime();
	void ClearLevel();
private:
	Mouse m_mouse;
	std::vector<std::unique_ptr<InteractableObjects>> m_interactObjects;
	std::vector<std::unique_ptr<Present>>m_presents;
	sf::Vector2f m_shapeSize;
	sf::Vector2f m_levelSize;
	sf::RectangleShape m_base;
	int m_levelTime;
	int m_cheeseCount;
	void handelCurrentChar(char c, sf::Vector2f position,sf::Vector2f, GameController&,InfoBar&);
};