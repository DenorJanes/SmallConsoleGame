#include <iostream>
#include "Playground.h"

using std::cout;

void main()
{
	Playground pg(20,40);
	Player player;
	
	pg.attachPlayer(&player);
	pg.UpdatePlayerPosition();
	pg.display_scene();

	system("pause");
}