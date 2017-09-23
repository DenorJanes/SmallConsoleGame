#include "Ball.h"


bool Ball::checkPathTo(const char** const scene,int x, int y)
{
	int X = x + position.x;
	int Y = y + position.y;

	// we are in the corner
	if (scene[Y][position.x] != ' ' && scene[position.y][X] != ' ') // we are in the corner
		{
			direction.x = -x;
			direction.y = -y;
			return false;
		}
	// we are facing top or bottom bounds
	else if (scene[Y][position.x] != ' ') { direction.y = -y; return false; }
	// we are facing left or right bounds																		  
	else if (scene[position.y][X] != ' ') { direction.x = -x; return false; } 
	// we are facing the corner
	else if (scene[Y][X] != ' ')
	{
		{
			direction.x = -x;
			direction.y = -y;
			return false;
		}
	}

	return true;
}

Ball::Ball()
{
	srand(time(NULL));

	direction.x = (rand() % 2) ? 1 : -1;
	direction.y = -1;

	body = new char(circle);
}


Ball::~Ball()
{
	delete body;
}
