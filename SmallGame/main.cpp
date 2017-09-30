#include "HelpFunctions.h"
#include "Playground.h"
#include "MovementHandler.h"
#include "GameMaster.h"
#include <conio.h>

using std::cout;

void main()
{
	Playground pg(20,40);
	Player player;
	Wall wall;
	Ball ball;
	MovementHandler move(pg,wall);
	GameMaster gm(pg, wall, ball, player);

	pg.attachPlayer(&player);
	pg.attachWall(&wall);
	pg.attachBall(&ball);

	ball.destroyableWall(&wall);

	gm.introduction();

	while (true)
	{
		if (_kbhit())
		{
			char input = _getch();
			move.getKey(input, player);
		}

		gm.updateLevel();
		gm.showLevel();

		gm.victory_check();
		gm.loss_check();

		move.execute(
			ball.getDirectionX(),
			ball.getDirectionY(),
			ball
		);

		gm.updateLevel();
	}
}