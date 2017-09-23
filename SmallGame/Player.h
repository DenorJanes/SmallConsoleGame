#pragma once
#include "DynamicGameObject.h"
#include "HelpFunctions.h"

class Player : public DynamicGameObject
{
	enum player_length { length = 9 }; // cube - code for char symbol

public:

	Player();
	~Player();

	bool checkPathTo(const char** const scene, int* x, int* y) override { return 1; }

	int getLength() const { return length; }

	char operator[](int i) const { return (i < length && i >= 0) ? body[i] : ' '; }
};

