// File: features.hpp
// This file is used to store all the program functions or "features" for the sake of easy navigation, readability, and organization.

#include <iostream>
#include <fstream>
#include <string>

// Include the program classes header file.
#include ".programClasses.hpp"

userAgentManager user;

void loginSystem(), mainMenu(), registerSystem(), checkUserFile(), simpleTasksMenu(), uptimeSystem();

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
            loginSystem();
            break;
        case 2:
            registerSystem();
            break;
        case 3:
            std::cout << "Exiting program..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            mainMenu();
            break;
    }
    system("clear");
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
    if (!user.username.compare(username) && !user.password.compare(password)) {
        std::cout << "Login successful!" << "\n";
        system("clear") || system("cls");
    } else {
        std::cout << "Invalid username or password. Please try again." << "\n";
        system("clear") || system("cls");
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
}

void simpleTasksMenu()
{
    taskManagerAgent taskManager;
    
    std::cout << "Simple Tasks v0.1\n\n";
    std::cout << "Wecome, " << user.username << "!" << "\n\n";

    taskManager.about();
}