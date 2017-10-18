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

	GameObject() = default;
	virtual ~GameObject() = default;

protected:
	std::vector<std::string> body;
};

