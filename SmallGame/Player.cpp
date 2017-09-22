#include "Player.h"



Player::Player()
{
	body = new char[length];
	for (int i = 0; i < length; ++i)
		body[i] = 223; // cude symbol

}


Player::~Player()
{
	if (body)
		delete[] body;
}
