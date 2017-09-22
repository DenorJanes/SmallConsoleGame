#pragma once
#include <iostream>
#include "Player.h"
#include "Wall.h"
#include "HelpFunctions.h"

class Playground
{
public:
	//default constructor and destrucor
	explicit Playground(int size_row = 20, int size_column = 40);
	~Playground();

	// displaying the content that is already exist in the scene
	void display_scene() const;

	// getters and setters
	int getColumnSize() const { return _scene_size_column; }
	int getRowSize() const { return _scene_size_row; }
	void attachPlayer(Player* player);
	void attachWall(Wall* wall);

	void UpdatePlayerPosition();
	void UpdateWallPosition();
	void clear_playground();

private:

	Player* _player;
	Wall* _wall;

	int _scene_size_row, _scene_size_column; 
	char** scene;
};

