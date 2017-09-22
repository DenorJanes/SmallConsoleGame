#include "Playground.h"



Playground::Playground(int size_row,int size_column) : _scene_size_row(size_row), _scene_size_column(size_column)
{
	scene = new char*[_scene_size_row];
	for (int i = 0; i < _scene_size_row; ++i)
	{
		scene[i] = new char[_scene_size_column];
	
		
		if (i == 0 || i == _scene_size_row - 1)  fill_row(scene[i], '*'); 
		else
		{
			fill_row(scene[i]);
			scene[i][0] = scene[i][_scene_size_column - 1] = '*';
		}
	}
}


Playground::~Playground()
{
	if (scene != nullptr)
		delete[] scene;
}

void Playground::fill_field(char** field)
{
	for (int i = 0; i < _scene_size_row; ++i)
	{
		if (i == 0 || i == _scene_size_row - 1)  fill_row(scene[i], '*');
		else
		{
			fill_row(scene[i]);
			scene[i][0] = scene[i][_scene_size_column - 1] = '*';
		}
	}
}
void Playground::fill_row(char* scene_row, char with)
{
	for (int i = 0; i < _scene_size_column; ++i)
		scene_row[i] = with;
}

void Playground::display_scene()
{
	for (int i = 0; i < _scene_size_row; ++i)
	{
		for (int j = 0; j < _scene_size_column; ++j)
			std::cout << scene[i][j];
		std::cout << std::endl;
	}
}