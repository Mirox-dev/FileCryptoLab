#include "HillCipher.h"

#include "MathUtils.h"

#include <stdexcept>

namespace {
    constexpr int AlphabetSize = 26;

    bool isEnglishLetter(char symbol) {
        return ('A' <= symbol && symbol <= 'Z') || ('a' <= symbol && symbol <= 'z');
    }

    int letterToNumber(char symbol) {
        if ('a' <= symbol && symbol <= 'z') {
            symbol = static_cast<char>(symbol - 'a' + 'A');
        }

        return symbol - 'A';
    }

    char numberToLetter(int value) {
        return static_cast<char>('A' + MathUtils::modulo(value, AlphabetSize));
    }

    std::string onlyEnglishLettersUppercase(const std::string& text) {
        std::string letters;
        letters.reserve(text.size());

        for (const char symbol : text) {
            if (isEnglishLetter(symbol)) {
                letters.push_back(numberToLetter(letterToNumber(symbol)));
            }
        }

        return letters;
    }
}

HillCipher::HillCipher(int a, int b, int c, int d)
    : matrix_{{{MathUtils::modulo(a, AlphabetSize), MathUtils::modulo(b, AlphabetSize)},
               {MathUtils::modulo(c, AlphabetSize), MathUtils::modulo(d, AlphabetSize)}}} {
    if (!hasInverseMatrix()) {
        throw std::invalid_argument("Hill cipher matrix must be invertible modulo 26");
    }
}

std::string HillCipher::encrypt(const std::string& text) {
    Matrix2x2 encryptionMatrix{{
        {matrix_[0][0], matrix_[0][1]},
        {matrix_[1][0], matrix_[1][1]}
    }};

    std::string preparedText = onlyEnglishLettersUppercase(text);
    if (preparedText.size() % 2 != 0) {
        preparedText.push_back('X');
    }

    return transform(preparedText, encryptionMatrix);
}

std::string HillCipher::decrypt(const std::string& text) {
    return transform(onlyEnglishLettersUppercase(text), inverseMatrix());
}

int HillCipher::determinant() const {
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
}

bool HillCipher::hasInverseMatrix() const {
    return MathUtils::gcd(determinant(), AlphabetSize) == 1;
}

HillCipher::Matrix2x2 HillCipher::inverseMatrix() const {
    const int inverseDeterminant = MathUtils::modularInverse(determinant(), AlphabetSize);

    return {{
        {MathUtils::modulo(matrix_[1][1] * inverseDeterminant, AlphabetSize),
         MathUtils::modulo(-matrix_[0][1] * inverseDeterminant, AlphabetSize)},
        {MathUtils::modulo(-matrix_[1][0] * inverseDeterminant, AlphabetSize),
         MathUtils::modulo(matrix_[0][0] * inverseDeterminant, AlphabetSize)}
    }};
}

std::string HillCipher::transform(const std::string& text, const Matrix2x2& matrix) const {
    if (text.size() % 2 != 0) {
        throw std::invalid_argument("Hill cipher input must contain an even number of letters");
    }

    std::string result;
    result.reserve(text.size());

    for (std::size_t index = 0; index < text.size(); index += 2) {
        const int first = letterToNumber(text[index]);
        const int second = letterToNumber(text[index + 1]);

        result.push_back(numberToLetter(matrix[0][0] * first + matrix[0][1] * second));
        result.push_back(numberToLetter(matrix[1][0] * first + matrix[1][1] * second));
    }

    return result;
}
