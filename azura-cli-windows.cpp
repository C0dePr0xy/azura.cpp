#include <fstream>
#include <iostream>

char input;

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

        std::string FileName;
        std::string TaskDetails;

        std::ofstream TaskFile;

        switch (input) {
        case 'N':
            std::cout << "Enter FileName: ";
            std::cin >> FileName;
            TaskFile.open(FileName);
            TaskFile.close();
            break;
        case 'E':
            std::cout << "Enter FileName to edit: ";
            std::cin >> FileName;
            TaskFile.open(FileName);
            std::cout << "Enter TaskDetails: ";
            std::cin >> TaskDetails;
            TaskFile << TaskDetails << "\n";
            TaskFile.close();
            break;
        case 'D':
            std::cout << "Please Enter FileName to delete: ";
            std::cin >> FileName;
            if (remove("myfile.txt") != 0)
                perror("Error deleting file");
            else
                puts("File successfully deleted");
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
            return 0; // Exit the program
        case 'A':
            std::cout << "(release) (r-v0.1)\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "Author(s): Eric Guerra\n";
            std::cout << "\n";
            std::cout << "Maintainer(s): Eric Guerra\n";
            std::cout << "\n";
            std::cout << "License: N/A\n";
            std::cout << "\n";
            std::cout << "Contact(s): ericg36@outlook.com\n";
            std::cout << "\n";
            break;
        default:
            std::cout << "\n";
            std::cout << "Bad Input!\n";
            std::cout << "\n";
            break;
        }
    }

    return 0;
}