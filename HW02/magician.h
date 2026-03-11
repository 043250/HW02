#pragma once
#include "player.h"

class Monster;

class Magician : public Player {
public:
	Magician(std::string nickname);
	void attack() override;
	void attack(Monster* monster) override;
};