#include <simple-tasks.cpp>

void log();

void log() {
    std::ofstream LogFile("Debug.log");
    LogFile << main() << "\n";
}