/**************************************************
 Project: A3-DerekTran
 Lab Num: Assignment 3
 Author: Derek Tran
 Purpose: Item Class
**************************************************/

#include "Item.h"

Item::Item() {
	itemName = "Item";
	itemCondition = "Clean";
	itemDescription = "N/A";
	itemMurder = true;
	// Debug
	output = "";
}

Item::Item(string name, string description) {
	itemName = name;
	itemDescription = description;
}

string Item::getItem() {
	return itemName;
}
string Item::getItemCondition() {
	return itemCondition;
}
bool Item::getItemMurder() {
	return itemMurder;
}

void Item::setItemCondition(string item) {
	itemCondition = item;
}
void Item::setItemMurder(bool murder) {
	itemMurder = murder;
}

string Item::printName() {
	output = itemName + ":" + itemDescription;
	return output;
};