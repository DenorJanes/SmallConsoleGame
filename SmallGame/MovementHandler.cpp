#include "MovementHandler.h"

void MovementHandler::execute(DynamicGameObject& obj, Playground& pg)
{
	/*if (abs(x) > 1) x /= abs(x);
	if (abs(y) > 1) y /= abs(y);*/

	obj.checkPathTo(pg.getScene());
	obj.MoveInDirection();
}
