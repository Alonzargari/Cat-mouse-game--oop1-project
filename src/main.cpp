#include "GameController.h"
#include "Menu.h"
int main()
{
	/*auto game = GameController();
	game.Run();*/
	auto menu = Menu();
	menu.menuRun();
	return EXIT_SUCCESS;
}
