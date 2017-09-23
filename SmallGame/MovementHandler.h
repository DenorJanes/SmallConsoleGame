#pragma once
#include "DynamicGameObject.h"
#include "Playground.h"

class MovementHandler
{
private:

	DynamicGameObject& _obj;
	Playground& _pg;


public:
	MovementHandler(int x, int y, DynamicGameObject& obj, Playground& pg);
	~MovementHandler();
};

