#pragma once
#include "DynamicGameObject.h"
#include "Playground.h"

class MovementHandler
{
private:
	Playground& _pg;

public:
	MovementHandler() = delete;
	explicit MovementHandler(Playground& pg) : _pg(pg) {}
	~MovementHandler() = default;

	bool getKey(char key, Player& player);
	void execute(int x,int y, DynamicGameObject& obj);
};

