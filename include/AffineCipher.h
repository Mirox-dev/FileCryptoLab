#pragma once

#include "Cipher.h"

#include <string>

class AffineCipher : public Cipher {
public:
    AffineCipher(int a, int b);

    std::string encrypt(const std::string& text) const override;
    std::string decrypt(const std::string& text) const override;

private:
    static constexpr int AlphabetSize = 26;

    int a_;
    int b_;
    int aInverse_;

    static bool isEnglishLetter(char symbol);
    static bool isUppercaseLetter(char symbol);
    static bool isLowercaseLetter(char symbol);

    char encryptChar(char symbol) const;
    char decryptChar(char symbol) const;
};