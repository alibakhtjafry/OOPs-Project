#include <iostream>
#include <string>
#include "Medium.h"
using namespace std;
// Contain defination of all the fucntion of that class
/*
Contain all the defination of the fucntions
1- Setter and getters
2- File function that will take string and return the file handle
3- Take input for the username and return the string of that usrename
4- Take user name & user choice for level and then starts the game take input for row,col and number
then check all the checks for the validation of that number placing then place it and clear thes screen then
print matrix again if the user make more then 5 mistake then lost the game and usre have to play again that level
or slect level again if user complete the level then it write the record in a file
-> It also calculate time and display it also every time it make time null so that for each level
time calculate properly
*/

ifstream Medium::fileopen(const string &filename)
{
    ifstream fileread(filename);
    if (!fileread.is_open())
    {
        cout << "File couldn't be opened!!!" << endl;
    }
    return fileread;
}
string Medium::takingInput()
{
    string username;
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
    colors(10);
    cout << "\n\n\tEnter Name/UserName/ID: ";
    colors(7);
    getline(cin, username);
    return username;
}
void Medium::playGame()
{
    bool playAgain = false;
    char ch;
    cin.ignore();
    string userName = takingInput();
    loadingScreenDelayed();

    do
    {
        int choice;
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
        cout << "\t|" << "    " << "Select your level\t\t|\n";
        colors(7);
        colors(11);
        cout << "\t|\t\t\t\t" << "|\n"
                                 "\t|\t\t\t\t"
             << "|\n"
                "\t|\t\t\t\t"
             << "|\n";
        colors(7);
        colors(6);
        cout << "\t|" << "    " << "Level - 1 \t\t\t|\n";
        colors(7);
        colors(11);
        cout << "\t|\t\t\t\t" << "|\n"
                                 "\t|\t\t\t\t"
             << "|\n"
                "\t|\t\t\t\t"
             << "|\n";
        colors(7);
        colors(1);
        cout << "\t|" << "         " << "Level - 2  \t\t|\n";
        colors(7);
        colors(11);
        cout << "\t|\t\t\t\t" << "|\n"
                                 "\t|\t\t\t\t"
             << "|\n"
                "\t|\t\t\t\t"
             << "|\n";
        colors(7);
        colors(4);
        cout << "\t|" << "             " << " Level - 3 " << "    \t|\n";
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

        cout << "   " << "Enter your choice: ";
        inputValidation(choice);
        ifstream fileRead = fileopen("Medium.txt"); // this fucntion also calls the displayt function in it opens file and read it

        if (choice == 1)
        {
            readFromFile(fileRead);
            system("cls");
            loadingScreenDelayed();
            displaySuduko();
            bool check = false;
            time_t startTime = time(NULL);
            setMistakes(0);
            while (!isComplete())
            {
                int elapsedMinutes = displayElapsedTime(startTime);
                colors(4);
                cout << "    " << "Time: " << elapsedMinutes << "  Seconds" << endl
                     << endl;
                colors(7);

                int row, col, num;
                cout << "Enter row, column, and number to place (1-9 for row/col, e.g., 5 5 3): ";
                Validation(row, col, num);
                placeNumber(row, col, num);

                if (getMistakes() >= 5)
                {
                    colors(2);
                    cout << "\n\n\t\t\t!!!!!You lost the Game!!!!!" << endl;
                    colors(7);
                    check = true;
                    break;
                }

                Sleep(90);
            }
            // if the check is false then this condition works
            if (!check)
            {
                cout << "\n\nCongratulations! You completed Level 1. Ready for Level 2?" << endl;
                time_t level1EndTime = time(NULL);

                int level1Duration = level1EndTime - startTime;
                ofstream outFile("record.txt", ios::app);
                outFile << userName << endl
                        << "Level 1 Medium - Time: " << level1Duration << " seconds" << " - Mistakes " << mistakes << endl;
                outFile.close();

                cout << "Ready for level 2? If yes select it to start :) " << endl;
            }
        }
        if (choice == 2)
        {
            bool check2 = false;
            setMistakes(0);
            system("cls");
            loadingScreenDelayed();
            fileRead.seekg(171, ios_base::beg);
            readFromFile(fileRead);
            system("cls");
            displaySuduko();
            time_t startTime = time(NULL); // Reset start time for Level 2

            while (!isComplete())
            {
                int elapsedMinutes = displayElapsedTime(startTime);
                colors(4);
                cout << "    " << "Time: " << elapsedMinutes << " Seconds" << endl
                     << endl;
                colors(7);

                int row, col, num;
                cout << "Enter row, column, and number to place: ";
                Validation(row, col, num);
                placeNumber(row, col, num);

                if (getMistakes() >= 5)
                {
                    colors(2);
                    cout << "\n\n\t\t\t!!!!!You lost the Game!!!!!" << endl;
                    colors(7);
                    check2 = true;
                    break;
                }

                Sleep(100);
            }

            if (!check2)
            {
                cout << "\n\tCongratulations! :)  You completed Level 2. Ready for Level 3?" << endl;
                time_t level2EndTime = time(NULL);

                int level2Duration = level2EndTime - startTime;
                ofstream outFile("record.txt", ios::app);
                outFile << userName << endl
                        << "Level 2 Medium - Time: " << level2Duration << " seconds" << " - Mistakes " << mistakes << endl;
                outFile.close();
                colors(4);
                cout << "Ready for level 3? If yes select it to start :)  \n";
                colors(7);
            }
        }
        if (choice == 3)
        {
            setMistakes(0);
            bool check3 = false;
            fileRead.seekg(342, ios_base::beg);
            readFromFile(fileRead);
            system("cls");
            loadingScreenDelayed();
            system("cls");
            displaySuduko();
            time_t startTime = time(NULL);

            while (!isComplete())
            {
                int elapsedMinutes = displayElapsedTime(startTime);
                colors(4);
                cout << "    " << "Time: " << elapsedMinutes << " Minutes" << endl
                     << endl;
                colors(7);

                int row, col, num;
                cout << "Enter row, column, and number to place: ";
                Validation(row, col, num);
                placeNumber(row, col, num);

                if (getMistakes() >= 5)
                {
                    colors(2);
                    cout << "\n\n\t\t\t!!!!!You lost the Game!!!!!" << endl;
                    colors(7);
                    check3 = true;
                    break;
                }

                Sleep(100);
            }

            if (!check3)
            {
                cout << "*************************************" << endl;
                cout << "\n\tCongratulations! :) You completed Level 3. You completed all levels!" << endl;
                time_t level3EndTime = time(NULL);
                int level3Duration = level3EndTime - startTime;
                ofstream outFile("record.txt", ios::app);
                outFile << userName << endl
                        << "Level 3 Medium - Time: " << level3Duration << " seconds" << " - Mistakes " << mistakes << endl;
                outFile.close();
                fileRead.close();
            }
        }

        cout << "\nWant To Play Again?" << endl;
        do
        {
            ch = _getch(); // Read a character without echoing it to the console

            if (ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n')
            {
                break;
            }
            else
            {
                cout << "\nInvalid input. Please enter 'y' or 'n'.\n";
            }
        } while (true);

        if (ch == 'Y' || ch == 'y')
        {
            playAgain = true;
        }
        else if (ch == 'N' || ch == 'n')
        {
            playAgain = false;
        }
        setMistakes(0);

    } while (playAgain);
}