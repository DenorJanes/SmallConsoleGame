#pragma once
#include "GameObject.h"

class Player : public GameObject
{
	int leftEdgeX, leftEdgeY;
	int rightEdgeX, rightEdgeY;
	int centerX, centerY;

	enum player_size { length = 9 };

public:
	Player();
	~Player();
};

