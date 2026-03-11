#include "warrior.h"
#include "Monster.h"
#include <iostream>

Warrior::Warrior(std::string nickname) : Player(nickname) {
	job_name = "전사";
	std::cout << "* 전사로 전직하였습니다." << std::endl;
	HP = 80;
}

void Warrior::attack() {
	std::cout << nickname << "이(가) 검을 휘두른다!" << std::endl;
}

void Warrior::attack(Monster* monster) {
	int damage = power - monster->getDefence();
	if (damage <= 0) damage = 1;

	std::cout << "* " << monster->getName() << "에게 검으로 "
		<< damage << "의 피해를 입혔다!" << std::endl;

	monster->setHP(monster->getHP() - damage);

	if (monster->getHP() > 0) {
		std::cout << "* " << monster->getName()
			<< "의 남은 HP: " << monster->getHP() << std::endl;
	}
	else {
		std::cout << "* " << monster->getName() << "을(를) 처치했습니다! 승리!" << std::endl;
	}
}