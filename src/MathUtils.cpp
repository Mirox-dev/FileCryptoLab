#include "MathUtils.h"

#include <cstdlib>
#include <stdexcept>

namespace MathUtils {
    int modulo(int value, int modulus) {
        if (modulus <= 0) {
            throw std::invalid_argument("Modulus must be positive");
        }

        const int result = value % modulus;
        return result < 0 ? result + modulus : result;
    }

    int gcd(int left, int right) {
        left = std::abs(left);
        right = std::abs(right);

        while (right != 0) {
            const int remainder = left % right;
            left = right;
            right = remainder;
        }

        return left;
    }

    int modularInverse(int value, int modulus) {
        if (modulus <= 0) {
            throw std::invalid_argument("Modulus must be positive");
        }

        const int normalizedValue = modulo(value, modulus);

        for (int candidate = 1; candidate < modulus; ++candidate) {
            if (modulo(normalizedValue * candidate, modulus) == 1) {
                return candidate;
            }
        }

        throw std::invalid_argument("Modular inverse does not exist");
    }
}
