// Author: Eric Guerra
// Date: 2025-02-12
// Version: 0.1
// Description: A simple program that allows the user to organize and manage their daily tasks in their terminal.

// Includes necessary libraries for the program to run.
// List of program functions or "features" for the sake of easy navigation, readability, and organization.
#include "features.hpp"

int main()
{
    checkUserFile();
    mainMenu();
    simpleTasksMenu();
}