#include "classes.hpp"
#include <cassert>
#include <fstream>
#include <iostream>

double version();
void userlogin();
std::string YN;
std::string uname;
std::string pword;

double version() {
	Version vNum;
	vNum.version = vNum.version + 0.1;

	return vNum.version;
}

void userlogin() {
    std::string uname;
    std::string pword;
    std::string YN;
    User userLogin;

    std::cout << "[Username]\n";
    std::cin >> uname;
    std::cout << "[Password]\n";
    std::cin >> pword;

    userLogin.username = uname;
    userLogin.password = pword;

    std::cout << "Create new user? [Y] [N]\n";
    std::cin >> YN;

    if (YN == "Y" || YN == "y") {
        std::ofstream userFile("profile.cfg");
        if (userFile.is_open()) {
            userFile << "[Username]\n";
            userFile << userLogin.username << "\n";
            userFile << "[Password]\n";
            userFile << userLogin.password << "\n";
            userFile.close();
            std::cout << "\n";
            std::cout << "\n";
        }
        else {
            std::cerr << "Error: Unable to create user profile file!\n";
            assert(false);
        }
    }
    else if (YN == "N" || YN == "n") {
        std::ifstream userFile("profile.cfg");
        if (userFile.is_open()) {
            std::string fileUsername;
            std::string filePassword;
            userFile >> fileUsername;
            userFile >> userLogin.username;
            userFile >> filePassword;
            userFile >> userLogin.password;
            userFile.close();

            if (userLogin.password == pword) {
                std::cout << userLogin.username << " is logged in!\n";
                std::cout << "\n";
                std::cout << "\n";
            }
            else {
                std::cout << "Invalid login!\n";
                assert(false);
            }
        }
        else {
            std::cerr << "Error: Unable to open user profile file!\n";
            assert(false);
        }
    }
}