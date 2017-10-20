#pragma once
#include "DynamicGameObject.h"

class Player : public DynamicGameObject
{
	enum player_properties { length = 10 }; 

public:
	Player();
	~Player() = default;

	bool CheckPathInDirection(const std::vector<std::string> scene) override;
	void MoveInDirection() override;

	int getLength() const { return length; }

	const char getBody(int pos) const { return (pos < length && pos >= 0) ? body[0][pos] : ' '; }
};

