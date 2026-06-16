#pragma once

#include "Cipher.h"

#include <array>
#include <string>

class HillCipher : public Cipher {
public:
    HillCipher(int a, int b, int c, int d);

    std::string encrypt(const std::string& text) const override;
    std::string decrypt(const std::string& text) const override;

private:
    static constexpr int AlphabetSize = 26;

    using Matrix2x2 = std::array<std::array<int, 2>, 2>;

    Matrix2x2 matrix_;

    int determinant() const;
    bool hasInverseMatrix() const;
    Matrix2x2 inverseMatrix() const;

    std::string transform(
        const std::string& text,
        const Matrix2x2& matrix
    ) const;
};