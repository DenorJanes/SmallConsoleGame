#pragma once

template <typename T>
class GameObject
{
public:

	enum body_mesh { cube = 223 };
	struct Point2D
	{
		int x;
		int y;
	} position;

	virtual void moveTo(int, int) = 0;

	GameObject() = default;
	virtual ~GameObject() = default;

protected:
	T body;
};

