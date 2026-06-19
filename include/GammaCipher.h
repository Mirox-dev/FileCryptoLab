#ifndef GAMMA_CIPHER_H
#define GAMMA_CIPHER_H

#include "Cipher.h"
#include <string>

class GammaCipher : public Cipher {
private:
    std::string key;

public:
    GammaCipher(const std::string& key);

    std::string encrypt(const std::string& text) const override;
    std::string decrypt(const std::string& text) const override;

    std::string getKey() const;
};

#endif