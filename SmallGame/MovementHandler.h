#pragma once

class Playground;
class DynamicGameObject;

class MovementHandler
{
private:
	// a location for movement
	Playground& _pg;

public:
	MovementHandler() = delete;
	explicit MovementHandler(Playground& pg) : _pg(pg) {}
	~MovementHandler() = default;

	// a method for player input movement
	bool getKey(char key, DynamicGameObject& player);

	// a method for movement in supplied direction
	void execute(int x, int y, DynamicGameObject& obj);
};

