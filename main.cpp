#include "AffineCipher.h"

#include <iostream>
#include <string>

int main() {
    try {
        AffineCipher cipher(5, 8);

        std::string text = "Hello World!";
        std::string encrypted = cipher.encrypt(text);
        std::string decrypted = cipher.decrypt(encrypted);

        std::cout << "Original:  " << text << '\n';
        std::cout << "Encrypted: " << encrypted << '\n';
        std::cout << "Decrypted: " << decrypted << '\n';
    }
    catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << '\n';
    }

    return 0;
}