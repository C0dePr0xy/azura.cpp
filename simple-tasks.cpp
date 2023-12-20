#include <fstream>
#include <iostream>
#include <string>

char confirmation;

int main() {
    char input;

    while (true) {
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "Simple-Tasks\n";
        std::cout << "New Task [N]\n";
        std::cout << "Edit Task [E]\n";
        std::cout << "Delete Task [D]\n";
        std::cout << "List Tasks [L]\n";
        std::cout << "About [A]\n";
        std::cout << "Exit [X]\n";
        std::cin >> input;
        std::cout << "\n";
        std::cout << "\n";

        std::ofstream TaskFile;
        std::string taskstring;

        switch (input) {
        case 'N':
            TaskFile.open("Tasks.utsk", std::ios::app);
            if (!TaskFile.is_open()) {
                std::cerr << "Error opening Tasks.utsk for writing!\n";
                std::cout << "Operation failed: Error Code: PEFO01C!\n";
                std::cout << "Refer to MANUAL.txt for more info\n";
                return 1;
            }
            TaskFile.close();
            break;
        case 'E':
            TaskFile.open("Tasks.utsk", std::ios::out);
            if (!TaskFile.is_open()) {
                std::cerr << "Error opening Tasks.utsk for writing!\n";
                std::cout << "Operation failed: Error Code: PEFO01W!\n";
                std::cout << "Refer to MANUAL.txt for more info\n";
                return 1;
            }
            std::cout << "Enter Task Details: ";
            std::cin.ignore();
            std::getline(std::cin, taskstring);
            TaskFile << taskstring << "\n";
            TaskFile.close();
            break;

        case 'D':
            std::cout << "Deletion of Tasks.utsk is irreversible!\n";
            std::cout << "Proceed? [Y] [N]\n";
            std::cin >> confirmation;
            if (confirmation == 'Y') {
                if (std::remove("Tasks.utsk") == 0) {
                    std::cout << "\n";
                    std::cout << "Tasks File Deletion Complete!\n";
                    std::cout << "\n";
                }
                else {
                    std::cout << "\n";
                    std::cout << "Operation failed: Error Code: UEII03D!\n";
                    std::cerr << "Error deleting Tasks.utsk!\n";
                    std::cout << "\n";
                }
            }
            else if (confirmation == 'N') {
                std::cout << "\n";
                std::cout << "Operation failed: Error Code: UEII01D!\n";
                std::cout << "Refer to MANUAL.txt for more info\n";
                std::cout << "\n";
            }
            else {
                std::cout << "\n";
                std::cout << "Invalid Input! Error Code: UEII02D!\n";
                std::cout << "Refer to MANUAL.txt for more info\n";
                std::cout << "\n";
            }
            break;
        case 'L':
            std::cout << "\n";
            std::cout << "Feature in progress.\n";
            std::cout << "\n";
            break;
        case 'X':
            std::cout << "\n";
            std::cout << "Exiting program. Goodbye!\n";
            std::cout << "\n";
            return 0;
        case 'A':
            std::cout << "(release) (r-v0.4)\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "Author(s): Eric Guerra\n";
            std::cout << "\n";
            std::cout << "Maintainer(s): Eric Guerra\n";
            std::cout << "\n";
            std::cout << "License: BSL-1.0\n";
            std::cout << "\n";
            std::cout << "Contact(s): ericg36@outlook.com\n";
            std::cout << "\n";
            break;
        default:
            std::cout << "\n";
            std::cout << "Invalid Input! Error Code: UEII02Q!\n";
            std::cout << "Refer to MANUAL.txt for more info\n";
            std::cout << "\n";
            break;
        }
    }

    return 0;
}