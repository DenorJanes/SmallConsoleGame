#include "Wall.h"



Wall::Wall()
{
	body = new char*[height];

	for (int i(0); i < height; ++i)
	{
		body[i] = new char[width];

		fill_row(body[i], width, DynamicGameObject::body_mesh::cube);
	}

	wall_health = height * width;
}


Wall::~Wall()
{
	if (!body)
		delete[] body;
}

void Wall::destroy(Point* begin, Point* end)
{
	while (begin != end)
	{
		if (begin->x >= position.x &&
			begin->y >= position.y &&
			begin->x < position.x + width &&
			begin->y < position.y + height)
		{
			body[begin->y - position.y][begin->x - position.x] = ' ';
		}

		wall_health--;
		begin++;
	}

}

