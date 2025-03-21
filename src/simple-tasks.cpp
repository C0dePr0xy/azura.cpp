// Author: Eric Guerra
// Date: 2025-02-12
// Version: 0.1
// Description: A simple program that allows the user to organize and manage their daily tasks in their terminal.
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <ctime>

// Variable to store the user's choice (This can be used anywhere in the program).
int userChoice;

// Variable to store a yes or no choice from the user (This is meant for confirmation prompts in important components of the program).
char userConfirmation;

// This class is designed to store task information. This class will be useful for maintaining this program and adding more features in the future. :)
class task
{
    public: // The following variables below puplic will throw warnings, but the program will still compile and run as intended.
        std::string taskName = "Untitled";
        std::string taskDescription = "No Description";
        std::string taskDate = auto taskDate = __DATE__;
        std::string taskTime = auto taskTime = __TIME__;
        std::string taskStatus = "Incomplete";
};

// Creates an object for use in the program from the task class.
task Task;

// This vector is designed to store task objects for listing in the task list.
std::vector<task> taskList;

// Function designed to clear the terminal screen (used when building the program, checks OS when building). -- Windows, Linux, MacOS
void clear()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Checks is task files exist in the program drirectory and accounts for them in the task list.
void taskScanner()
{
    std::ifstream taskFile;
    taskFile.open(Task.taskName + ".task");
    if (taskFile.is_open())
    {
        while (!taskFile.eof())
        {
            taskFile >> Task.taskName;
            taskFile >> Task.taskDescription;
            taskFile >> Task.taskDate;
            taskFile >> Task.taskTime;
            taskFile >> Task.taskStatus;
        }
    }
    taskFile.close();
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

    std::ofstream taskFile; 
    switch (userChoice)
    {
        case (1): // Creates a task, stores relevant information in a file, and adds the task to a list vector.
            clear();
            std::cout << "Simple Tasks [CLI]\n\n";
            std::cout << "Task Name: ";
            std::cin >> Task.taskName;
            std::cin.ignore();
            std::getline(std::cin, Task.taskName);
            std::cout << "Task Description: ";
            std::cin.ignore();
            std::getline(std::cin, Task.taskDescription);
            std::cin >> Task.taskDescription;
            taskFile.open(Task.taskName + ".task");
            taskFile << "[Name] " << Task.taskName << "\n";
            taskFile << "[Description] " << Task.taskDescription << "\n\n";
            taskFile << "[Date Created] " << Task.taskDate << " @" << Task.taskTime << "\n";
            taskFile << "[Status] " << Task.taskStatus << "\n";
            taskFile.close();
            taskList.push_back(Task);
            clear();
            break;
        case (2):
            clear();
            std::cout << "Simple Tasks [CLI]\n\n";
            std::cout << "Task Deletion...\n";
            std::cout << "WARNING: Are you sure you want to enter task deletion mode? [Y/N]: ";
            std::cin >> userConfirmation;
            if (userConfirmation == 'Y' || userConfirmation == 'y')
            {
                std::cout << "\nTask Name: ";
                std::cin >> Task.taskName;
                for (int i = 0; i < taskList.size(); i++)
                {
                    if (Task.taskName == taskList[i].taskName)
                    {
                        taskList.erase(taskList.begin() + i);
                        remove((Task.taskName + ".task").c_str());
                        std::cout << "Task Deleted!\n";
                        break;
                    }
                    else
                    {
                        std::cout << "Task Not Found!\n";
                        break;
                    }
                }
            }
            else
            {
                clear();
                break;
            }
            clear();
            break;
        case (3): // Displays the tasks in the task list vector to the terminal.
            clear();
            std::cout << "Simple Tasks [CLI]\n\n";
            for (int i = 0; i < taskList.size(); i++)
            {
                std::cout << " ∙ " <<taskList[i].taskName << " [" << taskList[i].taskStatus << "]" << "\n"; // This will display the task name and status of each task in the list vector to the terminal. 
            }
            std::cout << "\n";
            std::cout << "[Press any key to return to the main menu.]\n";
            std::cin.ignore();
            std::cin.get();
            clear();
            break;
        case (4):
            clear();
            exit(0); // Closes the program. -- Windows, Linux, MacOS
            break;
        case (5): // Displays info about the program and the author and/ or maintainer(s).
            clear();            
            std::cout << "Simple Tasks [CLI]\n\n";
            std::cout << "[Source Code] " << "https://github.com/C0dePr0xy/simple-tasks" << "\n";
            std::cout << "[Author] Eric Guerra\n";
            std::cout << "[Build Date] " << __DATE__ << " " << __TIME__ << "\n";
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
    taskScanner();
    while (true)
    {
        mainMenu();
    }
    return 0;
}