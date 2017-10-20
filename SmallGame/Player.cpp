#include "Player.h"

Player::Player()
{
	body.push_back(std::string(length, cube));

	direction.x = 0;
	direction.y = 0;
}

bool Player::CheckPathInDirection(const std::vector<std::string> scene)
{
	int X = direction.x + position.x;
	int Y = direction.y + position.y;

	// moving lefr or right
	if (direction.y == 0) 
	{
		if (scene[position.y][X] != ' ' && scene[position.y][X + length] != ' ')
		{
			direction.x = 0;
		}
	}
	// moving up or down
	else if (direction.x == 0) 
	{
		for (int iX = position.x; iX < position.x + length; ++iX)
		{
			if (scene[Y][iX] != ' ') 
			{
				direction.y = 0;
				break;
			}
		}
	}

	return true;
}
void Player::MoveInDirection()
{
	position.x += direction.x*2;
	position.y += direction.y*1;

	direction.x = direction.y = 0;
}


