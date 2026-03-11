#include "archer.h"
#include "Monster.h"
#include <iostream>

Archer::Archer(std::string nickname) : Player(nickname) {
	job_name = "궁수";
	std::cout << "* 궁수로 전직하였습니다." << std::endl;
	accuracy = 80;
}

void Archer::attack() {
	std::cout << nickname << "이(가) 활을 쏜다!" << std::endl;
}

void Archer::attack(Monster* monster) {
	int damage = power - monster->getDefence();
	if (damage <= 0) damage = 1;

	int perShot = damage / 3;
	if (perShot <= 0) perShot = 1;

	for (int i = 0; i < 3; i++) {
		std::cout << "* " << monster->getName() << "에게 화살로 "
			<< perShot << "의 피해를 입혔다!" << std::endl;
		monster->setHP(monster->getHP() - perShot);

		if (monster->getHP() <= 0) {
			std::cout << "* " << monster->getName() << "을(를) 처치했습니다! 승리!" << std::endl;
			return;
		}
	}

	std::cout << "* " << monster->getName()
		<< "의 남은 HP: " << monster->getHP() << std::endl;
}