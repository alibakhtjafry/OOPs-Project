#ifndef MEDIUM_H
#define MEDIUM_H
#include <iostream>
#include "Game.h"

// Derived form the game class and parent of that class
// Public inheritance
// Medium class starts
class Medium : public Game
{
public:
    // constructor
    Medium() : Game() {}
    // take string of file name and return file handle
    ifstream fileopen(const string &);
    // take input for the usrename
    string takingInput();
    // This is the pure virtual fucntion in the Game class and overridding this function
    // This function play the game
    void playGame();
};

#endif