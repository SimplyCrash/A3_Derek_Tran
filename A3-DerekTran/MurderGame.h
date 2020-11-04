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
        vector<string> suspectList;
        vector<string> suspectNames;
        vector<Location> locationList;

    public:
        string askForString(string question);
        void readTextFile(string file);
        void createSuspectList();
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

