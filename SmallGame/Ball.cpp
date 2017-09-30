#include "Ball.h"


bool Ball::CheckPathTo(const char** const scene,int x, int y)
{
	int X = x + position.x;
	int Y = y + position.y;
	
	static bool tryX = true;

	// we are in the corner
	if (scene[Y][position.x] != ' ' && scene[position.y][X] != ' ') // we are in the corner
		{
			direction.x = -x;
			direction.y = -y;
			
			if (_wall)
			{
				Point2D* points = new Point2D[3];
				points[0] = Point2D{ position.x, Y };
				points[1] = Point2D{ X, position.y };
				points[2] = Point2D{ X, Y };

				_wall->destroy(points, points + 3);

				delete[] points;
			}
		}
	// we are facing top or bottom bounds
	else if (scene[Y][position.x] != ' ') 
	{ 
		direction.y = -y;

		if (_wall)
		{
			Point2D* point = new Point2D;
			*point = Point2D{ position.x, Y };

			_wall->destroy(point, point + 1);

			delete point;
		}
	}
	// we are facing left or right bounds																		  
	else if (scene[position.y][X] != ' ') 
	{ 
		direction.x = -x; 

		if (_wall)
		{
			Point2D* point = new Point2D;
			*point = Point2D{ X, position.y };

			_wall->destroy(point, point + 1);

			delete point;
		}
	} 
	// we are facing the corner
	else if (scene[Y][X] != ' ')
	{
		if (tryX) direction.x = -x;
		else if (!tryX) direction.y = -y;
		
		tryX = !tryX;

		if (_wall)
		{
			Point2D* point = new Point2D;
			*point = Point2D{ X, Y };

			_wall->destroy(point, point + 1);

			delete point;
		}	
	}

	if(scene[position.y + direction.y][position.x + direction.x] == ' ') return true;
	else CheckPathTo(scene, direction.x, direction.y);
}

Ball::Ball()
{
	srand(time(NULL));

	direction.x = (rand() % 2) ? 1 : -1;
	direction.y = -1;

	body = new char(circle);
}

Ball::~Ball()
{
	delete body;
}
