#pragma once


class DynamicGameObject
{
public:

	enum body_mesh { cube = 223, circle = 111 };
	struct Point2D
	{
		int x;
		int y;
	} position;
	struct UnitVector2D {
		int x;
		int y;
	} direction;

	void MoveInDirection()
	{
		position.x += direction.x;
		position.y += direction.y;
	}
	virtual bool checkPathTo(const char** const scene,int x, int y) = 0;

	DynamicGameObject() = default;
	virtual ~DynamicGameObject() = default;

protected:

	char* body;
};

