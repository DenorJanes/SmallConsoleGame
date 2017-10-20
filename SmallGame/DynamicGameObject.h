#pragma once
#include "GameObject.h"

class DynamicGameObject : public GameObject
{
public:
	virtual void MoveInDirection() = 0;
	virtual bool CheckPathTo(const std::vector<std::string> scene,int x, int y) = 0;

	int getDirectionX() const { return direction.x; }
	int getDirectionY() const { return direction.y; }
	
	void setDirectionX(int dirX) { direction.x = (abs(dirX) > 1) ? dirX / abs(dirX) : dirX; }
	void setDirectionY(int dirY) { direction.y = (abs(dirY) > 1) ? dirY / abs(dirY) : dirY; }

	DynamicGameObject() { position.x = position.y = 0; }
	virtual ~DynamicGameObject() = default;

protected:
	Point2D direction;
};

