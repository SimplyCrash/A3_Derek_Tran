#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
using std::vector;

int intValidation(int min, int max){
	int input;
	cin >> input;

	// Try again if input is out of range or fails
	while (input < min || input > max || cin.fail()) {
		cout << "Input must be an integer between " << min << " and "
		     << max << "." << endl;
		cout << "Please try again: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> input;
	}

	// Flush buffer after successful input
	cin.clear();
	cin.ignore(256, '\n');

	return input;
}

/*
int Game::intValidation(int min, int max) const {
	int input;
	cin >> input;

	// Try again if input is out of range or fails
	while (input < min || input > max || cin.fail()) {
		cout << "Input must be an integer between " << min << " and "
		     << max << "." << endl;
		cout << "Please try again: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> input;
	}

	// Flush buffer after successful input
	cin.clear();
	cin.ignore(256, '\n');

	return input;
}
*/
