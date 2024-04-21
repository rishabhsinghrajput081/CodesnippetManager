#include "CodeSnippetManager.h"
#include <iostream>
#include <string>
#include <fstream>

void CodeSnippetManager::addSnippet(const std::string& tag, const std::string& code) {
    snippets[tag] = code;
}

void CodeSnippetManager::retrieveSnippet(const std::string& tag) {
    auto it = snippets.find(tag);
    if (it != snippets.end()) {
        std::cout << "Snippet for tag " << tag << ":" << std::endl;
        std::cout << it->second << std::endl;
    }
    else {
        std::cout << "No snippet found for tag " << tag << "." << std::endl;
    }
}

bool CodeSnippetManager::saveToFile(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cout << "Error: Unable to open file for writing." << std::endl;
        return false;
    }

    for (const auto& entry : snippets) {
        outFile << "Tag: " << entry.first << "\n";
        outFile << "Code:\n" << entry.second << "\n";
    }

    outFile.close();
    std::cout << "Snippets saved to the file: " << filename << std::endl;
    return true;
}

bool CodeSnippetManager::loadToFile(const std::string& filename) {
    std::ifstream ifile(filename);
    if (!ifile) {
        std::cout << "Error: Unable to open file for reading." << std::endl;
        return false;
    }
    snippets.clear();
    std::string line;
    std::string currentTag;
    std::string currentCode;

    while (getline(ifile, line)) {
        if (line.find("Tag:") == 0) {
            currentTag = line.substr(5);
        }
        else if (line.find("Code:") == 0) {
            currentCode = "";
            while (getline(ifile, line) && !line.empty()) {
                currentCode += line + "\n";
            }
            snippets[currentTag] = currentCode;
        }
    }
    ifile.close();
    std::cout << "Snippets loaded from file: " << filename << std::endl;
    return true;
}
