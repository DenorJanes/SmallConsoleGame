#include "MovementHandler.h"
#include "DynamicGameObject.h"
#include "Playground.h"
#include <cmath>

bool MovementHandler::getKey(DynamicGameObject& obj, char key)
{
	switch (key)
	{
	case 'w': obj.setDirectionX(0); obj.setDirectionY(-1); break;
	case 's': obj.setDirectionX(0); obj.setDirectionY(1);  break;
	case 'a': obj.setDirectionX(-1); obj.setDirectionY(0); break;
	case 'd': obj.setDirectionX(1); obj.setDirectionY(0);  break;
	default: return false;
	}
	
	return true;
}

void MovementHandler::execute(DynamicGameObject& obj, char key)
{
	// check for proper player input
	getKey(obj, key);

	// check if direction that ball can move ahead is set
	int getOut = 0;
	while (!obj.CheckPathInDirection(_pg.getScene()))
	{
		// check if ball isn't locked by wall and player
		if (++getOut > 4) 
		{ 
			obj.setDirectionX(0); 
			obj.setDirectionY(0); 
			break;
		}
	}

	obj.MoveInDirection();
}
