#pragma once


class DynamicGameObject
{
public:

	enum body_mesh { cube = 223 };
	struct Point2D
	{
		int x;
		int y;
	} position;

	void MoveTo(int x, int y)
	{
		position.x += x;
		position.y += y;
	}
	virtual bool checkPathTo(const char** const scene, int* x, int* y) = 0;

	DynamicGameObject() = default;
	virtual ~DynamicGameObject() = default;

protected:

	char* body;
};

