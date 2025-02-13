// File: features.hpp
// This file is used to store all the program functions or "features" for the sake of easy navigation, readability, and organization.
// I really love functions, they make my life so much easier.


// Includes necessary libraries for the functions to run.
#include <iostream>
#include <fstream>
#include <string>

// Include the program classes header file.
#include ".programClasses.hpp"

// Class objects used in the functions.
userAgentManager user;

// Functions will be declared in line 18 and defined in lines 22-55.
// These functions exist here for easy maintenance.
void loginSystem(), mainMenu(), registerSystem(), checkUserFile(), simpleTasksMenu(), runtimeAgent();

// Checks if the user file exists, if not, create it.
// This function exists for the sake of easy maitnance and organization.
void checkUserFile() {
    std::ifstream userFile(".user.dll");
    if (!userFile) {
        std::ofstream userFile(".user.dll");
    } else {
        userFile.close();
    }
}

// Initializes the startup menu.
// This function should only be called when the program starts.
// It allows the user to login, register, or exit the program, simple.
void mainMenu()
{
    checkUserFile();
    runtimeAgent();
    std::cout << "Simple Tasks v0.1" << "\n\n";
    std::cout << "Please select an option from the menu below:" << "\n\n";
    std::cout << "[1] Login" << "\n";
    std::cout << "[2] Register" << "\n";
    std::cout << "[3] Exit" << "\n\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            runtimeAgent();
            loginSystem();
            break;
        case 2:
            runtimeAgent();
            registerSystem();
            break;
        case 3:
            exit(0);
            break;
        default:
            std::cout << "Invalid choice. Please try again." << "\n";
            runtimeAgent();
            mainMenu();
            break;
    }
}

// Initializes the user login system.
void loginSystem()
{
    std::cout << "[User Login]" << "\n\n";
    std::cout << "[Enter your username]: ";
    std::cin >> user.username;
    std::cout << "[Enter your password]: ";
    std::cin >> user.password;

    std::ifstream userFile(".user.dll");
    std::getline(userFile, user.username);
    std::getline(userFile, user.password);
    userFile.close();
    if (user.username == user.username && user.password == user.password) {
        std::cout << "Login successful!" << "\n";
        runtimeAgent();
        simpleTasksMenu();
    } else {
        std::cout << "Invalid username or password. Please try again." << "\n";
        runtimeAgent();
        loginSystem();
    }
}

// Initializes the user registration system.
void registerSystem()
{
    std::cout << "[New User Registration]" << "\n\n";
    std::cout << "[Enter a username]: ";
    std::cin >> user.username;
    std::cout << "[Enter a password]: ";
    std::cin >> user.password;

    std::ofstream userFile(".user.dll");
    userFile << "[USERNAME]: " << user.username << "\n";
    userFile << "[PASSWORD]: " << user.password << "\n";
    userFile.close();
    simpleTasksMenu();
}

// Simple Tasks v0.1
// Initializes the main program.
void simpleTasksMenu()
{
    runtimeAgent();
    taskManagerAgent taskManager;
    
    std::cout << "Simple Tasks v0.1\n\n";

    taskManager.about();
}

// Checks system OS and clear the terminal screen (Supports macOS, Linux, and Windows).
// This function allows the program to function as intented on the client side.
// This function is called every time the terminal needs to be cleared, it makes my life a little bit easier.
void runtimeAgent()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}