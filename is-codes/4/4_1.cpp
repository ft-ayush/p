#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// Function to compute GCD (Greatest Common Divisor) using Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to compute modular inverse of e mod φ(n) using Extended Euclidean Algorithm
int modInverse(int e, int phi) {
    int t = 0, newt = 1;
    int r = phi, newr = e;
    while (newr != 0) {
        int quotient = r / newr;
        int temp = newt;
        newt = t - quotient * newt;
        t = temp;

        temp = newr;
        newr = r - quotient * newr;
        r = temp;
    }
    if (r > 1) return -1; // e is not invertible
    if (t < 0) t += phi;
    return t;
}

// Function to perform modular exponentiation (base^exp mod mod)
// Efficient for large numbers
int modPow(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) // if exp is odd
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Check if a number is prime (naive method)
bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); ++i)
        if (num % i == 0)
            return false;
    return true;
}

int main() {
    // Step 1: Choose two distinct prime numbers p and q
    int p, q;
    cout << "Enter two distinct prime numbers (e.g., 3 and 11): ";
    cin >> p >> q;

    if (!isPrime(p) || !isPrime(q) || p == q) {
        cout << "Invalid input. Both numbers must be distinct primes.\n";
        return 1;
    }

    // Step 2: Compute n = p * q
    int n = p * q;

    // Step 3: Compute Euler's totient function φ(n) = (p-1)*(q-1)
    int phi = (p - 1) * (q - 1);

    // Step 4: Choose e such that 1 < e < φ(n) and gcd(e, φ(n)) = 1
    int e;
    cout << "Enter a public key exponent e such that 1 < e < " << phi << " and gcd(e, " << phi << ") = 1: ";
    cin >> e;

    if (e <= 1 || e >= phi || gcd(e, phi) != 1) {
        cout << "Invalid e. It must satisfy 1 < e < φ(n) and gcd(e, φ(n)) = 1.\n";
        return 1;
    }

    // Step 5: Compute d, the modular inverse of e mod φ(n)
    int d = modInverse(e, phi);
    if (d == -1) {
        cout << "Modular inverse not found. Try different e.\n";
        return 1;
    }

    // Display the public and private keys
    cout << "\nPublic Key: (" << e << ", " << n << ")\n";
    cout << "Private Key: (" << d << ", " << n << ")\n";

    // Step 6: Encrypt a message (must be a number less than n)
    int msg;
    cout << "\nEnter a numeric message to encrypt (less than " << n << "): ";
    cin >> msg;

    if (msg >= n) {
        cout << "Message must be less than n.\n";
        return 1;
    }

    // Encryption: c = m^e mod n
    int encrypted = modPow(msg, e, n);
    cout << "Encrypted message: " << encrypted << "\n";

    // Decryption: m = c^d mod n
    int decrypted = modPow(encrypted, d, n);
    cout << "Decrypted message: " << decrypted << "\n";

    return 0;
}

/*
Input:
p = 3, q = 11
e = 7
msg = 9

Output:
Public Key: (7, 33)
Private Key: (3, 33)
Encrypted message: 15
Decrypted message: 9
*/