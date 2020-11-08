/**************************************************
 Project: A3-DerekTran
 Lab Num: Assignment 3
 Author: Derek Tran
 Purpose: Player Class
**************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Suspect.h"
#include "Item.h"
#include "Location.h"
#pragma once

using namespace std;
using std::vector;
#pragma once

class Player{
public:
	//Constructors
	Player();
	Player(string name);
	//Destructor
	//~Player();
	//Accessor Functions
	string getName();
	vector<Item*> getInventory();
	int getTurn();
	int getScore();
	//Mutator Functions
	void addInventory(Item* item);
	void removeInventory(Item* item);
	void updateTurn();
	void updateScore(int newScore);
	void resetScore(int score);
	//Extra functions
	string printInventory();

private:
	//Variables
	string playerName;
	vector<Item*> playerInventory;
	int playerTurn;
	int playerScore;
};

