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

Location::Location(string name, string description) {
	locationName = name;
	locationDescription = description;
}

//ACCESSORS
string Location::getLocationName() {
	return locationName;
}
string Location::getCondition() { 
	return locationCondition; 
}
string Location::getLocationDescription() {
	return locationDescription;
}
vector<Suspect*> Location::getSuspects() { 
	return locationSuspects; 
}
vector<Item*> Location::getItems() { 
	return locationItems; 
}
bool Location::getIfMurder() { 
	return locationMurder; 
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
    vector<Item*> newList = {};
    for (int i = 0; i < locationItems.size(); i++) {
        cout << locationItems[i];
        if (locationItems[i] != item) {
            newList.push_back(item);
        }
    }
    locationItems = newList;
}
void Location::setLocationCondition(string condition) { 
	locationCondition = condition; 
}
void Location::setLocationDescription(string description) {
	locationDescription = description;
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
            // Uppercase first letter
            correctName += char(toupper(locationName[i]));
            check = 1;
        }
        else {
            if (locationName[i] == '_') {
                // Adds Space
                correctName += ' ';
                check = 0;}
            else {
                correctName += locationName[i];
            }
        }
    }
    return correctName;
}

void Location::debugPrintSuspects() {
	for (int i = 0; i < locationSuspects.size(); i++) {
		cout << locationSuspects[i]->printName() << "\n";
	}
}

void Location::debugPrintItems() {
	for (int i = 0; i < locationItems.size(); i++) {
		cout << locationItems[i]->printName() << ":" << locationItems[i]->printDescription() << "\n";
	}
}

string Location::printSuspect(int index) {
		return locationSuspects[index]->printName();
}

string Location::printItem(int index) {
		return locationItems[index]->printName();
}