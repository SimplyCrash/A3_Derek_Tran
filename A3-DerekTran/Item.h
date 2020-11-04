/**************************************************
 Project: A3-DerekTran
 Lab Num: Assignment 3
 Author: Derek Tran
 Purpose: Item Header
**************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#pragma once

using namespace std;
using std::vector;

class Item {
public:
	//Constructors
	Item();
	Item(string name, string description);
	//Destructor
	//~Item();
	//Accessor Functions
	string getItem();
	string getItemCondition();
	bool getItemMurder();
	//Mutator Functions
	void setItemCondition(string item);
	void setItemMurder(bool murder);
	//Extra Functions
	string Item::printName();
private:
	//Variables
	string itemName;
	string itemCondition;
	string itemDescription;
	bool itemMurder;
	//Debug
	string output;
};

