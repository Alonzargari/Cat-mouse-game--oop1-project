#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class TimeManager 
{
public:
	~TimeManager() {};
	static TimeManager& GetTimeManagerInstance();
	void setLevelTime(int);
	void setMinuts(int time);
	void setSecondes(int time);
	int getLevelTime();
	int getTimeAsSecond();
	int getTimeAsMinute();
	void SetAddForTimer(int time);
	int getAddForTimer();
	void DecreaseFreezeTime();
	bool freezeIsOver();
	void RestartClocks();
	sf::Clock getGameClock();
	sf::Clock getInfoClock();
	//sf::Clock getLevelTimeAsMinute();
private:
	TimeManager();
	TimeManager(const TimeManager&) = default;
	TimeManager& operator=(const TimeManager&) = default;
	sf::Clock m_timeFreeze;
	sf::Clock m_gamecClock;
	sf::Clock m_infoTimer;
	sf::Time m_elapsedTime;
	int m_LevelTime;
	int m_levelTimeAsMinute;
	int m_levelTimeAsSecond;
	float m_catFreezeLimit;
	int m_timeToAdd;
};