#include "AffineCipher.h"
#include "MathUtils.h"

#include <stdexcept>

AffineCipher::AffineCipher(int a, int b)
    : a_(a),
      b_(MathUtils::modulo(b, AlphabetSize)),
      aInverse_(0) {
    if (MathUtils::gcd(a_, AlphabetSize) != 1) {
        throw std::invalid_argument(
            "Invalid affine key: parameter 'a' must be coprime with 26"
        );
    }

    aInverse_ = MathUtils::modularInverse(a_, AlphabetSize);
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

    const char base = isUppercaseLetter(symbol) ? 'A' : 'a';
    const int x = symbol - base;

    const int encrypted = MathUtils::modulo(a_ * x + b_, AlphabetSize);

    return static_cast<char>(base + encrypted);
}

char AffineCipher::decryptChar(char symbol) const {
    if (!isEnglishLetter(symbol)) {
        return symbol;
    }

    const char base = isUppercaseLetter(symbol) ? 'A' : 'a';
    const int y = symbol - base;

    const int decrypted = MathUtils::modulo(
        aInverse_ * (y - b_),
        AlphabetSize
    );

    return static_cast<char>(base + decrypted);
}