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

	void fall() { direction.x = (rand() % 2) ? 1 : -1; direction.y = 1; }

public:
	explicit Ball(Wall* = nullptr);
	~Ball() = default;

	const char getBody() const { return body[0][0]; }

	virtual bool CheckPathInDirection(const std::vector<std::string> scene) override;
	virtual void MoveInDirection() override;

	void destroyableWall(Wall* wall) 
	{ 
		if (!wall) return;
		else _wall = wall;
	}
};

