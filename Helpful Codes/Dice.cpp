#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
using std::vector;

class Dice {
public:
    Dice();
    int Roll();
    int currentDiceSide();

private:
    int diceRoll;
    int diceReRoll; //Declares and initializes the number of dice to allow for      roll next dice throw.
};

Dice::Dice()
    : //This is the beginning of the class and sets diceRoll to zero
    diceRoll(0)
{
}

int Dice::Roll()
{ //This function actually does the random roll within the class Dice.
    diceRoll = ((rand() % 6) + 1);
    return diceRoll;
}

int Dice::currentDiceSide()
{ //This function returns the value of the dice roll for the class call.
    return diceRoll;
}

void GetPlayerInput(int playerInput)
{
    cin >> playerInput;
}

int main() {
    int players;
    std::cout << "Please enter the number of players " << std::endl;
    std::cin >> players;

// do something to make sure players is an integer

// initialize the empty playerDice vector
    std::vector<Dice*> playerDice = {};

    for (int i = 0; i <= players; ++i) {
        playerDice.push_back(new Dice); // this adds a new Dice object pointer to the end of the vector
        playerDice.at(i)->Roll();
        std::cout << playerDice.at(i)->currentDiceSide();
    }
}