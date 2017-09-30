#pragma once
#include "DynamicGameObject.h"
#include "HelpFunctions.h"

class Player : public DynamicGameObject
{
	enum player_properties { length = 10 }; 

public:

	Player();
	~Player();

	bool CheckPathTo(const char** const scene, int x, int y) override;
	void MoveInDirection() override;

	int getLength() const { return length; }

	const char getBody(int pos) const { return (pos < length && pos >= 0) ? body[pos] : ' '; }
};

