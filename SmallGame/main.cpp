#include <iostream>
#include "Playground.h"
#include "MovementHandler.h"
#include <Windows.h>
#include <conio.h>

using std::cout;

void main()
{
	Playground pg(20,41);
	Player player;
	Wall wall;
	Ball ball;
	MovementHandler move(pg,wall);

	pg.attachPlayer(&player);
	pg.attachWall(&wall);
	pg.attachBall(&ball);

	ball.destroyableWall(&wall);

	while (1)
	{
		pg.UpdatePlayerPosition();
		pg.UpdateWallPosition();
		pg.UpdateBallPosition();

		pg.display_scene();
		Sleep(100);
		system("cls");

		if (_kbhit())
		{
			char input = _getch();
			move.getKey(input,player);
		}

		move.execute(
			ball.getDirectionX(),
			ball.getDirectionY(),
			ball
		);

		pg.clear_playground();

		///////////////////////
		
	}

	
	system("pause");
}