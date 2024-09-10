#include "TimeManager.h"

//---------------------------------------------------------
TimeManager& TimeManager::GetTimeManagerInstance()
{
	static TimeManager timeManager;
	return timeManager;
}
TimeManager::TimeManager()
	:m_catFreezeLimit(10.f),m_timeToAdd{0},m_LevelTime{0},m_levelTimeAsMinute{0},m_levelTimeAsSecond{0}
{
}
//---------------------------------------------------------
//when scanning the board this is the time we get
void TimeManager::setLevelTime(int time)
{
	m_LevelTime = time;
}
//---------------------------------------------------------
void TimeManager::setMinuts(int time)
{
	m_levelTimeAsMinute = time/60;
}
//---------------------------------------------------------
void TimeManager::setSecondes(int time)
{
	m_levelTimeAsSecond = time%60;
}
//---------------------------------------------------------

int TimeManager::getLevelTime()
{
	return m_LevelTime;
}
//---------------------------------------------------------
//for display time seconds
int TimeManager::getTimeAsSecond()
{
	return m_levelTimeAsSecond;
}
//---------------------------------------------------------
//for display time minuts
int TimeManager::getTimeAsMinute()
{
	return m_levelTimeAsMinute;
}
//---------------------------------------------------------
//when mouse took extra time
void TimeManager::SetAddForTimer(int time)
{
	m_timeToAdd += time;
}
//--------------------------------------------------------

int TimeManager::getAddForTimer()
{
	return m_timeToAdd;
}
//---------------------------------------------------------
void TimeManager::DecreaseFreezeTime()
{
	m_elapsedTime = m_timeFreeze.restart();
	//we dont want negative value so if we passed this 
	//limit we update the m_elapsed to be 1
	if (m_elapsedTime.asSeconds() > 1) {
		m_elapsedTime = sf::seconds(1); // every time we passed the 1 we set the m_elapsed to be one 
	}
	m_catFreezeLimit -= m_elapsedTime.asSeconds();
}
//---------------------------------------------------------

//---------------------------------------------------------
bool TimeManager::freezeIsOver()
{
	if (m_catFreezeLimit <=0.1) 
	{
		m_catFreezeLimit = 10.f;
		m_timeFreeze.restart();
		return true;
	}
	return false;
}
//---------------------------------------------------------
void TimeManager::RestartClocks()
{
	 m_gamecClock.restart();
	 m_infoTimer.restart();
	 m_timeFreeze.restart();
	 m_timeToAdd = 0;
}
//---------------------------------------------------------
sf::Clock TimeManager::getGameClock()
{
	return m_gamecClock;
}
//---------------------------------------------------------
sf::Clock TimeManager::getInfoClock()
{
	return m_infoTimer;
}
//---------------------------------------------------------


