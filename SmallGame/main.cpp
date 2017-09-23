#include <iostream>
#include "Playground.h"
#include "MovementHandler.h"

using std::cout;

void main()
{
	Playground pg(20,41);
	Player player;
	Wall wall;
	Ball ball;

	pg.attachPlayer(&player);
	pg.attachWall(&wall);
	pg.attackBall(&ball);

	pg.UpdatePlayerPosition();
	pg.UpdateWallPosition();
	pg.UpdateBallPosition();

	MovementHandler MovementHandler(-1, 10, ball, pg);

	pg.display_scene();

	system("pause");
}