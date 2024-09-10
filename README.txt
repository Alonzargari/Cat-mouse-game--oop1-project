OOP PROJECT :README FILE

NAME: ALON ZARGARI 

GENERAL EXPLANATION OF THE EXERCISE:
TITLE :MOUSE AND CATS 
"Mouse and Cats" is a  game developed using the Multimedia Library (SFML).
 Players control a mouse navigating a maze filled with cats, cheese, and various power-ups. The objective is to collect cheese while 
avoiding cats. Each cheese collected earns the player 10 points.
The game features power-ups like Cat Bombs (removes a cat), Life Savers (extra life), Extra Time (more time), 
and Freezers (temporarily freezes cats). The mouse can also collect gifts (removes a cat), keys (opens doors), and other items.
Multiple levels with increasing difficulty are available. The game ends if the mouse is caught three times or if all cheese is collected.

THE FILES WE MAKE:
GameController.cpp,GameController.h-this files manage the game, movments and moving to other levels

GameObject.h,GameObject.cpp- this files is the These files are the parent class of all the objects in the game, 
and all the objects inherit from it. This class is a pure abstract class.

InteractableObject.h,InteractableObject.cpp- This class holds all the objects that interact with the players in the game

Entity.h,Entity.cpp-This class is the parent class for the player entities in the game, from which behaviors are inherited

Presents.h, Present.Cpp-This class is the parent class for all the gifts in the game, which inherit from this class. Additionally
this class inherits from InteractableObject.

ResourceManager.h,ResourceManager.cpp- This class is responsible for all the game's assets (sounds, fonts, textures, and more)

TimeManager.h,TimeManager.cpp- This class is responsible for managing time in the game.

Level.h,Level.cpp-This class is responsible for reading the game's stages and placing objects on the screen according to their
positions in the game. Additionally, this class determines the size of each object based on a calculation performed within the class.
This department is also responsible for removing from the relevant vectors the objects that were involved in a collision.

Menu.h,Menu.cpp-This class, as its name suggests, is responsible for displaying a menu to the user and providing options to start 
a new game, exit, or get help. Additionally, this class manages the end screen, which is activated when a player is disqualified or wins.

InfoBar.h,InfoBar.cpp-This class displays the game's data: the level number, time elapsed, number of lives, number of keys, score, 
and number of cheeses in each level.

Cats.cpp,Cats.h- this files is the job of  the cat in the game this files  responsible for moving the cat on the 
board and chasing the mouse

Mouse.cpp,Mouse.h-this files responsible for the mouse movment on the board and check the status of the cheese he ate,
presents,life,and keys

Macros.h-define all constants values in game and define enums to hold the info about textures or sound 

-------------------------from here the implementation is similar in the classes below---------------------------------
in those classes we manage collision with the entities in the game and ther methods 

CatPop.h,CatPop.cpp-power-up for poping a cat from the screen 
Freezer.h,Freezer.cpp- power-up for freezing the cats for limited time 
ExtraTime.h,ExtraTime.cpp-power-up for get extra time to the level 
LifeSaver.h,LifeSaver.cpp- power-up for get an extra life(Note if you already have three lifes you cant get them )
Key.h,Key.cpp- for opening doors
Doors.h,Doors.cpp- same as wall but if the mouse as keys he can open this door 
Wall.h, Wall.cpp- as it sounds response to make sure nobody can pass through them 
Cheese.h,Cheese.cpp- for mouse to eat them and get points

MAIN DATA STRUCTURE AND THEIR FUNCTIONS:

To hold the objects in the game, I used unique_ptr vectors
For the textures, fonts, and sounds, I hold an array for each of them, which holds the texture, font, or sound after they have been opened (pointers).

NOTEWORTHY ALGORITHMS:

for the cats chasing the mouse i used Distance formula the algorithm scanning all the locations (LEFT,RIGHT,UP,DOWN) ,
This algorithm chooses the preferred way to go. In case we get stuck, the algorithm will recalculate where it should go.
The algorithm doesn't know how to make the cats walk around the walls.

KNOWS BUGS:

When eaten by a cat, they are supposed to return to their initial position. For some reason, only one cat returns,
 even though I go through all the cat vectors and tell them to return to their initial position.

OTHER NOTES:
-As i said if you already three life you cant take another life 
-if you need to add level just add to the cmake level and call it "level00X.txt" (X-for the number you want)
-please note I added 3 numbers in the open of all the level files, the first number is the time of the level so 
when you add a new level make sure you  put a number of minutes you want
-Please note not to surpass the limit of 18 in width and 30 in height when you add a level.
-For a good appearance, try to stay within the limits of 16 in width and 27 in height.





