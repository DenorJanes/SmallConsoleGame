#include "Ball.h"


bool Ball::checkPathTo(const char** const scene)
{
	int X = direction.x + position.x;
	int Y = direction.y + position.y;

	if(scene[Y][X] != ' ')
		if (scene[Y][position.x] != ' ' && scene[position.y][X] != ' ') // we are in the corner
		{ 
			direction.x = -direction.x;
			direction.y = -direction.y;
			return false; 
		} 
		else if (scene[Y][position.x] != ' ') { direction.y = -direction.y; return false; } // we are facing top or bottom bounds
		else if (scene[position.y][X] != ' ') { direction.x = -direction.x; return false; } // we are facing left or right bounds

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
