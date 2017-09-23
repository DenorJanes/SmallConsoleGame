#pragma once
#include "Ball.h"
#include "Wall.h"
#include "Playground.h"
#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;

class GameMaster
{
private:
	Playground& _pg;
	Wall& _wall;
	Ball& _ball;
	Player& _player;

public:
	GameMaster(Playground& pg, Wall& wall, Ball& ball, Player& player) : _pg(pg), _wall(wall), _ball(ball), _player(player) {}
	GameMaster() = delete;
	~GameMaster() = default;
	
	void introduction();
	void showLevel();
	void updateLevel();
	void victory_check();
	void loss_check();
};

