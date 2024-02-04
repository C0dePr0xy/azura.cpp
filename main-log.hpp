#ifndef MAIN_CPP
#define MAIN_CPP
#include <fstream>
#include <iostream>
#include <string>

void log();

void log() {
    std::ofstream LogFile("Debug.log");
    LogFile << "Log stuff goes here?" << "\n";
    LogFile.close();
}

#endif // MAIN_CPP