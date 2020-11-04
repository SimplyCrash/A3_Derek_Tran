/**************************************************
 Project: A3-DerekTran
 Lab Num: Assignment 3
 Author: Derek Tran
 Purpose: Main Class 
**************************************************/

#include "MurderGame.h"



void MurderGame::pause() {
	cout << "\n\n";
	system("pause");
}

void MurderGame::readTextFile(string fileName) {
	ifstream fileToRead(fileName);

	if (fileToRead.is_open()) {
		string line = "";
		while (!fileToRead.eof()) {
			getline(fileToRead, line);
			cout << line << "\n";
		}
	}
	else {
		cout << "\n		File Not Found.";
	}
	fileToRead.close();

};

string MurderGame::askForString(string question) {
	string userInput = "";
	cout << "\n" + question;
	getline(cin, userInput);

	while (userInput.length() <= 0) {
		cout << "You didn't seem to enter anything please try again: ";
		getline(cin, userInput);
	}

	return userInput;
}

void MurderGame::createSuspectList() {
	//Instance Variables
	ifstream fileToRead("suspectNames.txt");
	string character = "";
	string line = "";
	int random;

	//Opening File and storing the information within variable quotesTemp
	if (fileToRead.is_open()) {
		getline(fileToRead, character);
	}
	fileToRead.close();

	//Storing the information from quotesTemp into the vector quotes
	for (int i = 0; i < character.length(); i++) {
		if (character[i] == ';') {
			suspectList.push_back(line);
			line = "";
		}
		else {
			line += character[i];
		}
	}

	//Chooses random 7 names
	for (int i = 0; i < suspectList.size() - 7; i++) {
		random = rand() % suspectList.size();
		suspectList[random].erase();
	}
	

	//Gets rid of the empty spaces left behind from .erase
	for (int i = 0; i < suspectList.size(); i++) {
		if (suspectList[i].empty()) {
		}
		else {
			suspectNames.push_back(suspectList[i]);
		}
	}

	//Shuffle suspectNames
	random_shuffle(suspectNames.begin(), suspectNames.end());

	/*Assignment
	Suspect victim(suspectNames[0], "victim");
	Suspect murderer(suspectNames[1], "murderer");
	Suspect alibiPair1_1(suspectNames[2], "alibiPair1_1");
	Suspect alibiPair1_2(suspectNames[3], "alibiPair1_2");
	Suspect alibiPair2_1(suspectNames[4], "alibiPair2_1");
	Suspect alibiPair2_2(suspectNames[5], "alibiPair2_2");
	Suspect suspect(suspectNames[6], "suspect");*/

}

void MurderGame::createItemList() {
	//Instance Variables
	ifstream fileToRead("itemDescription.txt");
	string character = "";
	string read = "";
	int count = 0;

	//Opening File and storing the information within variable quotesTemp
	if (fileToRead.is_open()) {
		getline(fileToRead, character);
	}
	fileToRead.close();

	//Storing the information from quotesTemp into the vector quotes
	for (int i = 0; i < character.length(); i++) {
		if (character[i] == '_') {
			itemNamesList.push_back(read);
			read = "";
			count = 0;
		}
		else if (character[i] == ';') {
			itemDescriptionList.push_back(read);
			read = "";
			count = 1;
		}
		else {
			read += character[i];
		}
	}

} 


void MurderGame::readList() {
	for (int i = 0; i < suspectNames.size(); i++) {
		cout << suspectNames[i] << "\n";
	}
}

void MurderGame::initialiseGame() {
	//Initialise Player name
	Player p1(askForString("Please enter your name:"));

	//Initialising list of Locations
	locationList = { "gym", "classroom_A", "classroom_B", "classroom_C", "classroom_D", "cafeteria", "boys_Bathroom", "girls_bathroom", "teachers_Lounge", "principals_Office", "storage", "janitors_Closet", "game_Room", "pool", "library", "club_Room" };
	locationVector = {};

	for (int i = 0; i < locationList.size(); ++i) {
		locationVector.push_back(new Location(locationList[i]));
	}
	
	//Initialising list of Suspects
	createSuspectList();
	suspectRoles = { "victim", "murderer", "alibiPair1_1", "alibiPair1_2", "alibiPair2_1", "alibiPair2_2", "suspect" };
	suspectVector = {};
	for (int i = 0; i < suspectNames.size(); ++i) {
		suspectVector.push_back(new Suspect(suspectNames[i], suspectRoles[i])); 
		
		int random = rand() % 16;
		locationVector[random]->addSuspect(suspectVector[i]);
	}

	//Initialising list of items
	itemVector = {};
	for (int i = 0; i < itemNamesList.size(); ++i) {
		itemVector.push_back(new Item(itemNamesList[i], itemDescriptionList[i]));

		int random = rand() % 16;
		locationVector[random]->addItem(itemVector[i]);
	}
	
	//Debug
	cout << "\n";
	for (int i = 0; i < locationList.size(); ++i) {
		cout << locationList[i] << "\n";
		locationVector[i]->printSuspects();
	}

	cout << "\n";
	for (int i = 0; i < locationList.size(); ++i) {
		cout << locationList[i] << "\n";
		locationVector[i]->printItems();
	}
	
	readList();
}

void MurderGame::displayDescription() {
	readTextFile("murderMysteryDescription.txt");
	pause();
}

void MurderGame::displayTitle() {
	system("CLS");
	readTextFile("murderMysteryTitle.txt");
	pause();
}

void MurderGame::displayRules() {
	system("CLS");
	readTextFile("murderMysteryRules.txt");
	initialiseGame();
	pause();
}