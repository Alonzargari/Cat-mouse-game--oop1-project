#pragma once
#include <string>
#include <SFML/Graphics.hpp>

const int WINDOW_LENGTH = 1600;
const int WINDOW_HEIGHT = 900;
const int BOARD_LENGTH =900;
const int BOARD_HEIGHT =900;
const int BOARD_CENTER_X = 1000 / 2;
const int BOARD_CENTER_Y = 700 / 2;
const int INFO_BAR_POS_X = 1200;
const int INFO_BAR_POS_Y = 700;

const sf::Vector2f RIGHT = { 1,0 };
const sf::Vector2f LEFT = { -1,0 };
const sf::Vector2f UP = { 0,-1 };
const sf::Vector2f DOWN = { 0,1 };
const sf::Vector2f NONE = { 0,0 };
const sf::Vector2f PIXELS = { 32,32 };

const char MOUSE = '%';
const char CAT = '^';
const char CHEESSE = '*';
const char WALL = '#';
const char DOOR = 'D';
const char KEY = 'F';
const char CAT_POP = '$';
const char LIFE_SAVER = '+';
const char EXTRA_TIME = '@';
const char FREEZE_CAT = '&';
const char PATH = ' ';

enum Textures_t
{
	MOUSE_,CAT_,CHEESSE_,WALL_,DOOR_,KEY_, CAT_POP_,LIFE_SAVER_,EXTRA_TIME_,
	FREEZE_CAT_,MENU_BG_,BUTTON_,GAME_BG,RESTART_,HOME_,HELP_SCREEN_
};
enum Sounds_t 
{ 
	BGMUSIC_, ANGRY_, CATBOMB_, EATING_, EXTRALIFE_, EXTRATIME_, 
	FREEZE_, GAMEOVER_, SUCCESS_, TIMELEFT_,KEYSOUND_,DOOR_SOUND_
};