#include "AffineCipher.h"

#include <stdexcept>

AffineCipher::AffineCipher(int a, int b)
    : a_(a), b_(mod(b, AlphabetSize)) {
    if (gcd(a_, AlphabetSize) != 1) {
        throw std::invalid_argument(
            "Invalid affine key: parameter 'a' must be coprime with 26"
        );
    }
}

std::string AffineCipher::encrypt(const std::string& text) const {
    std::string result;
    result.reserve(text.size());

    for (char symbol : text) {
        result.push_back(encryptChar(symbol));
    }

    return result;
}

std::string AffineCipher::decrypt(const std::string& text) const {
    std::string result;
    result.reserve(text.size());

    for (char symbol : text) {
        result.push_back(decryptChar(symbol));
    }

    return result;
}

int AffineCipher::gcd(int left, int right) {
    left = left < 0 ? -left : left;
    right = right < 0 ? -right : right;

    while (right != 0) {
        int remainder = left % right;
        left = right;
        right = remainder;
    }

    return left;
}

int AffineCipher::mod(int value, int modulo) {
    int result = value % modulo;

    if (result < 0) {
        result += modulo;
    }

    return result;
}

int AffineCipher::modInverse(int value, int modulo) {
    value = mod(value, modulo);

    for (int candidate = 1; candidate < modulo; ++candidate) {
        if (mod(value * candidate, modulo) == 1) {
            return candidate;
        }
    }

    throw std::invalid_argument("Modular inverse does not exist");
}

bool AffineCipher::isEnglishLetter(char symbol) {
    return isUppercaseLetter(symbol) || isLowercaseLetter(symbol);
}

bool AffineCipher::isUppercaseLetter(char symbol) {
    return symbol >= 'A' && symbol <= 'Z';
}

bool AffineCipher::isLowercaseLetter(char symbol) {
    return symbol >= 'a' && symbol <= 'z';
}

char AffineCipher::encryptChar(char symbol) const {
    if (!isEnglishLetter(symbol)) {
        return symbol;
    }

    char base = isUppercaseLetter(symbol) ? 'A' : 'a';
    int x = symbol - base;

    int encrypted = mod(a_ * x + b_, AlphabetSize);

    return static_cast<char>(base + encrypted);
}

char AffineCipher::decryptChar(char symbol) const {
    if (!isEnglishLetter(symbol)) {
        return symbol;
    }

    char base = isUppercaseLetter(symbol) ? 'A' : 'a';
    int y = symbol - base;

    int aInverse = modInverse(a_, AlphabetSize);
    int decrypted = mod(aInverse * (y - b_), AlphabetSize);

    return static_cast<char>(base + decrypted);
}