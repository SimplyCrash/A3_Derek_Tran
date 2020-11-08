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
	string getInventory();
	int getTurn();
	int getScore();
	//Mutator Functions
	void addInventory(Item);
	void removeInventory(Item);
	void updateTurn();
	void updateScore(int newScore);
	void resetScore(int score);
	//Extra functions
	void printInventory();

private:
	//Variables
	string playerName;
	vector<Item> playerInventory;
	int playerTurn;
	int playerScore;
};

