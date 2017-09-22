#pragma once
#include "GameObject.h"
#include "HelpFunctions.h"


class Wall: public GameObject<char**>
{
	enum size { width = 30, height = 7 };

public:
	Wall();
	~Wall();

	// getters
	int getWidth() const { return width; }
	int getHeight() const { return height; }

	const char* const operator[](int i) const { return (i < height && i >= 0) ? body[i] : nullptr; }

	virtual void moveTo(int x, int y) override {};
};

