#ifndef EASY_H
#define EASY_H
#include "Game.h"
#include <fstream>
#include <iostream>
#include <windows.h>

using namespace std;
// Easy IS-A level in Game
// It is derived form class Game which is the parent class of it
// Start of Easy class
class Easy : public Game
{
public:
    Easy() : Game() {}

    void setMistakes(int);

    int getMistakes();
    // Taking input for the usrename
    string takingInput();
    // Take filename and return file handle
    ifstream fileopen(const string &);
    // This is the pure virtual fucntion in the Game class and overridding this function
    // This function play the game
    void playGame();
};
#endif