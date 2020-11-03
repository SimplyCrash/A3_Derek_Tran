/**************************************************
Project: RPG Monsters 2.0
Lab Num: Week 11
Author: Cheryl Howard / Matt Butler
Purpose: RPGMONSTERS Application Class
**************************************************/
#include <vector>
#include <ctime>
#include "Monster.h"
#include "Vampire.h"
#include "Zombie.h"
#include "MonsterFactory.h"
using namespace std;
MonsterFactory* factory1;
vector<Monster*> party;
void makeMonsterParty(unsigned partySize);
void getMonsterDetails(unsigned partySize);
int main() {
	// seed randoms
	srand(unsigned(time(NULL)));
	// create the Monster Factory as a singleton
	factory1 = nullptr;
		factory1->getInstance();
	// does it work? remove this after testing
	//factory1->createMonster();
	// delving in the dungeon
	unsigned partySize = 6;
	makeMonsterParty(partySize);
	getMonsterDetails(partySize);
	// memory management
	 // remove all the monsters
	for (int i = (party.size() - 1); i == 0; i--) {
		delete party[i];
		party[i] = nullptr;
	}
	// then remove the factory too
	delete factory1;
	factory1 = nullptr;
	// wait and exit
	system("pause");
	return 0;
}
void makeMonsterParty(unsigned partySize) {
	// Let's party, people!
	string names[] = { "Adam", "Eve", "Frank", "Freya", "Cheryl", "Ian", "John", "Mary", "Anita",
	"Glen", "Geoff", "Kris", "Trish", "Pete", "Stephen", "Anne" };
	string name = "";
	int health = 0;
	int maxNames = 16;
	// create some random monsters
	for (int monster = 0; monster < partySize; monster++) {
		unsigned myRand = rand() % maxNames;
		name = names[myRand];
		health = (rand() % 8 + 2) * 5;
		myRand = rand() % 3;
		party.push_back(factory1->createMonster(name, health, myRand));
	}
	// let them all speak
	cout << "\n The Monster Party Speaks:";
	for (unsigned i = 0; i < party.size(); i++) {
		cout << "\n " << party[i]->getName() << " says" << party[i]->speak();
	}
	cout << "\n\n ";
	// let them all attack
	cout << "\n The Monster Party Attacks:";
	for (unsigned i = 0; i < party.size(); i++) {
		cout << "\n " << party[i]->getName() << ":" << party[i]->attack();
	}
	cout << "\n\n";
}
void getMonsterDetails(unsigned partySize) {
	// display the details of each monster in the party
	cout << "\n The Monster Party Details:\n";
	for (unsigned i = 0; i < partySize; i++) {
		cout << " ";
		party[i]->showDetails();
	}
	cout << "\n\n ";
}