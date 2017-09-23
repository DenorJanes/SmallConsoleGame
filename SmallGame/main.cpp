#include <iostream>
#include "Playground.h"
#include "MovementHandler.h"
#include <Windows.h>

using std::cout;

void main()
{
	Playground pg(20,41);
	Player player;
	Wall wall;
	Ball ball;
	MovementHandler move;

	pg.attachPlayer(&player);
	pg.attachWall(&wall);
	pg.attackBall(&ball);

	while (1)
	{
		pg.UpdatePlayerPosition();
		pg.UpdateWallPosition();
		pg.UpdateBallPosition();

		pg.display_scene();
		Sleep(200);
		system("cls");

		move.execute(ball, pg);

		pg.clear_playground();

		///////////////////////
		
	}

	
	system("pause");
}