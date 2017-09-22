#include "Player.h"


void Player::moveTo(int x, int y)
{

}

Player::Player()
{
	body = new char[length + 1];
	fill_row(body, length, cube);
	body[length] = '\0';
}


Player::~Player()
{
	if (body)
		delete[] body;
}
