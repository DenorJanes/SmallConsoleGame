#pragma once
class GameObject
{
public:

	virtual void moveTo(int, int) = 0;

	GameObject() = default;
	virtual ~GameObject() = default;

private:
	char* body;
};

