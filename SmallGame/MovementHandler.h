#pragma once
#include "DynamicGameObject.h"
#include "Playground.h"

class MovementHandler
{
private:
	Playground& _pg;
	Wall& _wall;

public:
	MovementHandler() = delete;
	explicit MovementHandler(Playground& pg, Wall& wall) : _pg(pg), _wall(wall) {}
	~MovementHandler() = default;

	bool getKey(char key, Player& player);
	void execute(int x, int y, DynamicGameObject& obj);
};

