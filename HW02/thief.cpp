#include "thief.h"
#include "Monster.h"
#include <iostream>

Thief::Thief(std::string nickname) : Player(nickname) {
	job_name = "도적";
	std::cout << "* 도적으로 전직하였습니다." << std::endl;
	speed = 80;
}

void Thief::attack() {
	std::cout << nickname << "이(가) 단검을 휘두른다!" << std::endl;
}

void Thief::attack(Monster* monster) {
	int damage = power - monster->getDefence();
	if (damage <= 0) damage = 1;

	int perHit = damage / 5;
	if (perHit <= 0) perHit = 1;

	for (int i = 0; i < 5; i++) {
		std::cout << "* " << monster->getName() << "에게 단검으로 "
			<< perHit << "의 피해를 입혔다!" << std::endl;
		monster->setHP(monster->getHP() - perHit);

		if (monster->getHP() <= 0) {
			std::cout << "* " << monster->getName() << "을(를) 처치했습니다! 승리!" << std::endl;
			return;
		}
	}

	std::cout << "* " << monster->getName()
		<< "의 남은 HP: " << monster->getHP() << std::endl;
}