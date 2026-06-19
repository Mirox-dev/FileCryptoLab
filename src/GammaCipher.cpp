#include "GammaCipher.h"
#include <stdexcept>


GammaCipher::GammaCipher(const std::string& key) {
    if (key.empty()) {
        throw std::invalid_argument("Invalid gamma key: key cannot be empty");
    }
    this->key = key;
}

std::string GammaCipher::encrypt(const std::string& text) const {
    std::string result = "";

    for (int i = 0; i < text.length(); i++) {
        char encryptedSymbol = text[i] ^ key[i % key.length()];
        result += encryptedSymbol;
    }

    return result;
}

std::string GammaCipher::decrypt(const std::string& text) const {
    return encrypt(text);
}

std::string GammaCipher::getKey() const {
    return key;
}