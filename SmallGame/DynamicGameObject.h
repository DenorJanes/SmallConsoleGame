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

	virtual void MoveInDirection() = 0;
	virtual bool CheckPathTo(const char** const scene,int x, int y) = 0;

	DynamicGameObject() { position.x = position.y = 0; }
	virtual ~DynamicGameObject() = default;

protected:
	char* body;
};

