#pragma once
#include "DynamicGameObject.h"
#include "HelpFunctions.h"

class Wall
{
	enum size { width = 30, height = 7 };


	char ** body;

public:

	DynamicGameObject::Point2D position;

	Wall();
	~Wall();

	// getters
	int getWidth() const { return width; }
	int getHeight() const { return height; }

	const char* const operator[](int i) const { return (i < height && i >= 0) ? body[i] : nullptr; }

};

