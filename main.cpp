#include "CodeSnippetManager.h"
#include <iostream>

int main() {
    CodeSnippetManager manager;

    if(manager.loadToFile("snippets.txt")) {
        std::cout << "Snippets loaded from file." << std:: endl;
    }
    else {
        std::cout << " No saved snippets found. Starting with an empty manager" << std::endl;
    }


    while(true) {
        std:: cout << "1. Add Snippet" << std:: endl;
        std:: cout << "2. Retrieve Snippet" << std:: endl;
        std:: cout << "3. Exit" << std:: endl;
        std:: cout << " Choose an option : ";


        int choice;
        std:: cin >> choice;

        if (choice == 1) {
            std::string tag, code;
            std::cout << "Enter tag: ";
            std::cin>>tag;
            std::cin.ignore();

            std::cout << "Enter code Snippet:\n";
            std::string line;
            code = "";
            while (getline(std::cin,line)&& line!= "%%") {
                code += line + "\n";
            }
            manager.addSnippet(tag,code);
            std::cout <<"Snippet added." << std::endl;


        }
        else if(choice == 2) {
            std::string tag;
            std::cout << "Enter tag to retrieve snippet: ";
            std::cin >> tag;
            manager.retrieveSnippet(tag);
        }
        else if(choice == 3) {
            manager.saveToFile("snippets.txt");
            std::cout << "Snippets saved to file. Exiting the program." << std::endl;
            break;
        }
        else{
            std::cout << "Invalid choice. Please choose a valid option" << std::endl;
        }

    }








    return 0;
}