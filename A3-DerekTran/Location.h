/**************************************************
 Project: A3-DerekTran
 Lab Num: Assignment 3
 Author: Derek Tran
 Purpose: Location Header
**************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <list>
#include "Suspect.h"
#include "Item.h"
#pragma once

using namespace std;
using std::vector;

class Location{
public:
	//Constructors
	Location();
	Location(string name);
	//Accessor Functions
	string getCondition();
	vector<Suspect*> getSuspects();
	vector<Item> getItems();
	bool getIfMurder();
	//Mutator Functions
	void addSuspect(Suspect* suspect);
	void removeSuspect(Suspect suspect);
	void addItem(Item item);
	void removeItem(Item item);
	void setLocationCondition(string condition);
	void setLocationSuspects(Suspect suspect);
	void setLocationItems(Item item);
	void setLocationMurder(bool murder);
	//EXTRA FUNCTIONS
	void printSuspects();

private:
	//Variables
	string locationName;
	string locationCondition;
	vector<Suspect*> locationSuspects;
	vector<Item> locationItems;
	bool locationMurder;
};

