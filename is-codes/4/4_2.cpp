#include <iostream>
using namespace std;

// Naive function to find GCD (Greatest Common Divisor)
int gcd(int a, int b) {
    int gcd = 1;
    for (int i = 1; i <= a && i <= b; ++i)
        if (a % i == 0 && b % i == 0)
            gcd = i;
    return gcd;
}

// Naive function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i < num; ++i)
        if (num % i == 0)
            return false;
    return true;
}

// Naive function to compute base^exp mod mod
int modPow(int base, int exp, int mod) {
    int result = 1;
    for (int i = 0; i < exp; ++i)
        result = (result * base) % mod;
    return result;
}

// Naive function to find modular inverse of e mod phi
int modInverse(int e, int phi) {
    for (int d = 1; d < phi; ++d)
        if ((e * d) % phi == 1)
            return d;
    return -1; // No modular inverse found
}

int main() {
    int p, q;

    // Step 1: Input two prime numbers
    cout << "Enter two distinct prime numbers (e.g., 3 and 11): ";
    cin >> p >> q;

    if (!isPrime(p) || !isPrime(q) || p == q) {
        cout << "Both numbers must be distinct and prime.\n";
        return 1;
    }

    // Step 2: Compute n and phi(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Step 3: Input a valid public exponent e
    int e;
    cout << "Enter public exponent e such that 1 < e < " << phi << " and gcd(e, " << phi << ") = 1: ";
    cin >> e;

    if (e <= 1 || e >= phi || gcd(e, phi) != 1) {
        cout << "Invalid e. It must be between 1 and phi and co-prime with phi.\n";
        return 1;
    }

    // Step 4: Compute private key d (modular inverse of e)
    int d = modInverse(e, phi);
    if (d == -1) {
        cout << "No modular inverse found for e. Choose a different e.\n";
        return 1;
    }

    // Step 5: Display keys
    cout << "\nPublic Key: (" << e << ", " << n << ")";
    cout << "\nPrivate Key: (" << d << ", " << n << ")\n";

    // Step 6: Input message to encrypt
    int msg;
    cout << "Enter numeric message to encrypt (less than " << n << "): ";
    cin >> msg;

    if (msg >= n) {
        cout << "Message must be less than n.\n";
        return 1;
    }

    // Step 7: Encrypt and Decrypt
    int encrypted = modPow(msg, e, n);
    int decrypted = modPow(encrypted, d, n);

    cout << "Encrypted message: " << encrypted << "\n";
    cout << "Decrypted message: " << decrypted << "\n";

    return 0;
}
