#pragma once
#include "GameObject.h"

class Player : public GameObject
{

	enum player_propperies { length = 9, cube = 223 }; // cube - code for char symbol

public:

	Player();
	~Player();

	virtual void moveTo(int x, int y) override;

	int getLength() const { return length; }

	char operator[](int i) const { return (i < length && i >= 0) ? body[i] : ' '; }
};

