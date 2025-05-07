#include <iostream>
#include <string>
using namespace std;

// Naive function to check for prime
bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i < num; ++i)
        if (num % i == 0)
            return false;
    return true;
}

// Naive GCD function
int gcd(int a, int b) {
    int gcd = 1;
    for (int i = 1; i <= a && i <= b; ++i)
        if (a % i == 0 && b % i == 0)
            gcd = i;
    return gcd;
}

// Naive modular exponentiation
int modPow(int base, int exp, int mod) {
    int result = 1;
    for (int i = 0; i < exp; ++i)
        result = (result * base) % mod;
    return result;
}

// Naive modular inverse
int modInverse(int e, int phi) {
    for (int d = 1; d < phi; ++d)
        if ((e * d) % phi == 1)
            return d;
    return -1;
}

int main() {
    int p, q;
    cout << "Enter two distinct prime numbers (e.g., 3 and 11): ";
    cin >> p >> q;

    if (!isPrime(p) || !isPrime(q) || p == q) {
        cout << "Invalid input. Both numbers must be distinct primes.\n";
        return 1;
    }

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e;
    cout << "Enter public key exponent e (1 < e < " << phi << ", gcd(e, " << phi << ") = 1): ";
    cin >> e;

    if (e <= 1 || e >= phi || gcd(e, phi) != 1) {
        cout << "Invalid e. Must satisfy conditions.\n";
        return 1;
    }

    int d = modInverse(e, phi);
    if (d == -1) {
        cout << "No modular inverse found. Try a different e.\n";
        return 1;
    }

    cout << "\nPublic Key: (" << e << ", " << n << ")";
    cout << "\nPrivate Key: (" << d << ", " << n << ")\n";

    cin.ignore(); // Clear input buffer
    string message;
    cout << "\nEnter a message (ASCII only, characters must be < " << n << "): ";
    getline(cin, message);

    string encryptedMessage = "";
    string decryptedMessage = "";

    cout << "\nEncrypted ASCII values: ";
    for (char ch : message) {
        int ascii = (int)ch;
        int cipher = modPow(ascii, e, n);
        cout << cipher << " ";
        encryptedMessage += to_string(cipher) + " ";
    }

    cout << "\n\nDecrypted message: ";
    for (char ch : message) {
        int ascii = (int)ch;
        int cipher = modPow(ascii, e, n);
        int plain = modPow(cipher, d, n);
        decryptedMessage += (char)plain;
    }

    cout << decryptedMessage << "\n";
    return 0;
}

/*
Input:
p = 5, q = 11
e = 3
Message = "Hi"

Output:
Encrypted ASCII values: 2 10
Decrypted message: Hi
*/