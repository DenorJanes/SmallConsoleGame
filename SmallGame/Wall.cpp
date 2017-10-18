#include "Wall.h"

Wall::Wall()
{
	for (int i(0); i < height; ++i)
		body.push_back(std::string(width, cube));

	wall_health = height * width;
}

void Wall::destroy(iterP2D begin, iterP2D end)
{
	while (begin != end)
	{
		if (begin->x >= position.x &&
			begin->y >= position.y &&
			begin->x < position.x + width &&
			begin->y < position.y + height)
		{
			body[begin->y - position.y][begin->x - position.x] = ' ';
			wall_health--;
		}

		begin++;
	}
}

const char Wall::getBody(int row, int column) const 
{ 
	if (column >= 0 && row >= 0 && column < width && row < height) return body[row][column];
	else return ' ';
}

