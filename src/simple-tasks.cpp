// Author: Eric Guerra
// Date: 2025-02-12
// Version: 0.1
// Description: A simple program that allows the user to organize and manage their daily tasks in their terminal.
#include <iostream>
#include <string>
#include <cstdlib>

// Variable to store the user's choice (This can be used anywhere in the program).
int userChoice;

// Function designed to clear the terminal screen (used when building the program, checks OS when building). -- Windows, Linux, MacOS
void clear()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Function designed to display the main menu of Simple Tasks CLI.
void mainMenu()
{
    std::cout << "Simple Tasks [CLI]\n";
    std::cout << "[1] Create a Task\n";
    std::cout << "[2] Delete a Task\n";
    std::cout << "[3] Task List\n";
    std::cout << "[4] Exit\n";
    std::cout << "[5] About\n";
    std::cout << "Choice: ";
    std::cin >> userChoice;

    switch (userChoice)
    {
        case (1):
            clear();
            std::cout << "Task Created Successfully!\n";
            clear();
            break;
        case (2):
            clear();
            std::cout << "Task Deleted Successfully!\n";
            clear();
            break;
        case (3):
            clear();
            std::cout << "Task List\n";
            clear();
            break;
        case (4):
            clear();
            exit(0); // Closes the program. -- Windows, Linux, MacOS
            break;
        case (5):
            clear();            
            std::cout << "Simple Tasks [CLI]\n\n";
            std::cout << "[Source Code] " << "https://github.com/C0dePr0xy/simple-tasks" << "\n";
            std::cout << "[Author] Eric Guerra\n";
            std::cout << "[Build Date] " << __DATE__ << "\n";
            std::cout << "[Description] A simple daily task managment application for the terminal.\n\n";
            std::cout << "[Press any key to return to the main menu.]\n";
            std::cin.ignore();
            std::cin.get();
            clear();
            break;
        default:
            clear();
            std::cout << "Invalid Choice!\n";
            clear();
            break;
    }
}

int main()
{
    clear();
    while (true)
    {
        mainMenu();
    }
    return 0;
}