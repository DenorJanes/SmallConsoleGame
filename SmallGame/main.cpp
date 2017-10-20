#include "Playground.h"
#include "Ball.h"
#include "Player.h"
#include "Wall.h"
#include "MovementHandler.h"
#include "GameMaster.h"
#include <conio.h>


void main()
{
	Playground pg;
	Player player;
	Wall wall;
	Ball ball;
	MovementHandler move(pg);
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
			move.execute(player, input);
		}

		gm.updateLevel();
		gm.showLevel();

		gm.victory_check();
		gm.loss_check();

		move.execute(ball);

		gm.updateLevel();
	}
}