#include "MovementHandler.h"
#include "DynamicGameObject.h"
#include "Playground.h"
#include <cmath>

bool MovementHandler::getKey(char key, DynamicGameObject& player)
{
	switch (key)
	{
	case 'w': execute(0, -1, player); break;
	case 's': execute(0, 1, player); break;
	case 'a': execute(-1, 0, player); break;
	case 'd': execute(1, 0, player); break;
	default: return false;
	}
	
	return true;
}

void MovementHandler::execute(int dirX, int dirY, DynamicGameObject& obj)
{
	if (abs(dirX) > 1) dirX /= abs(dirX);
	if (abs(dirY) > 1) dirY /= abs(dirY);

	// check if direction that ball can move ahead is set
	if (!obj.CheckPathTo(_pg.getScene(), dirX, dirY))
	{
		while (!obj.CheckPathTo(
			_pg.getScene(),
			obj.direction.x,
			obj.direction.y
		));
	}

	obj.MoveInDirection();
}
