#include "MovementHandler.h"

bool MovementHandler::getKey(char key, Player& player)
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

void MovementHandler::execute(int x, int y, DynamicGameObject& obj)
{
	if (abs(x) > 1) x /= abs(x);
	if (abs(y) > 1) y /= abs(y);

	int count = 0;

	// check if proper direction isn't set yet
	if (!obj.CheckPathTo(_pg.getScene(), x, y))
	{
		while(!obj.CheckPathTo(
			_pg.getScene(),
			obj.direction.x,
			obj.direction.y
		)) {
			count++;
			if (count == 10)
			{
				_pg.display_scene();
			}
		}
	}
	obj.MoveInDirection();
}
