#include "GameMaster.h"

void GameMaster::introduction()
{
	cout << "********************************" << endl;
	cout << "*        Hello, player!        *" << endl;
	cout << "*    Before the game starts    *" << endl;
	cout << "* make sure that you are using *" << endl;
	cout << "*   english language on your   *" << endl;
	cout << "* computer with caps lock off! *" << endl;
	cout << "*   Press w s a d to control.  *" << endl;
	cout << "*          Good luck!          *" << endl;
	cout << "********************************" << endl;
	system("pause");
}

void GameMaster::showLevel()
{
	_pg.display_scene();

	cout << "******************************" << endl;
	cout << "* Wall's current health: " << _wall.getWallHealth() << " *" << endl;
	cout << "******************************" << endl;

	Sleep(100);
	system("cls");
}

void GameMaster::updateLevel()
{
	_pg.clear_playground();
	_pg.UpdatePlayerPosition();
	_pg.UpdateWallPosition();
	_pg.UpdateBallPosition();
}

void GameMaster::victory_check()
{
	if (_wall.getWallHealth() == 0)
	{
		cout << "Congratulations! You win!" << endl;
		system("pause");

		exit(1);
	}

}

void GameMaster::loss_check()
{
	if (_pg.game_over() == _ball.position.y)
	{
		cout << "The game is over!" << endl;
		system("pause");

		exit(1);
	}
}
