/**************************************************
 Project: A3-DerekTran
 Lab Num: Assignment 3
 Author: Derek Tran
 Purpose: Main Header
**************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "Suspect.h"
#include "Item.h"
#include "Player.h"
#include "Location.h"
#pragma once

using namespace std;
using std::vector;

class MurderGame{
    private:
        int locationMurderNum;
        int itemMurderNum;
        int locationIndex;
        int suspectIndex;
        int itemIndex;
        string playerName;
        string userInputValue;
        vector<string> alibiVector;
        vector<string>userInputVector;
        bool program;
        string currentLocation;

        vector<string> suspectList;
        vector<string> suspectNames;
        vector<string> suspectRoles;
        vector<Suspect*> suspectVector;

        vector<string> locationNamesList;
        vector<string> locationDescriptionList;
        vector<Location*> locationVector; //FUTURE PROBLEM WITH SCOPING

        vector<string> itemNamesList;
        vector<string> itemDescriptionList;
        vector<Item*> itemVector;



    public:
        string askForString(string question);
        void readTextFile(string file);
        int returnLocationIndex(string element);
        int returnSuspectIndex(string element);
        int returnItemIndex(int locationIndex, string element);
        void createSuspectList();
        void createItemList();
        void createLocationList();
        void readList();
        void pause();
        void displayDescription();
        void displayTitle();
        void displayRules();
        void initialiseGame();
        void playGame();
        void gameOver();
        void displayScore();
        void resetGame();
        void playerMovement(string userInput);
};

