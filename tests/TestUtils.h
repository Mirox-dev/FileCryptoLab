#pragma once

#include <iostream>
#include <string>

inline int failedTestsCount = 0;

template <typename Actual, typename Expected>
void expectEqual(
    const Actual& actual,
    const Expected& expected,
    const std::string& testName
) {
    if (actual == expected) {
        std::cout << "[PASS] " << testName << '\n';
        return;
    }

    ++failedTestsCount;

    std::cerr << "[FAIL] " << testName << '\n';
    std::cerr << "  Expected: " << expected << '\n';
    std::cerr << "  Actual:   " << actual << '\n';
}

template <typename ExceptionType, typename Function>
void expectThrows(Function function, const std::string& testName) {
    try {
        function();
    }
    catch (const ExceptionType&) {
        std::cout << "[PASS] " << testName << '\n';
        return;
    }
    catch (...) {
        ++failedTestsCount;
        std::cerr << "[FAIL] " << testName << '\n';
        std::cerr << "  Wrong exception type\n";
        return;
    }

    ++failedTestsCount;
    std::cerr << "[FAIL] " << testName << '\n';
    std::cerr << "  Expected exception was not thrown\n";
}