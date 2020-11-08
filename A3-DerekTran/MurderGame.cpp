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

int MurderGame::returnLocationIndex(string element) {
	int index = 0;
	while (index < locationVector.size()) {
		if (locationVector[index]->getLocationName() == element) {
			break;
		}
			index++;
	}
	
	if (index + 1 == locationVector.size()) {
		cout << "Element doesnt exist"; //LOCATION DOESNT EXIST
	}

	return index;
}

int MurderGame::returnSuspectIndex(string element) {
	int index = 0;
	while (index < suspectVector.size()) {
		if (suspectVector[index]->getSuspect() == element) {
			break;
		}
		index++;
	}

	if (index + 1 == suspectVector.size()) {
		cout << "Element doesnt exist"; //LOCATION DOESNT EXIST
	}

	return index;
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
			line += char(toupper(character[i]));
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
	ifstream fileToRead("itemList.txt");
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
			read += char(toupper(character[i]));
		}
	}

} 

void MurderGame::createLocationList() {
	//Instance Variables
	ifstream fileToRead("locationList.txt");
	string character = "";
	string read = "";

	//Opening File and storing the information within variable quotesTemp
	if (fileToRead.is_open()) {
		getline(fileToRead, character);
	}
	fileToRead.close();

	//Storing the information from quotesTemp into the vector quotes
	for (int i = 0; i < character.length(); i++) {
		if (character[i] == ':') {
			locationNamesList.push_back(read);
			read = "";
		}
		else if (character[i] == ';') {
			locationDescriptionList.push_back(read);
			read = "";
		}
		else {
			read += char(toupper(character[i]));
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
	createLocationList();
	locationVector = {};

	for (int i = 0; i < locationNamesList.size(); ++i) {
		locationVector.push_back(new Location(locationNamesList[i], locationDescriptionList[i]));
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

	//Initialise alibi for murderer
	int random = 0;
	do
	{
		random = rand() % 7;
		
	} while (random = 1);

	suspectVector[1]->setSuspectAlibi(suspectVector[random]->getSuspect());
	

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
	cout << "\n";
	for (int i = 0; i < locationNamesList.size(); ++i) {
		cout << locationNamesList[i] << "\n";
		locationVector[i]->debugPrintSuspects();
	}

	cout << "\n";
	for (int i = 0; i < locationNamesList.size(); ++i) {
		cout << locationNamesList[i] << "\n";
		locationVector[i]->debugPrintItems();
	}
	
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
	locationIndex = locationMurderNum;
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
			locationIndex = returnLocationIndex(userInputVector[1]);
			if (locationIndex >= locationVector.size()) {
				cout << "Wrong Parameters";
			}
			else {
				currentLocation = locationVector[locationIndex]->getLocationName();

				system("CLS");
				cout << border << "\n";
				cout << "At the crime scene" << "\n"; //CHANGE LATER IF STATEMENT TO CHECK IF ACUTAL CRIME SCENE
				cout << border << "\n";
				cout << "You are currently in the " << currentLocation << "\n";
				cout << locationVector[locationIndex]->getLocationDescription();
			}

		}

		else if (userInputVector[0] == "SEARCH") {
			system("CLS");
			cout << border << "\n";
			cout << "Investigating crime scene" << "\n";
			cout << border << "\n";

			if (locationVector[locationIndex]->getItems().empty() && locationVector[locationIndex]->getSuspects().empty()) {
				cout << "\nThere are no other entities in this room";
			}
			else {
				for (int i = 0; i < locationVector[locationIndex]->getItems().size(); i++) {
					cout << "\nThere seems to be a " << locationVector[locationIndex]->printItem(i) << " in the room";
					cout << "Item Check";
				}


				for (int i = 0; i < locationVector[locationIndex]->getSuspects().size(); i++) {
					cout << "\n" << locationVector[locationIndex]->printSuspect(i) << " is standing in the room.";
					cout << "Suspect Check";
				}
			}
			cout << "Outside If";
		}

		else if (userInputVector[0] == "EXAMINE") {
			system("CLS");
			cout << border << "\n";
			cout << "Examining Item" << "\n";
			cout << border << "\n";
			if (locationVector[locationIndex]->getItems().empty()) {
				cout << "\nThere are no items to EXAMINE";
			}
			else {
				for (int i = 0; i < locationVector[locationIndex]->getItems().size(); i++) {
					locationVector[locationIndex]->printItem(i); //NEED TO CHANGE TO DESCRIPTION ONLY
				}
			}

		}

		else if (userInputVector[0] == "GET") {
			itemIndex = returnLocationIndex(userInputVector[1]);
			if (itemIndex >= locationVector.size()) {
				cout << "Wrong Parameters";
			}
			else {
				//locationVector[locationIndex]->removeItems(itemVector[itemIndex]); //Removes item from location
				//p1.addInventory(itemVector[itemIndex]); //FIX PLAYER INSTANCE //Adds item to inventory
			}
		}

		else if (userInputVector[0] == "DROP") {
			itemIndex = returnLocationIndex(userInputVector[1]);
			if (itemIndex >= locationVector.size()) {
				cout << "Wrong Parameters";
			}
			else {
				//locationVector[locationIndex]->addItems(itemVector[itemIndex]); //Adds item to location
				//p1->removeInventory(itemVector[itemIndex]); //Removes item from inventory
			}
			
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

			suspectIndex = returnSuspectIndex(userInputVector[1]);
			
			cout << border << "\n";
			cout << "Questioning suspect" << "\n";
			cout << border << "\n";
			alibiVector.push_back(suspectVector[suspectIndex]->getAlibi()) ; //NEED CHECK IF THEY QUESTION TWICE
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