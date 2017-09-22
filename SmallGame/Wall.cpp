#include "Wall.h"



Wall::Wall()
{
	body = new char*[height];

	for (int i(0); i < height; ++i)
	{
		body[i] = new char[width];

		fill_row(body[i], width, cube);
	}
}


Wall::~Wall()
{
	if (!body)
		delete[] body;
}
