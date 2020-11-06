/**************************************************
 Project: A3-DerekTran
 Lab Num: Assignment 3
 Author: Derek Tran
 Purpose: Location Class
**************************************************/

#include "Location.h"

//CONSTRUCTORS
Location::Location() {
	locationCondition = "Innocent";
	locationSuspects = {};
	locationItems = {};
}

Location::Location(string name) {
	locationName = name;
}

//ACCESSORS
string Location::getCondition() { 
	return locationCondition; 
}
vector<Suspect*> Location::getSuspects() { 
	return locationSuspects; 
}
vector<Item*> Location::getItems() { 
	return locationItems; 
}
bool getIfMurder() { 
	return true; 
}

//MUTATORS
void Location::addSuspect(Suspect* suspect) { 
	locationSuspects.push_back(suspect); 
}
void Location::removeSuspect(Suspect* suspect) { 
	//NEEDS REVIEW IN FUTURE
	//locationSuspects.erase(remove(locationSuspects.begin(), locationSuspects.end(), suspect), locationSuspects.end()); 
}
void Location::addItem(Item* item) { 
	locationItems.push_back(item); 
}
void Location::removeItem(Item* item) {
	//NEEDS REVIEW IN FUTURE
	//locationItems.erase(remove(locationItems.begin(), locationItems.end(), item), locationItems.end());
}
void Location::setLocationCondition(string condition) { 
	locationCondition = condition; 
}
void Location::setLocationMurder(bool murder) { 
	locationMurder = murder; 
}

//EXTRA FUNCTIONS
string Location::printName() {
	int check = 0;
	string correctName = "";
	for (int i = 0; i < locationName.length(); i++) {
		if (check == 0) {
			correctName[i] = toupper(locationName[i]);
			check = 1;
		}
		else if (locationName[i] == '_') {
			correctName[i] = ' ';
			check = 0;
		}
	}
	return correctName;
}

void Location::printSuspects() {
	for (int i = 0; i < locationSuspects.size(); i++) {
		cout << locationSuspects[i]->printName() << "\n";
	}
}

void Location::printItems() {
	for (int i = 0; i < locationItems.size(); i++) {
		cout << locationItems[i]->printName() << "\n";
	}
}