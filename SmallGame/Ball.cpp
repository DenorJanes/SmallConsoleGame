#include "Ball.h"


bool Ball::checkPathTo(const char** const scene, int* x, int* y)
{
	int X = *x + position.x;
	int Y = *y + position.y;

	if(scene[Y][X] != ' ')
		if (scene[Y][position.x] != ' ' && scene[position.y][X] != ' ') { *x = -*x; *y = -*y; return false; } // we are in the corner
		else if (scene[Y][position.x] != ' ') { *y = -*y; return false; } // we are facing top or bottom bounds
		else if (scene[position.y][X] != ' ') { *x = -*x; return false; } // we are facing left or right bounds

		return true;
}

Ball::Ball()
{
	srand(time(NULL));

	_xDir = (rand() % 2) ? 1 : -1;
	_yDir = 1;

	body = new char(cube);
}


Ball::~Ball()
{
}
