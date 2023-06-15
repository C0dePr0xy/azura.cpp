#include <iostream>

int main()
{
    std::string uname = "";
    std::string pword = "";
    std::string yesno;
    int numkey;

    std::cout << "\n"
                 "██████╗░██████╗░░█████╗░░░░░░██╗███████╗░█████╗░████████╗  ░█████╗░███████╗██╗░░░██╗██████╗░░█████╗░\n"
                 "██╔══██╗██╔══██╗██╔══██╗░░░░░██║██╔════╝██╔══██╗╚══██╔══╝  ██╔══██╗╚════██║██║░░░██║██╔══██╗██╔══██╗\n"
                 "██████╔╝██████╔╝██║░░██║░░░░░██║█████╗░░██║░░╚═╝░░░██║░░░  ███████║░░███╔═╝██║░░░██║██████╔╝███████║\n"
                 "██╔═══╝░██╔══██╗██║░░██║██╗░░██║██╔══╝░░██║░░██╗░░░██║░░░  ██╔══██║██╔══╝░░██║░░░██║██╔══██╗██╔══██║\n"
                 "██║░░░░░██║░░██║╚█████╔╝╚█████╔╝███████╗╚█████╔╝░░░██║░░░  ██║░░██║███████╗╚██████╔╝██║░░██║██║░░██║\n"
                 "╚═╝░░░░░╚═╝░░╚═╝░╚════╝░░╚════╝░╚══════╝░╚════╝░░░░╚═╝░░░  ╚═╝░░╚═╝╚══════╝░╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝\n";
    std::cout << "(visual-concept) (eb-v0.6)\n";
    std::cout << " \n";
    std::cout << "Enter Custom Username:\n";
    std::cin >> uname;
    std::cout << "Hello " << uname << " welcome to PROJECT AZURA (early-build v0.5)\n";
    std::cout << "Hello " << uname << ", please enter password (remember that you can edit the pword variable to whatever you want within the code!): ";
    std::cin >> pword;
    if (pword == admin){
        std::cout << "Access Granted!\n";
        std::cout << "Welcome " << uname << " to AZURA, Your personal lightweight (concept) to-do list.\n";
        std::cout << "Just as a reminder, you can always edit goals in the code using a text editor of your choice! :D\n";
        std::cout << "Would you like to continue? (Y/y or N/n)\n";
        std::cin >> yesno;
        if (yesno == "y" || "Y"){
            std::cout << "Select which step 1-10 you want to do first please... (You can edit the tasks in the switch statement within the code!)\n";
            std::cin >> numkey;
            switch (numkey) {
                case 1:
                    std::cout << "Brainstorm Ideas\n";
                    break;
                case 2:
                    std::cout << "Organize Ideas\n";
                    break;
                case 3:
                    std::cout << "Learn more C++\n";
                    break;
                case 4:
                    std::cout << "Learn Blender3D\n";
                    break;
                case 5:
                    std::cout << "Look for suitable game engine\n";
                    break;
                case 6:
                    std::cout << "Install game engine\n";
                    break;
                case 7:
                    std::cout << "Learn game engine\n";
                    break;
                case 8:
                    std::cout << "Make simple character controller\n";
                    break;
                case 9:
                    std::cout << "Design simple level\n";
                    break;
                case 10:
                    std::cout << "Practice C++ more\n";
                    break;
                default:
                    std::cout << "Invalid numkey!\n";
                    break;
            }
        }else if (yesno == "n" || "N"){
            std::cout << "logging out...\n";
            std::cout << "Exiting program...\n";
        } else{
            std::cout << "INVALID INPUT!! " << uname << " logging out, " << (pword == "CLEARED") << "EXITING...";
        }
    } else{
        std::cout << "Access Denied!\n";
        std::cout << uname << " is not permitted to use this application!\n";
        std::cout << "Please close and re-open terminal to restart.\n";
        std::cout << "Bye bye!! :3\n";
    }
}