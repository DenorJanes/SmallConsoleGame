#pragma once
#include "DynamicGameObject.h"
#include <time.h>
#include <random>

class Wall;

class Ball : public DynamicGameObject
{
private:
	// an object that can be destructed by ball
	Wall* _wall;

public:
	explicit Ball(Wall* = nullptr);
	~Ball();

	const char getBody() const { return *body; }
	int getDirectionX() const { return direction.x; }
	int getDirectionY() const { return direction.y; }

	virtual bool CheckPathTo(const char** const scene, int x, int y) override;
	virtual void MoveInDirection() override;

	void destroyableWall(Wall* wall) 
	{ 
		if (!wall) return;
		else _wall = wall;
	}
};

