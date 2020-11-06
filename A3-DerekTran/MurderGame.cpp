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
	/*for (int i = 0; i < suspectList.size() - 7; i++) {
		random = rand() % suspectList.size();
		suspectList[random].erase();
	}*/

	int count = 0;
	int check = 0;

	do
	{
		check++;
		count = 0;
		random = rand() % suspectList.size();
		suspectList[random].erase();

		for (int i = 0; i < suspectList.size(); i++) {
			if (!suspectList[i].empty()) {
				count++;
			}
		}
	} while (count > 7);

	cout << check;
	cout << suspectList.size();
	

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


}

void MurderGame::createItemList() {
	//Instance Variables
	ifstream fileToRead("itemDescription.txt");
	string character = "";
	string read = "";

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
		}
		else if (character[i] == ';') {
			itemDescriptionList.push_back(read);
			read = "";
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

	string test = "test";

	transform(test.begin(), test.end(), test.begin(), ::toupper);

	cout << test;

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

	//Initialise alibi pair 1
	suspectVector[2]->setSuspectAlibi(suspectVector[3]->getSuspect());
	suspectVector[3]->setSuspectAlibi(suspectVector[2]->getSuspect());

	//Initialise alibi pair 2
	suspectVector[4]->setSuspectAlibi(suspectVector[5]->getSuspect());
	suspectVector[5]->setSuspectAlibi(suspectVector[4]->getSuspect());

	//Initialising list of items
	createItemList();
	itemVector = {};
	for (int i = 0; i < itemNamesList.size(); ++i) {
		itemVector.push_back(new Item(itemNamesList[i], itemDescriptionList[i]));

		int random = rand() % 16;
		locationVector[random]->addItem(itemVector[i]);
	}

	//Setting murder scene
	//Setting Random Item as Murder Weapon
	int randomNumItem = rand() % itemVector.size();
	cout << randomNumItem;
	itemVector[randomNumItem]->setItemMurder(true);

	//Setting Random Location as Murder Scene
	int randomNumLocation = rand() % locationVector.size();
	cout << randomNumLocation;
	locationVector[randomNumLocation]->setLocationMurder(true);

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
	
	system("pause");
	readList();
}

void MurderGame::playGame() {
	string border = "*****************************************************************************************************************************************************";
	system("CLS");
	cout << border << "\n";
	cout << "You stand up and decided to get out of the classroom.";
	cin.get();
	cout << "While walking around the school, you start to hear commotion from a lit up room. Being the curious person you was you started you walk towards it." << "\n";
	cout << "You arrive at a room with 7 other people." << "\n";
	cout << "One person exclaims that they should go the principals office and get the master key to try and leave the school" << "\n";
	cout << "Everyone agrees and decides to go try and find the principals office. Everyone leaves and goes on their seperate paths" << "\n";
	cout << "You however still being awestruck by the situation you decided to stay behind and gather your thoughts" << "\n";
	cout << "Moments pass... Suddenly you hear a scream coming from "  << locationVector[locationMurderNum]->printName();
	cin.get();
	cout << "You decided to head towards the screaming" << "\n";
	cout << "You arive at " << locationVector[locationMurderNum]->printName() << "\n";
	cout << "You see everyone gathered around " << "'victim' dead on the floor";
	//Discussion on what happens cbf writing for now
	cout << "You all go your seperate ways to find the murderer among us";
	cin.get();
	
	system("CLS");
	cout << border << "\n";
	cout << "At the crime scene" << "\n";
	cout << border << "\n";
	cout << "You are currently in the " << locationVector[locationMurderNum]->printName() << "\n";
	//cout << Location Description
	//cout << "What now? " << userInput;
	//START THE GAME REPETITION
	
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
}