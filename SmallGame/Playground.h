#pragma once
#include <iostream>

class Playground
{
public:
	//default constructor
	explicit Playground(int size_row = 20, int size_column = 41);
	~Playground();

	void display_scene();
private:
	void fill_row(char* scene_row, char with = ' ');
	void fill_field(char** field);

	int _scene_size_row, _scene_size_column;
	// a scene to do all the action 
	char** scene;
};

