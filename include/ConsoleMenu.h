#pragma once

#include "Cipher.h"

#include <memory>
#include <string>

class ConsoleMenu {
public:
    void run();

private:
    void printMainMenu() const;
    void printAlgorithmMenu() const;

    void processFile(bool encryptMode);

    std::unique_ptr<Cipher> createCipher();

    int readInt(const std::string& prompt) const;
    std::string readNonEmptyLine(const std::string& prompt) const;
};