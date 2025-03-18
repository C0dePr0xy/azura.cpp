// Author: Eric Guerra
// Date: 2025-02-12
// Version: 0.1
// Description: A simple program that allows the user to organize and manage their daily tasks in their terminal.
#include <iostream>
#include <string>

int userChoice;

// Function designed to check the OS while building the program. -- Windows, Linux, MacOS
void checkSystemOS()
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
    checkSystemOS();
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
            checkSystemOS();
            std::cout << "Task Created Successfully!\n";
            checkSystemOS();
            break;
        case (2):
            checkSystemOS();
            std::cout << "Task Deleted Successfully!\n";
            break;
        case (3):
            checkSystemOS();
            std::cout << "Task List\n";
            checkSystemOS();
            break;
        case (4):
            checkSystemOS();
            std::cout << "Exiting Simple Tasks CLI...\n";
            system("exit");
            break;
        case (5):
            checkSystemOS();            
            std::cout << "Simple Tasks [CLI]\n";
            std::cout << "Source Code: " << "https://github.com/C0dePr0xy/simple-tasks" << "\n";
            std::cout << "Author: Eric Guerra\n";
            std::cout << "Version: 0.1\n";
            std::cout << "Description: A simple program that allows the user to organize and manage their daily tasks in their terminal interface.\n\n";
            std::cout << "[Press any key to return to the main menu.]\n";
            std::cin.ignore();
            std::cin.get();
            checkSystemOS();
            break;
        default:
            checkSystemOS();
            std::cout << "Invalid Choice!\n";
            checkSystemOS();
            break;
    }
}

int main()
{
    checkSystemOS();
    while (true)
    {
        mainMenu();
    }
    return 0;
}