#include <fstream>
#include <iostream>
#include <string>
using namespace std;

char input;
char confirmation;

int main() {
    while (true) {
        std::cout << "Simple-Tasks for WINDOWS OS!\n";

        std::cout << "New Task [N]\n";
        std::cout << "Edit Task [E]\n";
        std::cout << "Delete Task [D]\n";
        std::cout << "List Tasks [L]\n";
        std::cout << "About [A]\n";
        std::cout << "Exit [X]\n";
        std::cout << "\n";
        std::cin >> input;
        std::cout << "\n";
        std::cout << "\n";

        
        std::ofstream TaskFile ("Tasks.utsk");
        std::string taskstring;

        switch (input) {
        case 'N':
            TaskFile.open("Tasks.utsk");
            break;
        case 'E':
            TaskFile.open("Tasks.utsk", std::ios::out);
            std::cout << "Enter TaskDetails: ";
            std::cin >> taskstring;
            TaskFile << taskstring << "\n";
            break;
        case 'D':
            std::cout << "Deletion of Tasks.utsk is irreversable!\n";
            std::cout << "Proceed? [Y] [N]\n";
            std::cin >> confirmation;
            if (confirmation == 'Y') {
                remove("Tasks.utsk");
                std::cout << "\n";
                std::cout << "Tasks File Deletion Complete!\n";
                std::cout << "\n";
            }
            else if (confirmation == 'N') {
                std::cout << "Operation failed: \n";
                std::cout << "Error Code: UEII01D!\n";
                std::cout << "Refer to " << "MANUAL.txt" << " for more info\n";
            }
            else {
                std::cout << "Invalid Input!\n";
                std::cout << "Error Code: UEII02D!\n";
                std::cout << "Refer to " << "MANUAL.txt" << " for more info\n";
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
            std::cout << "\n";
            TaskFile.close();
            return 0;
        case 'A':
            std::cout << "(release) (r-v0.3)\n";
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
            std::cout << "Invalid Input!\n";
            std::cout << "Error Code: UEII02Q!\n";
            std::cout << "Refer to " << "MANUAL.txt" << " for more info\n";
            std::cout << "\n";
            break;
        }
    }

    return 0;
}