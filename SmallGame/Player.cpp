#include "Player.h"



Player::Player()
{
	body = new char[length + 1];
	fill_row(body, length, cube);
	body[length] = '\0';

	direction.x = 0;
	direction.y = 0;
}

Player::~Player()
{
	if (body)
		delete[] body;
}

bool Player::CheckPathTo(const char ** const scene, int x, int y)
{
	int X = x + position.x;
	int Y = y + position.y;

	// moving lefr or right
	if (y == 0) 
	{
		if (scene[position.y][X] != ' ' && scene[position.y][X + length] != ' ')
		{
			x = 0;
		}
	}
	// moving up or down
	else if (x == 0) 
	{
		for (int iX = position.x; iX < position.x + length; ++iX)
		{
			if (scene[Y][iX] != ' ') 
			{
				y = 0;
				break;
			}
		}
	}

	direction.x = x;
	direction.y = y;

	return true;
}

void Player::MoveInDirection()
{
	position.x += direction.x*2;
	position.y += direction.y*1;
}


