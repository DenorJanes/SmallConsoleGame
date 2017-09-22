#pragma once
#include <iostream>
#include "Player.h"
class Playground
{
public:
	//default constructor and destrucor
	explicit Playground(int size_row = 20, int size_column = 41);
	~Playground();

	// displaying the content that is already exist in the scene
	void display_scene() const;

	// getters and setters
	int getColumnSize() const { return _scene_size_column; }
	int getRowSize() const { return _scene_size_row; }
	void attachPlayer(Player* player);

	void UpdatePlayerPosition();
private:
	void fill_row(char* scene_row, char with = ' ');
	void fill_field(char** field);

	
	Player* _player;

	int _scene_size_row, _scene_size_column; 
	char** scene;
};

