#include <iostream>
#include <cstdlib> // srand()
#include <ctime> // time()
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "MurderGame.h"
#pragma once

using namespace std;
using std::vector;


using std::cin;
using std::cout;
using std::endl;

int main() {
	srand(time(NULL));

	// Construct and begin game
	MurderGame game;
    game.displayDescription();
    game.displayTitle();
    game.displayRules();
    
    game.initialiseGame();
    /*
    Intialise game will set up the game world.
    It will also ask if the player wants to play from where they left off 
    by checking if a textfile 'savedProgress.txt'.
    If yes, it will set up the game world accordingly. (if time permits)
    If no, it will ask for name.
    */
	//game.startGame();
    /*
    Plays game
    */


	// Give player the option to play again (needs changing)
	int repeatChoice = 0;

    /*
	do {
		game.repeatMenu();
		repeatChoice = game.intValidation(1,2);

		switch(repeatChoice) {
			case 1: {
				Game repeatGame;
				repeatGame.startGame();
				break;
			}
			case 2:
				break;
			default:
				break;
		}
	} while (repeatChoice != 2);
    */

    game.pause();

	return 0; // Calls destructure
}