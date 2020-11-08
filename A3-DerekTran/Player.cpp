/**************************************************
 Project: A3-DerekTran
 Lab Num: Assignment 3
 Author: Derek Tran
 Purpose: Player Class
**************************************************/

#include "Player.h"

Player::Player() {
	playerName = "Undefined";
	playerTurn = 0;
	playerScore = 0;
	playerInventory = {};
}

Player::Player(string name) {
	playerName = name;
};

string Player::getName() {return playerName;};
string Player::getInventory() {
	string inventory = "";
	for (int i = 0; i < playerInventory.size(); i++){
		string newLine = "\n";
		inventory += playerInventory[i]->getItem() + newLine;
		}
	return inventory;
	}
int Player::getTurn() {return playerTurn;};
int Player::getScore() {return playerScore;};

void Player::addInventory(Item* item) {
	playerInventory.push_back(item);
};
void Player::removeInventory(Item* item) {
	vector<Item*> newList = {};
	for (int i = 0; i < playerInventory.size(); i++)
		if (locationItems[i] != item) {
			newList.push_back(item);
		}
	playerInventory = newList;
};
void Player::updateTurn() {};
void Player::updateScore(int newScore) {};
void Player::resetScore(int score) {};

void Player::printInventory() {
	for (int i = 0; i < playerInventory.size(); i++) {

	}
}
