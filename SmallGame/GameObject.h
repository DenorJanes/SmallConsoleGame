#pragma once
#include <vector>
#include <string>

class GameObject
{
public:
	enum body_mesh { cube = 223, circle = 111 };
	struct Point2D
	{
		int x;
		int y;
	} position;

	GameObject() { position.x = 0; position.y = 0; }
	virtual ~GameObject() = default;

protected:
	std::vector<std::string> body;
};

