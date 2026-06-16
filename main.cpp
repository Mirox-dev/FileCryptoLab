#include "AffineCipher.h"
#include "TestRunner.h"

#include <exception>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc > 1 && std::string(argv[1]) == "--test") {
        return runAllTests();
    }
    else
    {
        try {
            AffineCipher cipher(5, 8);

            const std::string text = "Hello World!";
            const std::string encrypted = cipher.encrypt(text);
            const std::string decrypted = cipher.decrypt(encrypted);

            std::cout << "Original:  " << text << '\n';
            std::cout << "Encrypted: " << encrypted << '\n';
            std::cout << "Decrypted: " << decrypted << '\n';
        }
        catch (const std::exception& error) {
            std::cerr << "Error: " << error.what() << '\n';
            return 1;
        }

        return 0;
    }
}