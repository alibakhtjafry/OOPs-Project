/*NAME: Ali Bakht jafry& SUBHAN-UL-HAQ
ROLL# BCSF22M043,44
SEMESTER PROJECT (OBJECT ORIENTED PROGRAMMING)
Naming convention:
1st part of function name is small and the other part 1st alphabet capital
*/
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "Game.h"
#include "Game.cpp"
#include "Easy.h"
#include "Easy.cpp"
#include "Medium.h"
#include "Medium.cpp"
#include "Hard.h"
#include "Hard.cpp"

using namespace std;
// First welcome Screen
void Welcome();
// 2nd screen for choices
int window_2();
// This will read player record form file and display it
void findRecord();
// This window is for difficulty select
void window_3();
// This is the validation for the choices
int validationChoice(int &number);
// Main starts

// Main functionality

/*It will display appropriate screens after acording to user choice do the following
1- According to choice of the user make the approproiate pointer base class pointer to derived class
and call the function and game starts
2- Read data according to name of the name of the user and print its previous record
3- If the user chose to manual then it read file and display the content of the file
4- Exit the program
 */
int main()
{
    Welcome();

    bool mainMenu = true;
    while (mainMenu)
    {
        int x = window_2();
        if (x == 1)
        {
            bool playAgain = false;
            do
            {
                window_3();
                cout << "   " << "Enter your choice: ";

                int choice;
                inputValidation(choice);

                Game *sudoku = nullptr;
                switch (choice)
                {
                case 1:
                    system("CLS");
                    sudoku = new Easy();
                    sudoku->playGame();
                    break;
                case 2:
                    system("CLS");
                    sudoku = new Medium();
                    sudoku->playGame();
                    break;
                case 3:
                    system("CLS");
                    sudoku = new Hard();
                    sudoku->playGame();
                    break;
                }

                cout << "\n\nDo you want to challenge your mind with another difficulty level? (y/n)";
                char playAgain;
                playAgain = _getch();
                playAgain = (playAgain == 'y' || playAgain == 'Y');
                delete sudoku; // Free the allocated memory
            } while (playAgain);
        }
        else if (x == 2)
        {
            findRecord();
        }
        else if (x == 3)
        {
            system("cls");
            string data;
            ifstream fileread("howtoplay.txt");
            while (getline(fileread, data))
            {
                colors(3);
                cout << data << endl;
            }
            colors(7);
            fileread.close();
        }
        else if (x == 4)
        {
            break;
        }
        colors(6);
        cout << "   " << "\n\nDo you want to return to the main menu? (y/n)";
        colors(7);
        char menuChoice;
        do
        {
            menuChoice = _getch(); // Read a character without echoing it to the console

            if (menuChoice == 'Y' || menuChoice == 'y' || menuChoice == 'N' || menuChoice == 'n')
            {
                break;
            }
            else
            {
                cout << "\nInvalid input. Please enter 'y' or 'n'.\n";
            }
        } while (true);
        mainMenu = (menuChoice == 'y' || menuChoice == 'Y');
    }
    colors(6);
    cout << "\n\n\t\t\t*************************************************\n\n";
    colors(7);
    colors(3);
    cout << "\t\t\tT h a n k s  f o r  P l a y i n g  S U D O K U :)\n\n";
    colors(7);
    colors(6);
    cout << "\t\t\t*************************************************\n";
    colors(7);

    return 0;
}
// end of main
int window_2()
{
    int x;
    system("cls"); // Clear the console screen

    colors(14);
    cout << "\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    colors(7);
    colors(10);
    cout << "\n\t S     ";
    cout << "U     ";
    cout << "D     ";
    cout << "O     ";
    cout << "K     ";
    cout << "U\n";
    colors(7);
    colors(14);
    cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    colors(7);
    colors(3);
    cout << "\t|\t\t\t\t" << "|\n";
    colors(7);
    colors(3);
    cout << "\t|" << "     " << "1 - Select Difficulty\t|\n";
    colors(7);
    colors(3);
    cout << "\t|\t\t\t\t" << "|\n"
                             "\t|\t\t\t\t"
         << "|\n"
            "\t|\t\t\t\t"
         << "|\n";
    colors(7);
    colors(3);
    cout << "\t|" << "     " << "2 -  Player Record \t|\n";
    colors(7);
    colors(11);
    cout << "\t|\t\t\t\t" << "|\n"
                             "\t|\t\t\t\t"
         << "|\n"
            "\t|\t\t\t\t"
         << "|\n";
    colors(7);
    colors(3);
    cout << "\t|" << "     " << "3 -  How To Play \t\t|\n";
    colors(7);
    colors(3);
    cout << "\t|\t\t\t\t" << "|\n"
                             "\t|\t\t\t\t"
         << "|\n"
            "\t|\t\t\t\t"
         << "|\n";
    colors(7);
    colors(3);
    cout << "\t|" << "     " << "4 -  Exit \t\t|\n";
    colors(7);
    colors(3);
    cout << "\t|\t\t\t\t" << "|\n"
                             "\t|\t\t\t\t"
         << "|\n";
    colors(3);
    colors(14);
    cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    colors(7);

    colors(7);
    // x = _getch();
    validationChoice(x);
    return x;
}
void Welcome()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Clear the console
    system("CLS");

    // Display an ASCII art title for Sudoku with different colors for each character
    SetConsoleTextAttribute(hConsole, 4);
    cout << "  ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\t               SSS";
    SetConsoleTextAttribute(hConsole, 4);
    cout << " ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\tU   U  ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\tDDDD   ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\t OOO   ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\tK  K  ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\t U   U\n";

    SetConsoleTextAttribute(hConsole, 10);
    cout << " ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "\t              S";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "  ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "\tU   U  ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "\tD   D ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "\tO   O  ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "\tK k    ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "\t U   U\n";

    SetConsoleTextAttribute(hConsole, 12);
    cout << "  ";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t               SSS";
    SetConsoleTextAttribute(hConsole, 12);
    cout << " ";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\tU   U  ";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\tD   D ";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\tO   O  ";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\tKK    ";
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t U   U\n";

    SetConsoleTextAttribute(hConsole, 13);
    cout << "     ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << "\t                  S ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << " ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << "\tU   U ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << "\tD   D ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << "\tO   O  ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << "\tK K   ";
    SetConsoleTextAttribute(hConsole, 13);
    cout << "\t U   U\n";

    SetConsoleTextAttribute(hConsole, 9);
    cout << "  ";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "\t               SSS";
    SetConsoleTextAttribute(hConsole, 9);
    cout << " ";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "\t UUU   ";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "\tDDDD   ";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "\t OOO   ";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "\tK  K ";
    SetConsoleTextAttribute(hConsole, 9);
    cout << "\t  UUU\n";

    // Change color for the ornate frame
    SetConsoleTextAttribute(hConsole, 14); // Yellow

    // Elaborate ornate pattern using tilde characters (~) around the welcome message
    cout << "\t\t\t\t ~~~~~~~~~~~~~~~~~~~\n";
    SetConsoleTextAttribute(hConsole, 14); // Yellow
    cout << "\t\t\t\t~ ";
    SetConsoleTextAttribute(hConsole, 15); // White
    cout << "Welcome to Sudoku!";
    SetConsoleTextAttribute(hConsole, 14); // Yellow
    cout << " ~\n";
    cout << "\t\t\t\t ~~~~~~~~~~~~~~~~~~~\n"
         << endl;

    SetConsoleTextAttribute(hConsole, 7); // Reset to default white

    // Display instructions or further information
    SetConsoleTextAttribute(hConsole, 6);
    cout << "Get ready to challenge your mind!\n";
    cout << "Press any key to start the game...\n";
    SetConsoleTextAttribute(hConsole, 7); // Reset to default white
    _getch();
    // // Wait for the user to press a key
    // system("PAUSE");
}
void findRecord()
{
    system("cls");
    ifstream file("record.txt");
    if (!file)
    {
        cerr << "Error: Could not open the file!" << endl;
        return;
    }

    string name, otherDetails, searchName;
    cin.ignore();
    colors(2);
    cout << "   " << "Enter username to search: ";
    colors(7);
    getline(cin, searchName);

    bool recordFound = false;
    while (getline(file, name))
    {
        if (getline(file, otherDetails))
        {
            if (name == searchName)
            {
                colors(15);
                cout << "   \n"
                     << name << endl;
                cout << "   \n"
                     << otherDetails << endl;
                colors(7);
                recordFound = true;
            }
        }
    }

    if (!recordFound)
    {
        cout << "Record not found" << endl;
    }

    file.close();
}
void window_3()
{
    system("cls"); // Clear the console screen

    colors(14);
    cout << "\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    colors(7);
    colors(10);
    cout << "\n\t S     ";
    cout << "U     ";
    cout << "D     ";
    cout << "O     ";
    cout << "K     ";
    cout << "U\n";
    colors(7);
    colors(14);
    cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    colors(7);
    colors(11);
    cout << "\t|\t\t\t\t" << "|\n";
    colors(7);
    colors(12);
    cout << "\t|" << "    " << "Enter difficulty level\t|\n";
    colors(7);
    colors(11);
    cout << "\t|\t\t\t\t" << "|\n"
                             "\t|\t\t\t\t"
         << "|\n"
            "\t|\t\t\t\t"
         << "|\n";
    colors(7);
    colors(6);
    cout << "\t|" << "      " << "1-  Easy \t\t|\n";
    colors(7);
    colors(11);
    cout << "\t|\t\t\t\t" << "|\n"
                             "\t|\t\t\t\t"
         << "|\n"
            "\t|\t\t\t\t"
         << "|\n";
    colors(7);
    colors(1);
    cout << "\t|" << "      " << "2-  Medium \t\t|\n";
    colors(7);
    colors(11);
    cout << "\t|\t\t\t\t" << "|\n"
                             "\t|\t\t\t\t"
         << "|\n"
            "\t|\t\t\t\t"
         << "|\n";
    colors(7);
    colors(4);
    cout << "\t|" << "      " << "3-  Hard \t\t|\n";
    colors(7);
    colors(11);
    cout << "\t|\t\t\t\t" << "|\n"
                             "\t|\t\t\t\t"
         << "|\n"
            "\t|\t\t\t\t"
         << "|\n";
    colors(7);
    colors(14);
    cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    colors(7);
}
int validationChoice(int &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number < 0 || (number != 1 && number != 2 && number != 3 && number != 4))
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