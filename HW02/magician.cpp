#include "magician.h"
#include "Monster.h"
#include <iostream>

Magician::Magician(std::string nickname) : Player(nickname) {
	job_name = "법사";
	std::cout << "* 법사로 전직하였습니다." << std::endl;
	MP = 80;
}

void Magician::attack() {
	std::cout << nickname << "이(가) 마법을 시전한다!" << std::endl;
}

void Magician::attack(Monster* monster) {
	int damage = power - monster->getDefence();
	if (damage <= 0) damage = 1;

	std::cout << "* " << monster->getName() << "에게 마법으로 "
		<< damage << "의 피해를 입혔다!" << std::endl;

	monster->setHP(monster->getHP() - damage);

	if (monster->getHP() > 0) {
		std::cout << "* " << monster->getName()
			<< "의 남은 HP: " << monster->getHP() << std::endl;
	}
	else {
		std::cout << "* " << monster->getName()
			<< "을(를) 처치했습니다! 승리!" << std::endl;
	}
}