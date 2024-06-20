#ifndef HARD_H
#define HARD_H
#include <iostream>
#include "Game.h"
class Hard : public Game
{
public:
    // Constructor
    Hard() : Game() {}
    // Take filename and return file handle
    ifstream fileopen(const string &);
    // Taking input for the usrename
    string takingInput();
    // This is the pure virtual fucntion in the Game class and overridding this function
    // This function play the game
    void playGame();
};

#endif