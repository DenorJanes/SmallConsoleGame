#pragma once
#include "DynamicGameObject.h"
#include "HelpFunctions.h"

class Wall
{
	using Point = DynamicGameObject::Point2D;

private:
	enum size { width = 30, height = 7 };

	char ** body;

public:

	Point position;

	Wall();
	~Wall();

	// getters
	int getWidth() const { return width; }
	int getHeight() const { return height; }

	void destroy(Point* begin, Point* end);

	const char* const operator[](int i) const { return (i < height && i >= 0) ? body[i] : nullptr; }

};

