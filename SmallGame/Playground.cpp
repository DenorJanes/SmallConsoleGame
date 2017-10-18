#include "Playground.h"
#include "Player.h"
#include "Wall.h"
#include "Ball.h"
#include "HelpFunctions.h"
#include <iostream>

bool Playground::attachPlayer(Player* player) 
{ 
	if (!player)
		return false;

	_player = player; 
	_player->position.x = (_scene_size_column - _player->getLength())/2;
	_player->position.y = _scene_size_row - 3;

	return true;
}
bool Playground::attachWall(Wall* wall)
{
	if (!wall)
		return false;

	_wall = wall;
	_wall->position.x = (_scene_size_column - _wall->getWidth()) / 2;
	_wall->position.y = 3;

	return true;
}
bool Playground::attachBall(Ball* ball)
{
	if (!ball)
		return false;

	_ball = ball;
	_ball->position.x = (_scene_size_column) / 2;
	_ball->position.y = _scene_size_row - 4;

	return true;
}
void Playground::UpdatePlayerPosition()
{
	if (!_player)
		return;
	
	int Y = _player->position.y;
	int length = _player->position.x + _player->getLength();

	for (int X = _player->position.x; X < length; X++)
		scene[Y][X] = _player->getBody(X - _player->position.x);
}
void Playground::UpdateWallPosition() 
{
	if (!_wall)
		return;

	int width = _wall->position.x + _wall->getWidth();
	int height = _wall->position.y + _wall->getHeight();

	for (int Y = _wall->position.y; Y < height; Y++)
		for (int X = _wall->position.x; X < width; X++)
			scene[Y][X] = _wall->getBody(Y - _wall->position.y, X - _wall->position.x);
}
void Playground::UpdateBallPosition() {
	if (!_ball)
		return;

	int Y = _ball->position.y;
	int X = _ball->position.x;

	scene[Y][X] = _ball->getBody();
}

Playground::Playground(int size_row,int size_column)
{
	_scene_size_row = (size_row < 20) ? 20 : size_row;
	_scene_size_column = (size_column < 40) ? 40 : size_column;

	scene = new char*[_scene_size_row];

	for (int i = 0; i < _scene_size_row; ++i)
		scene[i] = new char[_scene_size_column];
}
Playground::~Playground()
{
	if (scene != nullptr)
		delete[] scene;
}

void Playground::clear_playground()
{
	for (int i = 0; i < _scene_size_row; ++i)
	{
		if (i == 0 || i == _scene_size_row - 1)  fill_row(scene[i], _scene_size_column, '*');
		else
		{
			fill_row(scene[i], _scene_size_column);
			scene[i][0] = scene[i][_scene_size_column - 1] = '*';
		}
	}
}

void Playground::display_scene() const
{
	for (int i = 0; i < _scene_size_row; ++i)
	{
		for (int j = 0; j < _scene_size_column; ++j)
			std::cout << scene[i][j];

		std::cout << std::endl;
	}
}