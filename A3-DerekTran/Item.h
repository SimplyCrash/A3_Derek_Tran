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
	Item(string name);
	void setItemCondition(string item);
	void setItemMurder(bool murder);
	//Destructor
	//~Item();
	//Accessor Functions
	string getItem();
	string getItemCondition();
	bool getItemMurder();
	//Mutator Functions
private:
	//Variables
	string itemName;
	string itemCondition;
	bool itemMurder;
};

