#pragma once
#include "DynamicGameObject.h"
#include "Playground.h"

class MovementHandler
{
public:
	MovementHandler() = default;
	~MovementHandler() = default;

	void execute(DynamicGameObject& obj, Playground& pg);
};

