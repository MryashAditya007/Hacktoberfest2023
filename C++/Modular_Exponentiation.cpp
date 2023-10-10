#include <iostream>
using namespace std;

long long fastModExp(long long base, long long exponent, long long modulus) {
    if (modulus == 1) return 0;  // Modulus 1 is not supported.

    long long result = 1;
    base = base % modulus;

    while (exponent > 0) {
        // If the current exponent is odd, multiply result with base.
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }

        // Exponent must be even now.
        exponent = exponent >> 1; // Equivalent to exponent /= 2
        base = (base * base) % modulus;
    }

    return result;
}

int main() {
    long long base = 2;
    long long exponent = 10;
    long long modulus = 1000000007; // Example modulus

    long long result = fastModExp(base, exponent, modulus);

    std::cout << base << "^" << exponent << " % " << modulus << " = " << result << std::endl;

    return 0;
}
