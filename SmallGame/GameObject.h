#pragma once
class GameObject
{
public:

	struct Point2D
	{
		int x;
		int y;
	} position;

	virtual void moveTo(int, int) = 0;

	GameObject() = default;
	virtual ~GameObject() = default;

protected:
	char* body;
};

