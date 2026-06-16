#include "AffineCipher.h"
#include "HillCipher.h"
#include "FileManager.h"


#include <iostream>

int main() {
    try {
        HillCipher cipher(5, 8, 1, 3);
        

        std::string text = FileManager::readFile("data/input.txt");
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