#pragma once
#include "player.h"

class Monster;

class Archer : public Player {
public:
	Archer(std::string nickname);
	void attack() override;
	void attack(Monster* monster) override;
};
