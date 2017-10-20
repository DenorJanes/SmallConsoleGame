#pragma once

class Playground;
class DynamicGameObject;

class MovementHandler
{
private:
	// a location for movement
	Playground& _pg;

	// a method for player input movement
	bool getKey(DynamicGameObject& obj, char key);

public:
	MovementHandler() = delete;
	explicit MovementHandler(Playground& pg) : _pg(pg) {}
	~MovementHandler() = default;

	// a method for movement in supplied direction
	void execute(DynamicGameObject& obj, char key = '\0');
};

