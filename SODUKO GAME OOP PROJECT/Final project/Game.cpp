#include <iostream>
#include <windows.h>
#include "Game.h"

// Constructor definition
Game::Game() : mistakes(0)
{
    // Initialize the Sudoku matrix with zeros
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            matrix[i][j] = 0;
        }
    }
    mistakes = 0; // Initialize mistakes to zero
}

// Set the number of mistakes
void Game::setMistakes(int x)
{
    mistakes = x;
}

// Get the number of mistakes
int Game::getMistakes()
{
    return mistakes;
}

// Read the Sudoku matrix from a file
void Game::readFromFile(ifstream &fileIn)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            fileIn >> matrix[i][j];
        }
    }
}

// Display the welcome screen with ASCII art and colors
void Game::Welcome()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Clear the console
    system("CLS");

    cout << "\n";
    // Display an ASCII art title for Sudoku with different colors for each character
    SetConsoleTextAttribute(hConsole, 11);
    cout << "\t\t  ";
    SetConsoleTextAttribute(hConsole, 11);
    cout << "SSS";
    SetConsoleTextAttribute(hConsole, 11);
    cout << "   ";
    SetConsoleTextAttribute(hConsole, 11);
    cout << "U   U  ";
    SetConsoleTextAttribute(hConsole, 11);
    cout << "DDDD   ";
    SetConsoleTextAttribute(hConsole, 11);
    cout << "OOO   ";
    SetConsoleTextAttribute(hConsole, 11);
    cout << "K  K  ";
    SetConsoleTextAttribute(hConsole, 11);
    cout << " U   U\n";

    SetConsoleTextAttribute(hConsole, 10);
    cout << "\t\t";
    SetConsoleTextAttribute(hConsole, 10);
    cout << " S";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "      ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "U   U  ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "D   D ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "O   O  ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "K k    ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "U   U\n";

    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t\t  ";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "SSS";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "   ";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "U   U  ";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "D   D ";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "O   O  ";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "KK    ";
    SetConsoleTextAttribute(hConsole, 12);
    cout << " U   U\n";

    SetConsoleTextAttribute(hConsole, 13);
    cout << "\t\t     ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << "S ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << " ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << "U   U ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << " D   D ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << "O   O  ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << "K K   ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << " U   U\n";

    SetConsoleTextAttribute(hConsole, 9);
    cout << "\t\t  ";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "SSS";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "   ";
    SetConsoleTextAttribute(hConsole, 9);
    cout << " UUU   ";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "DDDD   ";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "OOO   ";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "K  K ";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "   UUU\n";

    // Change color for the ornate frame
    SetConsoleTextAttribute(hConsole, 14); // Yellow
}

// Display the Sudoku matrix with colors
void Game::displaySuduko()
{
    Welcome(); // Display the welcome screen

    colors(4); // Set text color

    int a = 1;
    cout << "\n"
         << "       "
         << "COL#"
         << " ";
    cout << "    "
         << "1"
         << "     "
         << "2"
         << "     "
         << "3"
         << "      "
         << "4"
         << "     "
         << "5"
         << "     "
         << "6";
    cout << "      "
         << "7"
         << "     "
         << "8"
         << "     "
         << "9\n";
    colors(0);
    colors(3);

    cout
        << "              "
        << "_________________________________________________________\n"

        << "       ";
    colors(7);
    colors(4);
    cout << "ROW#\n";
    colors(7);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 0)
            {
                colors(4);

                cout << "\t" << a;
                colors(7);
                colors(4);
                cout << "    "
                     << "|";
                a++;
                colors(7);
            }
            colors(15);
            if (matrix[i][j] == 0)
            {
                cout << "  "
                     << "."
                     << "   ";
            }
            else
            {
                cout << "  " << matrix[i][j] << "   ";
            }
            colors(7);
            if (j == 8)
            {
                colors(3);

                cout << "|";
                colors(7);
            }
            // Print two spaces after every 3rd column (except the last column)
            if (j % 3 == 2 && j < 8)
            {
                colors(3);
                cout
                    << "|";
                colors(7);
            }
        }

        // Print two spaces after every 3rd row (except the last row)
        if (i % 3 == 2 && i < 8)
        {
            colors(2);

            cout << endl
                 << endl
                 << "             "
                 << "----------------------------------------------------------\n";
            colors(7);
        }
        cout << endl;
    }
    colors(15);

    cout << "             "
         << "__________________________________________________________\n\n";
    colors(7);
    colors(4);
    cout << "\t\t"
         << "Mistakes:"
         << " " << mistakes << " / 5 \t\t";
    colors(7);
}

// Check if the game is complete
bool Game::isComplete()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (matrix[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

// Check if a number can be placed in a row
bool Game::checkRow(int row, int num)
{
    for (int j = 0; j < 9; j++)
    {
        if (matrix[row][j] == num)
        {
            return false;
        }
    }
    return true;
}

// Check if a number can be placed in a column
bool Game::checkColumn(int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (matrix[i][col] == num)
        {
            return false;
        }
    }
    return true;
}

// Check if a number can be placed in a 3x3 grid
bool Game::checkGrid(int row, int col, int num)
{
    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (matrix[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

// Place a number in the matrix
void Game::placeNumber(int row, int col, int num)
{
    row--;
    col--; 
    // Adjust for 0-indexed array in implementation
    if (!checkRow(row, num))
    {
        cout << "Number already present in this row." << endl;
        mistakes++;
        mistakeSound();
        Sleep(600);
        system("cls");
        displaySuduko();
        return;
    }
    if (!checkColumn(col, num))
    {
        cout << "Number already present in this column." << endl;
        mistakes++;
        mistakeSound();
        system("cls");
        displaySuduko();
        return;
    }
    if (!checkGrid(row, col, num))
    {
        cout << "Number already present in this 3x3 grid." << endl;
        mistakes++;
        mistakeSound();
        system("cls");
        displaySuduko();
        return;
    }
    matrix[row][col] = num;
    system("cls");
    displaySuduko();
}

// Display the elapsed time since the start of the game
int Game::displayElapsedTime(time_t startTime)
{
    time_t currentTime = time(NULL);
    double elapsedSeconds = difftime(currentTime, startTime);
    return static_cast<int>(elapsedSeconds); // Return elapsed time in seconds
}

// Destructor
Game::~Game(){}
