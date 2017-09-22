#include "Player.h"
#include <iostream>
void Player::moveTo(int x, int y)
{

}

Player::Player()
{
	body = new char[length + 1];

	for (int i = 0; i < length; ++i)
		body[i] = (char)223; // cude symbol
	body[length] = '\0';
}


Player::~Player()
{
	if (body)
		delete[] body;
}
