/**************************************************
 Project: A3-DerekTran
 Lab Num: Assignment 3
 Author: Derek Tran
 Purpose: Suspect Class
**************************************************/

#include "Suspect.h"

Suspect::Suspect() {
	suspectName = "John";
	suspectRole = "Innocent";
	suspectAlibi = "None";
	suspectMurderer = false;

}

Suspect::Suspect(string name, string role) {
	suspectName = name;
	suspectRole = role;
}

Suspect::~Suspect() {}

string Suspect::getSuspect() { return suspectName; }
string Suspect::getRole() { return suspectRole; }
string Suspect::getAlibi() { return suspectAlibi; }
bool Suspect::getIfMurder() { 
	return true;  
}

void Suspect::setSuspectRole(string item) { 
	suspectRole = item;
}
void Suspect::setSuspectAlibi(string suspect) {
	suspectAlibi = suspect;
}
void Suspect::ifMurder(bool murder) {
	suspectMurderer = murder;
}

string Suspect::printName() {
	return suspectName;
}

