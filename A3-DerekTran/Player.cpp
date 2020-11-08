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
vector<Item*> Player::getInventory() {
	return playerInventory;
}
int Player::getTurn() {return playerTurn;};
int Player::getScore() {return playerScore;};

void Player::addInventory(Item* item) {
	playerInventory.push_back(item);
};
void Player::removeInventory(Item* item) {
    vector<Item*> newList = {};
    for (int i = 0; i < playerInventory.size(); i++)
        if (playerInventory[i] != item) {
            newList.push_back(item);
        }
    playerInventory = newList;
};
void Player::updateTurn() {};
void Player::updateScore(int newScore) {};
void Player::resetScore(int score) {};

string Player::printInventory() {
	string inventory = "";
	for (int i = 0; i < playerInventory.size(); i++) {
		string newLine = "\n";
		inventory += playerInventory[i]->getItem() + newLine;
	}
	return inventory;
}

