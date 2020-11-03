/**************************************************
Project: RPG Monsters 2.0
Lab Num: Week 11
Author: Cheryl Howard / Matt Butler
Foundations of C++
Lab 11 – Factories and Singletons :: Solutions
 Purpose: VAMPIRE Class Header
**************************************************/
#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "Monster.h"
class Vampire : public Monster {
private:
	Vampire(string name, int health);
	static int numVampires;
public:
	~Vampire();
	// friends of this class
	friend class MonsterFactory;
	friend ostream& operator<<(ostream& os, const Vampire& aVampire);
	// accessor functions
	static int getNumVampires();
	// functions
	virtual string speak();
	virtual string attack();
	virtual void showDetails();
};
#endif
