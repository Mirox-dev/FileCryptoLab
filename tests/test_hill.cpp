#include "HillCipher.h"
#include "TestUtils.h"

#include <stdexcept>
#include <string>

void runHillCipherTests() {
    HillCipher cipher(3, 3, 2, 5);

    expectEqual(
        cipher.encrypt("HELP"),
        std::string("HIAT"),
        "HillCipher encrypts HELP with 2x2 matrix"
    );

    expectEqual(
        cipher.decrypt("HIAT"),
        std::string("HELP"),
        "HillCipher decrypts HIAT"
    );

    expectEqual(
        cipher.decrypt(cipher.encrypt("TEST")),
        std::string("TEST"),
        "HillCipher restores original text with even length"
    );

    expectEqual(
        cipher.encrypt("HELLO"),
        std::string("HIOZHN"),
        "HillCipher pads odd-length text with X"
    );

    expectEqual(
        cipher.encrypt(""),
        std::string(""),
        "HillCipher handles empty string"
    );

    expectThrows<std::invalid_argument>(
        []() {
            HillCipher invalidCipher(2, 4, 2, 4);
        },
        "HillCipher rejects non-invertible matrix"
    );

    expectThrows<std::invalid_argument>(
        []() {
            HillCipher invalidCipher(1, 2, 3, 4);
        },
        "HillCipher rejects matrix with determinant without inverse"
    );
}