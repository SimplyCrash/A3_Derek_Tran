/**************************************************
Project: RPG Monsters 2.0
Lab Num: Week 11
Author: Cheryl Howard / Matt Butler
Purpose: MONSTER Class File
**************************************************/
#include "Monster.h"
int Monster::numMonsters = 0;
Monster::Monster() {}
Monster::Monster(string name, int health) {
	monName = name;
	monHealth = health;
	numMonsters++;
}
Monster::~Monster() { numMonsters--; }
// accessor functions
int Monster::getNumMonsters() { return numMonsters; }
int Monster::getHealth() { return monHealth; }
string Monster::getName() { return monName; }
// class functions
string Monster::speak() { return " Rooooaaaaar"; }
string Monster::attack() { return " Noooo! Don't hurt me ... I'm your friend!"; }
ostream& operator<<(ostream& os, const Monster& aMonster) {
	os << "Name: " << aMonster.monName << "\tHealth: " << aMonster.monHealth << "\tType: Monster";
	return os;
}
void Monster::showDetails() { cout << *this << endl; }
