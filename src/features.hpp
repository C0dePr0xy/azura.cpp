// File: features.hpp
// This file is used to store all the program functions or "features" for the sake of easy navigation, readability, and organization.

#include <iostream>
#include <fstream>
#include <string>

// Include the program classes header file.
#include ".programClasses.hpp"

userAgentManager user;

void loginSystem(), mainMenu(), registerSystem(), checkUserFile(), simpleTasksMenu(), runtimeAgent();

void checkUserFile() {
    std::ifstream userFile(".user.dll");
    if (!userFile) {
        std::ofstream userFile(".user.dll");
    } else {
        userFile.close();
    }
}

void mainMenu()
{
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

void loginSystem()
{
    std::string username, password;

    std::cout << "[User Login]" << "\n\n";
    std::cout << "[Enter your username]: ";
    std::cin >> username;
    std::cout << "[Enter your password]: ";
    std::cin >> password;

    std::ifstream userFile(".user.dll");
    std::getline(userFile, user.username);
    std::getline(userFile, user.password);
    userFile.close();
    if (username == user.username && password == user.password) {
        std::cout << "Login successful!" << "\n";
        runtimeAgent();
        simpleTasksMenu();
    } else {
        std::cout << "Invalid username or password. Please try again." << "\n";
        runtimeAgent();
        loginSystem();
    }
}

void registerSystem()
{
    std::cout << "[New User Registration]" << "\n\n";
    std::cout << "[Enter a username]: ";
    std::cin >> user.username;
    std::cout << "[Enter a password]: ";
    std::cin >> user.password;

    std::ofstream userFile(".user.dll");
    userFile << "[USERNAME]:\n" << user.username << "\n";
    userFile << "[PASSWORD]:\n" << user.password << "\n";
    userFile.close();
    simpleTasksMenu();
}

void simpleTasksMenu()
{
    runtimeAgent();
    taskManagerAgent taskManager;
    
    std::cout << "Simple Tasks v0.1\n\n";
    std::cout << "Wecome, " << user.username << "!" << "\n\n";

    taskManager.about();
}

// Checks system OS and clear the terminal screen.
void runtimeAgent()
{
    if (_WIN32) {
        system("cls");
    } else {
        system("clear");
    }
}