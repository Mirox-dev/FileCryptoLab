#include "ConsoleMenu.h"
#include "TestRunner.h"

#include <exception>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc > 1 && std::string(argv[1]) == "--test") {
        return runAllTests();
    }

    try {
        ConsoleMenu menu;
        menu.run();
    }
    catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}