#pragma once
#include "DynamicGameObject.h"
#include <list>

class Wall: GameObject
{
	using iterP2D = std::list<Point2D>::iterator;

private:
	enum size { width = 30, height = 7 };
	int wall_health;

public:
	Point2D position;

	Wall();
	~Wall() = default;

	// getters
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	int getWallHealth() const { return wall_health; }

	void destroy(iterP2D begin, iterP2D end);

	const char getBody(int row, int column) const;
};
