#include <iostream>
#include <cmath>

using namespace std;

// Function to perform modular exponentiation: (base^exponent) % mod
// This function is essential for large power calculations under modulo
long long modularExponentiation(long long base, long long exponent, long long mod) {
    long long result = 1;

    base = base % mod;  // Reduce base modulo mod first to simplify

    while (exponent > 0) {
        // If exponent is odd, multiply result with base
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }

        // Square the base and reduce exponent by half
        base = (base * base) % mod;
        exponent = exponent / 2;
    }

    return result;
}

int main() {
    // Publicly agreed upon prime number (p) and primitive root modulo p (g)
    // These values are known to both parties and can be insecure if small.
    long long p = 23; // A small prime number
    long long g = 5;  // A primitive root modulo 23

    cout << "Publicly Shared Variables:\n";
    cout << "Prime number (p): " << p << endl;
    cout << "Primitive root (g): " << g << endl;

    // Private keys (chosen secretly by Alice and Bob)
    long long a = 6; // Alice's private key
    long long b = 15; // Bob's private key

    // Compute public keys to exchange
    // Alice computes A = g^a mod p
    long long A = modularExponentiation(g, a, p);

    // Bob computes B = g^b mod p
    long long B = modularExponentiation(g, b, p);

    cout << "\nComputed Public Keys:\n";
    cout << "Alice sends (A): " << A << endl;
    cout << "Bob sends (B): " << B << endl;

    // Both compute the shared secret key using the other's public key and their own private key
    // Alice computes: s = B^a mod p
    long long secretKeyAlice = modularExponentiation(B, a, p);

    // Bob computes: s = A^b mod p
    long long secretKeyBob = modularExponentiation(A, b, p);

    cout << "\nComputed Shared Secret Keys:\n";
    cout << "Alice's computed secret: " << secretKeyAlice << endl;
    cout << "Bob's computed secret: " << secretKeyBob << endl;

    // If both computations are correct, the secret keys should match
    if (secretKeyAlice == secretKeyBob) {
        cout << "\nKey exchange successful. Shared secret key: " << secretKeyAlice << endl;
    } else {
        cout << "\nKey exchange failed. Secrets do not match." << endl;
    }

    return 0;
}


/*
Output:

Publicly Shared Variables:
Prime number (p): 23
Primitive root (g): 5

Computed Public Keys:
Alice sends (A): 8
Bob sends (B): 2

Computed Shared Secret Keys:
Alice's computed secret: 2
Bob's computed secret: 2

Key exchange successful. Shared secret key: 2
*/