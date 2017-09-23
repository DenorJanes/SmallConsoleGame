#pragma once
#include "DynamicGameObject.h"
#include <time.h>
#include <random>

class Ball : public DynamicGameObject
{
private:
	int _xDir, _yDir;
public:
	Ball();
	~Ball();

	const char getBody() const { return *body; }
	int getDirectionX() const { return _xDir; }
	int getDirectionY() const { return _yDir; }

	bool checkPathTo(const char** const scene, int* x, int* y) override;

};

