#include "Player.h"



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
