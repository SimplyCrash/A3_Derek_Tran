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

	//Assignment
	Suspect victim(suspectNames[1], "victim");
	Suspect murderer(suspectNames[2], "murderer");
	Suspect alibiPair1_1(suspectNames[3], "alibiPair1_1");
	Suspect alibiPair1_2(suspectNames[4], "alibiPair1_2");
	Suspect alibiPair2_1(suspectNames[5], "alibiPair2_1");
	Suspect alibiPair2_2(suspectNames[6], "alibiPair2_2");
	Suspect suspect(suspectNames[7], "suspect");

}

void MurderGame::createLocationList() {
	//Instance Variables
	ifstream fileToRead("locationList.txt");
	string character = "";
	string line = "";

	//Opening File and storing the information within variable quotesTemp
	if (fileToRead.is_open()) {
		getline(fileToRead, character);
	}
	fileToRead.close();

	//Storing the information from quotesTemp into the vector quotes
	for (int i = 0; i < character.length(); i++) {
		if (character[i] == ';') {
			locationList.push_back(line);
			line = "";
		}
		else {
			line += character[i];
		}
	}

} //COULD BE UNUSEFULL - DELETE

void MurderGame::readList() {
	for (int i = 0; i < suspectNames.size(); i++) {
		cout << suspectNames[i] << "\n";
	}
}

void MurderGame::initialiseGame() {
	Location gym = Location();
	Location classroomA = Location();
	Location classroomB = Location();
	Location classroomC = Location();
	Location classroomD = Location();
	Location cafeteria = Location();
	Location boys_Bathroom = Location();
	Location girls_Bathroom = Location();
	Location teachers_Lounge = Location();
	Location principals_Office = Location();
	Location storage = Location();
	Location janitors_closet = Location();
	Location game_room = Location();
	Location pool = Location();
	Location library = Location();
	Location clubRoom = Location();
	Player p1(askForString("Please enter your name:"));
	createSuspectList();
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