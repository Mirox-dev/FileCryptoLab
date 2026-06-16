#include "TestRunner.h"
#include "TestUtils.h"

#include <iostream>

void runAffineCipherTests();
void runXorCipherTests();
void runHillCipherTests();

int runAllTests() {
    std::cout << "Running FileCryptoLab tests...\n\n";

    runAffineCipherTests();
    runXorCipherTests();
    runHillCipherTests();

    std::cout << '\n';

    if (failedTestsCount > 0) {
        std::cerr << "Tests failed: " << failedTestsCount << '\n';
        return 1;
    }

    std::cout << "All tests passed successfully!\n";
    return 0;
}