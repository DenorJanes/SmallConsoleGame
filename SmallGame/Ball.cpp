#include "Ball.h"
#include "Wall.h"
#include <list>

bool Ball::CheckPathTo(const char** const scene,int x, int y)
{
	int X = x + position.x;
	int Y = y + position.y;
	
	// for different direction after hitting the edge
	bool decision = rand() % 2;

	// we are in the corner
	if (scene[Y][position.x] != ' ' && scene[position.y][X] != ' ') // we are in the corner
		{
			direction.x = -x;
			direction.y = -y;
			
			if (_wall)
			{
				std::list<Point2D> points;
				points.push_back(Point2D{ position.x, Y });
				points.push_back(Point2D{ X, position.y });
				points.push_back(Point2D{ X, Y });

				_wall->destroy(points.begin(), points.end());
			}
		}
	// we are facing top or bottom bounds
	else if (scene[Y][position.x] != ' ') 
	{ 
		direction.y = -y;

		if (_wall)
		{
			std::list<Point2D> points;
			points.push_back(Point2D{ position.x, Y });

			_wall->destroy(points.begin(), points.end());
		}
	}
	// we are facing left or right bounds																		  
	else if (scene[position.y][X] != ' ') 
	{ 
		direction.x = -x; 

		if (_wall)
		{
			std::list<Point2D> points;
			points.push_back(Point2D{ X, position.y });

			_wall->destroy(points.begin(), points.end());
		}
	} 
	// we are facing the edge of the corner
	else if (scene[Y][X] != ' ')
	{
		(decision) ? direction.x = -x : direction.y = -y;

		if (_wall)
		{
			std::list<Point2D> points;
			points.push_back(Point2D{ X, Y });

			_wall->destroy(points.begin(), points.end());
		}	
	}

	if(scene[position.y + direction.y][position.x + direction.x] == ' ') return true;
	else return false;
}
void Ball::MoveInDirection()
{
	position.x += direction.x;
	position.y += direction.y;
}

Ball::Ball(Wall* wall): _wall(wall)
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
