// Purpose: Contains the classes used in Simple Tasks.
// This file is used to store all the program classes for the sake of easy navigation, readability, and organization.

// Includes necessary libraries for the classes to run.
#include <iostream>
#include <fstream>
#include <string>

// Manages the user agent.
// This class is used to manage the user's login information.
// It contains the user's username and password.
class userAgentManager
{
    public:
	    std::string username;
	    std::string password;
};

// Manages the task manager agent.
// This class is used to manage the user's tasks.
class taskManagerAgent
{
    public:
        userAgentManager user;
        std::string taskAgent;

        void about()
        {
            double version = 0.1;
            
            std::cout << "Simple Tasks v" << version << "\n\n";
            std::cout << "[User]:" << user.username << "\n";
            std::cout << "[Author]: Eric Guerra" << "\n";
        }
};