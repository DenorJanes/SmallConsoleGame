#pragma once
#include "DynamicGameObject.h"
#include <time.h>
#include <random>

class Ball : public DynamicGameObject
{
public:
	Ball();
	~Ball();

	const char getBody() const { return *body; }
	int getDirectionX() const { return direction.x; }
	int getDirectionY() const { return direction.y; }

	bool checkPathTo(const char** const scene, int x, int y) override;

};

