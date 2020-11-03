/**************************************************
Project: RPG Monsters 2.0
Lab Num: Week 11
Author: Cheryl Howard / Matt Butler
Purpose: ZOMBIE Class file
**************************************************/
#include "Zombie.h"
int Zombie::numZombies = 0;
Zombie::Zombie(string name, int health) : Monster(name, health) { numZombies++; }
Zombie::~Zombie() { numZombies--; }
int Zombie::getNumZombies() { return numZombies; }
string Zombie::speak() { return " Braaaaaaaains"; }
string Zombie::attack() { return " The zombie is eating your brains!!!"; }
ostream& operator<<(ostream& os, const Zombie& aZombie) {
	os << "Name: " << aZombie.monName << "\tHealth: " << aZombie.monHealth;
	os << "\tType: Zombie";
	return os;
}
void Zombie::showDetails() { cout << *this << endl; }
