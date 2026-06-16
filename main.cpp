#include <iostream>
#include "include/FileManager.h"

int main() {
    try {
        std::string text = FileManager::readFile("data/input.txt");

        std::cout << "File content:" << std::endl;
        std::cout << text << std::endl;

        FileManager::writeFile("output.txt", text);

        std::cout << "File was copied successfully." << std::endl;
    }
    catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }

    return 0;
}