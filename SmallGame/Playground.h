#pragma once
#include <iostream>
#include "Player.h"
#include "Wall.h"
#include "Ball.h"
#include "HelpFunctions.h"

class Playground
{
public:
	

	//default constructor and destrucor
	explicit Playground(int size_row = 20, int size_column = 40);
	~Playground();

	// displaying the content that is already exist in the scene
	void display_scene() const;

	// getters
	int getColumnSize() const { return _scene_size_column; }
	int getRowSize() const { return _scene_size_row; }
	int game_over() const { return _scene_size_row-2; }
	const char** const getScene() const { return const_cast<const char**>(scene); }

	// setters
	bool attachPlayer(Player* player);
	bool attachWall(Wall* wall);
	bool attachBall(Ball* ball);
	

	void UpdatePlayerPosition();
	void UpdateWallPosition();
	void UpdateBallPosition();

	void clear_playground();

private:

	Player* _player;
	Wall* _wall;
	Ball* _ball;

	int _scene_size_row, _scene_size_column; 
	char** scene;
};

