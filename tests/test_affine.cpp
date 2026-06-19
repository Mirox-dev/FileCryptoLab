#include "AffineCipher.h"
#include "TestUtils.h"

#include <stdexcept>
#include <string>

void runAffineCipherTests() {
    AffineCipher cipher(5, 8);

    expectEqual(
        cipher.encrypt("Hello World!"),
        std::string("Rclla Oaplx!"),
        "AffineCipher encrypts text with uppercase and lowercase letters"
    );

    expectEqual(
        cipher.decrypt("Rclla Oaplx!"),
        std::string("Hello World!"),
        "AffineCipher decrypts text with uppercase and lowercase letters"
    );

    expectEqual(
        cipher.decrypt(cipher.encrypt("Attack at Dawn!")),
        std::string("Attack at Dawn!"),
        "AffineCipher restores original text after encryption and decryption"
    );

    expectEqual(
        cipher.encrypt("ABC xyz 123!"),
        std::string("INS tyd 123!"),
        "AffineCipher keeps spaces, digits and punctuation unchanged"
    );

    expectEqual(
        cipher.encrypt(""),
        std::string(""),
        "AffineCipher handles empty string"
    );

    AffineCipher cipherWithNegativeB(5, -1);

    expectEqual(
        cipherWithNegativeB.encrypt("A"),
        std::string("Z"),
        "AffineCipher normalizes negative b parameter"
    );

    expectThrows<std::invalid_argument>(
        []() {
            AffineCipher invalidCipher(2, 8);
        },
        "AffineCipher throws exception when a is not coprime with 26"
    );

    expectThrows<std::invalid_argument>(
        []() {
            AffineCipher invalidCipher(13, 8);
        },
        "AffineCipher throws exception when modular inverse does not exist"
    );
}