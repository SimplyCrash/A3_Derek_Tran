/**************************************************
Project: RPG Monsters 2.0
Lab Num: Week 11
Author: Cheryl Howard / Matt Butler
Purpose: MONSTER FACTORY Class file
**************************************************/
#include "MonsterFactory.h"
MonsterFactory* MonsterFactory::instance = nullptr;
MonsterFactory* MonsterFactory::getInstance() {
	if (instance == nullptr) {
		instance = new MonsterFactory();
	}
	return instance;
}
Monster* MonsterFactory::createMonster(string name, int health, int num) {
	//cout << "Monster being generated" << endl;
	Monster* myMonster = nullptr;
	switch (num) {
	case 0:
		myMonster = new Monster(name, health);
		break;
	case 1:
		myMonster = new Vampire(name, health);
		break;
	case 2:
		myMonster = new Zombie(name, health);
		break;
	default:
		cout << "Something went wrong ... oops!\n\n";
	}
	return myMonster;
}
