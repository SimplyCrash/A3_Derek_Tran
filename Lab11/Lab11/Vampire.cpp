/**************************************************
Project: RPG Monsters 2.0
Lab Num: Week 11
Author: Cheryl Howard / Matt Butler
Purpose: VAMPIRE Class File
**************************************************/
#include "Vampire.h"
int Vampire::numVampires = 0;
Vampire::Vampire(string name, int health) : Monster(name, health) { numVampires++; }
Vampire::~Vampire() { numVampires--; }
int Vampire::getNumVampires() { return numVampires; }
string Vampire::speak() { return " I want to suck your blood!"; }
string Vampire::attack() { return " The vampire is sucking your blood ..."; }
ostream& operator<<(ostream& os, const Vampire& aVampire) {
	os << "Name: " << aVampire.monName << "\tHealth: " << aVampire.monHealth;
	os << "\tType: Vampire";
	return os;
}
void Vampire::showDetails() { cout << *this << endl; }
