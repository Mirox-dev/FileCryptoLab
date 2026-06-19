#include "GammaCipher.h"
#include "TestUtils.h"

#include <stdexcept>
#include <string>

void runGammaCipherTests() {
    GammaCipher cipher("secret");

    const std::string originalText = "Hello World!";
    const std::string encryptedText = cipher.encrypt(originalText);
    const std::string decryptedText = cipher.decrypt(encryptedText);

    expectEqual(
        decryptedText,
        originalText,
        "GammaCipher restores original text after encryption and decryption"
    );

    GammaCipher simpleCipher("\x01");

    expectEqual(
        simpleCipher.encrypt("ABC"),
        std::string("@CB"),
        "GammaCipher encrypts text with one-character key"
    );

    expectEqual(
        simpleCipher.decrypt("@CB"),
        std::string("ABC"),
        "GammaCipher decrypts text with one-character key"
    );

    expectEqual(
        cipher.encrypt(""),
        std::string(""),
        "GammaCipher handles empty string"
    );

    GammaCipher binaryCipher("key");

    const std::string binaryText = std::string("A\0B\0C", 5);
    const std::string binaryEncrypted = binaryCipher.encrypt(binaryText);
    const std::string binaryDecrypted = binaryCipher.decrypt(binaryEncrypted);

    expectEqual(
        binaryDecrypted,
        binaryText,
        "GammaCipher handles zero bytes"
    );

    expectThrows<std::invalid_argument>(
        []() {
            GammaCipher invalidCipher("");
        },
        "GammaCipher rejects empty key"
    );
}