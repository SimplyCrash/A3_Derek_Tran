/**************************************************
Project: RPG Monsters 2.0
Lab Num: Week 11
Author: Cheryl Howard / Matt Butler
Purpose: MONSTER Class Header
Foundations of C++
Lab 11 – Factories and Singletons :: Solutions
 **************************************************/
#ifndef MONSTERS_H
#define MONSTERS_H
#include <iostream>
#include <string>
using namespace std;
class Monster {
protected:
	Monster();
	Monster(string name, int health);
	static int numMonsters;
	string monName;
	int monHealth;
public:
	~Monster();
	// friends of this class
	friend class MonsterFactory;
	friend ostream& operator<<(ostream& os, const Monster& aMonster);
	// accessor methods
	static int getNumMonsters();
	string getName();
	int getHealth();
	// functions
	virtual string speak();
	virtual string attack();
	virtual void showDetails();
};
#endif

