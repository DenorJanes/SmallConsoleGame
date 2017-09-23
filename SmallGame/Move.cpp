#include "MovementHandler.h"


MovementHandler::MovementHandler(int x, int y, DynamicGameObject& obj, Playground& pg) : _obj(obj) , _pg(pg)
{
	if (abs(x) > 1) x /= abs(x);
	if (abs(y) > 1) y /= abs(y);

	_obj.checkPathTo(_pg.getScene(), &x, &y);
	_obj.MoveTo(x, y);
	_pg.UpdateBallPosition();
}

MovementHandler::~MovementHandler()
{
}
