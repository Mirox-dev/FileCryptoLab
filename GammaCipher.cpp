#include "GammaCipher.h"

GammaCipher::GammaCipher(const std::string& key) {
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