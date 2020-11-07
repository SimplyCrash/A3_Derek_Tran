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
	itemMurderNum = rand() % itemVector.size();
	itemVector[itemMurderNum]->setItemMurder(true);
	cout << itemVector[itemMurderNum]->printName();

	//Setting Random Location as Murder Scene
	locationMurderNum = rand() % locationVector.size();
	locationVector[locationMurderNum]->setLocationMurder(true);
	cout << locationVector[locationMurderNum]->printName();

	//Debug
	/*cout << "\n";
	for (int i = 0; i < locationList.size(); ++i) {
		cout << locationList[i] << "\n";
		locationVector[i]->printSuspects();
	}

	cout << "\n";
	for (int i = 0; i < locationList.size(); ++i) {
		cout << locationList[i] << "\n";
		locationVector[i]->printItems();
	}*/
	
	system("pause");
	//readList();
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
	cout << "You see everyone gathered around " << "'victim' dead on the floor" << "\n";
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

	do
	{
		string placeHolder = "";
		vector<string> userInputVector = {};

		userInputValue = askForString("What now?");

		for (int i = 0; i <= userInputValue.length(); i++) {
			if (userInputValue[i] == ' ' || userInputValue[i] == NULL) {
				userInputVector.push_back(placeHolder);
				placeHolder = "";
			}
			else {
				placeHolder += char(toupper(userInputValue[i]));
			}

		}

		if (userInputVector[0] == "GOTO") {
			currentLocation = userInputVector[1];

			system("CLS");
			cout << border << "\n";
			cout << "At the crime scene" << "\n";
			cout << border << "\n";
			cout << "You are currently in the " << currentLocation << "\n";
			//cout << Location description

		}

		else if(userInputVector[0] == "SEARCH"){
			system("CLS");
			cout << border << "\n";
			cout << "Investigating crime scene" << "\n";
			cout << border << "\n";
			//cout << Whos and what items are in the room
		}

		else if (userInputVector[0] == "EXAMINE") {
			system("CLS");
			cout << border << "\n";
			cout << "Examining Item" << "\n";
			cout << border << "\n";
			//cout << Item description
		}

		else if (userInputVector[0] == "GET") {
			//cout << Item gathered
			//PUT INTO IVENTORY VECTOR
		}

		else if (userInputVector[0] == "DROP") {
			//cout << Item dropped
			//REMOVE FROM IVENTORY VECTOR
		}

		else if (userInputVector[0] == "I" || userInputVector[0] == "INV") {
			system("CLS");
			cout << border << "\n";
			cout << "Inventory" << "\n";
			cout << border << "\n";
			//FOR LOOP TO DISPLAY IVENTORY VECTOR
		}

		else if (userInputVector[0] == "QUESTION") {
			system("CLS");
			cout << border << "\n";
			cout << "Questioning suspect" << "\n";
			cout << border << "\n";
			//DISPLAY SUSPECT ALIBI
			//AND STORE IN ARRAY
		}

		else if (userInputVector[0] == "G") {
			system("CLS");
			cout << border << "\n";
			cout << "Accusation stage" << "\n";
			cout << border << "\n";
			/*userInput = askForString("Are you sure?");
			if (userInput == "YES"){
				suspectAccusation = askForString("Who would you like to accuse?");
				itemAccusation = askForstring("What item did the murderer use?);
			}

			if (userInput == "NO"){
			break
			}*/
			
		}

		else if (userInputVector[0] == "R") {
			//OPEN SUSPECTNOTES ARRAY
		}

		else if (userInputVector[0] == "H") {
			system("CLS");
			readTextFile("murderMysteryRules.txt");
			pause();
		}

		else if (userInputVector[0] == "M") {
			system("CLS");
			readTextFile("mapLayout.txt");
			pause();
		}

		else if (userInputVector[0] == "QUIT") {
			program = false;
		}

	} while (program);
	
	
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