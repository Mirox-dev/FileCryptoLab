#include "ConsoleMenu.h"

#include "AffineCipher.h"
#include "FileManager.h"
#include "HillCipher.h"
#include "GammaCipher.h"

#include <exception>
#include <iostream>
#include <limits>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

void ConsoleMenu::run() {
    while (true) {
        printMainMenu();

        const int choice = readInt("Choose action: ");

        switch (choice) {
            case 1:
                processFile(true);
                break;

            case 2:
                processFile(false);
                break;

            case 0:
                std::cout << "Goodbye!\n";
                return;

            default:
                std::cout << "Invalid menu option. Try again.\n\n";
                break;
        }
    }
}

void ConsoleMenu::printMainMenu() const {
    std::cout << "=== FileCryptoLab ===\n";
    std::cout << "1. Encrypt file\n";
    std::cout << "2. Decrypt file\n";
    std::cout << "0. Exit\n";
}

void ConsoleMenu::printAlgorithmMenu() const {
    std::cout << "\nChoose cipher:\n";
    std::cout << "1. Affine cipher\n";
    std::cout << "2. XOR (Gamma) cipher\n";
    std::cout << "3. Hill cipher\n";
}

void ConsoleMenu::processFile(bool encryptMode) {
    try {
        const std::string inputPath = readNonEmptyLine("Input file path: ");
        const std::string outputPath = readNonEmptyLine("Output file path: ");

        std::unique_ptr<Cipher> cipher = createCipher();

        const std::string inputText = FileManager::readFile(inputPath);

        std::string result;

        if (encryptMode) {
            result = cipher->encrypt(inputText);
        } else {
            result = cipher->decrypt(inputText);
        }

        FileManager::writeFile(outputPath, result);

        std::cout << "\nSuccess!\n";
        std::cout << "Result saved to: " << outputPath << "\n\n";
    }
    catch (const std::exception& error) {
        std::cout << "\nError: " << error.what() << "\n\n";
    }
}

std::unique_ptr<Cipher> ConsoleMenu::createCipher() {
    printAlgorithmMenu();

    const int algorithmChoice = readInt("Your choice: ");

    switch (algorithmChoice) {
        case 1: {
            const int a = readInt("Enter parameter a: ");
            const int b = readInt("Enter parameter b: ");

            return std::make_unique<AffineCipher>(a, b);
        }

        case 2: {
            const std::string key = readNonEmptyLine("Enter XOR key: ");

            return std::make_unique<GammaCipher>(key);
        }

        case 3: {
            std::cout << "Enter Hill cipher 2x2 matrix:\n";

            const int a = readInt("matrix[0][0]: ");
            const int b = readInt("matrix[0][1]: ");
            const int c = readInt("matrix[1][0]: ");
            const int d = readInt("matrix[1][1]: ");

            return std::make_unique<HillCipher>(a, b, c, d);
        }

        default:
            throw std::invalid_argument("Invalid cipher option");
    }
}

int ConsoleMenu::readInt(const std::string& prompt) const {
    while (true) {
        std::cout << prompt;

        std::string line;
        std::getline(std::cin, line);

        std::istringstream stream(line);

        int value = 0;
        char extra = '\0';

        if (stream >> value && !(stream >> extra)) {
            return value;
        }

        std::cout << "Invalid number. Try again.\n";
    }
}

std::string ConsoleMenu::readNonEmptyLine(const std::string& prompt) const {
    while (true) {
        std::cout << prompt;

        std::string line;
        std::getline(std::cin, line);

        if (!line.empty()) {
            return line;
        }

        std::cout << "Value cannot be empty. Try again.\n";
    }
}