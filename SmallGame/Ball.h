#pragma once
#include "DynamicGameObject.h"
#include "Wall.h"
#include <time.h>
#include <random>

class Ball : public DynamicGameObject
{
private:
	Wall* _wall;

public:
	Ball();
	~Ball();

	const char getBody() const { return *body; }
	int getDirectionX() const { return direction.x; }
	int getDirectionY() const { return direction.y; }

	bool CheckPathTo(const char** const scene, int x, int y) override;

	bool destroyableWall(Wall* wall) 
	{ 
		if (!wall) return false;
		else _wall = wall;
		return true; 
	}

};

