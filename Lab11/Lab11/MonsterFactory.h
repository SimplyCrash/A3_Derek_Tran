/**************************************************
Project: RPG Monsters 2.0
Lab Num: Week 11
Author: Cheryl Howard / Matt Butler
Purpose: MONSTER FACTORY Header file
**************************************************/
#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H
#include <iostream>
#include "Monster.h"
#include "Vampire.h"
#include "Zombie.h"

using namespace std;
class MonsterFactory {
public:
	static MonsterFactory* getInstance();
	Monster* createMonster(string name, int health, int num);
private:
	MonsterFactory() {}
	static MonsterFactory* instance;
};
#endif
