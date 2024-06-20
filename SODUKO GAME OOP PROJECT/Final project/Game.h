#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

// Function to set text color in the console
int colors(int a);

// Function to make a sound when the user makes a mistake
void mistakeSound();

// Sub-function for setting the cursor position in the console
void gotoxy(int x, int y);

// Function to display a loading screen with a visual effect
void loadingScreenDelayed();

// Input validation for the choice of difficulty levels
int inputValidation(int &number);

// Validation for row, column, and corresponding number input
void Validation(int &row, int &column, int &number);

// Abstract Game class
class Game
{
private:
    int matrix[9][9]; // Sudoku matrix

protected:
    int mistakes; // Number of mistakes made by the player

public:
    // Constructor
    Game();

    // Set the number of mistakes
    void setMistakes(int);

    // Get the number of mistakes
    int getMistakes();

    // Read the matrix from a file
    void readFromFile(ifstream &);

    // Display the welcome screen
    void Welcome();

    // Display the Sudoku matrix
    void displaySuduko();

    // Check if the game is complete
    bool isComplete();

    // Check if a number can be placed in a row
    bool checkRow(int, int);

    // Check if a number can be placed in a column
    bool checkColumn(int, int);

    // Check if a number can be placed in a 3x3 grid
    bool checkGrid(int, int, int);

    // Place a number in the matrix
    void placeNumber(int, int, int);

    // Display the elapsed time since the start of the game
    int displayElapsedTime(time_t);

    // Pure virtual function to play the game
    virtual void playGame() = 0;

    // Destructor
    virtual ~Game();
};

// Function to set text color in the console
int colors(int a)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    return SetConsoleTextAttribute(h, a);
}

// Function to make a sound when the user makes a mistake
void mistakeSound()
{
    DWORD frequency = 1000; // Frequency of the sound in Hertz (Hz)
    DWORD duration = 700;   // Duration of the sound in milliseconds (ms)

    // Generate the sound
    Beep(frequency, duration);
    Sleep(50);
    Beep(frequency, duration);
}

// Input validation for the choice of difficulty levels
int inputValidation(int &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number < 0 || (number != 1 && number != 2 && number != 3))
            {
                cout << "Enter a valid number: ";
            }
            else
            {
                validInput = true;
            }
        }
        else
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Invalid input. Please enter a valid number: ";
        }
    }
    return number;
}

// Sub-function for setting the cursor position in the console
void gotoxy(int x, int y)
{
    COORD d;
    d.X = x;
    d.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
}

// Validation for row, column, and corresponding number input
void Validation(int &row, int &column, int &number)
{
    bool validInput = false;

    while (!validInput)
    {
        if (!(cin >> row) || row < 0 || row > 9)
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Invalid input. ";
            continue;
        }
        if (!(cin >> column) || column < 0 || column > 9)
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Invalid input. ";
            continue;
        }
        if (!(cin >> number) || number < 0 || number > 9)
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Invalid input. ";
            continue;
        }

        validInput = true;
    }
}

// Function to display a loading screen with a visual effect
void loadingScreenDelayed()
{
    system("CLS");
    system("COLOR 0A");
    char a = 219; // Character to display loading bar
    gotoxy(30, 10);
    cout << "[HOLD ON]" << endl;
    gotoxy(25, 12);
    for (int r = 1; r <= 20; r++)
    {
        for (int q = 0; q <= 10000000; q++) // Reduced the delay by a factor of 10
            ;
        cout << a;
    }
    cout << "\n\n\n\n\n\n\n";
}

#endif
