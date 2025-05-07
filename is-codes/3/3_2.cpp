#include <iostream>

using namespace std;

// Naive power function to compute (base^exp) % mod
// This uses a simple loop and is NOT efficient for large exponents
long long naivePowerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    for (long long i = 0; i < exp; i++) {
        result = (result * base) % mod; // Take mod at each multiplication
    }
    return result;
}

int main() {
    // Step 1: Publicly known values
    int p = 23;  // Prime number (modulus)
    int g = 5;   // Primitive root modulo p

    cout << "Publicly known values:\n";
    cout << "Prime number (p): " << p << endl;
    cout << "Primitive root (g): " << g << endl;

    // Step 2: Each party chooses a private key (kept secret)
    int a = 6;   // Alice's private key
    int b = 15;  // Bob's private key

    // Step 3: Each party computes their public key to share
    // A = g^a mod p
    int A = naivePowerMod(g, a, p); // Alice's public key

    // B = g^b mod p
    int B = naivePowerMod(g, b, p); // Bob's public key

    cout << "\nPublic keys exchanged:\n";
    cout << "Alice sends A = " << A << endl;
    cout << "Bob sends B = " << B << endl;

    // Step 4: Both compute the shared secret key
    // Alice computes: s = B^a mod p
    int secretAlice = naivePowerMod(B, a, p);

    // Bob computes: s = A^b mod p
    int secretBob = naivePowerMod(A, b, p);

    cout << "\nShared secret keys computed:\n";
    cout << "Alice's secret key: " << secretAlice << endl;
    cout << "Bob's secret key: " << secretBob << endl;

    // Step 5: Verify if both shared secrets are the same
    if (secretAlice == secretBob) {
        cout << "\nSuccess! Shared secret key is: " << secretAlice << endl;
    } else {
        cout << "\nError: Shared secrets do not match!" << endl;
    }

    return 0;
}


/*
Output:

Publicly known values:
Prime number (p): 23
Primitive root (g): 5

Public keys exchanged:
Alice sends A = 8
Bob sends B = 2

Shared secret keys computed:
Alice's secret key: 2
Bob's secret key: 2

Success! Shared secret key is: 2
*/