#include <iostream>
#include <set>

using namespace std;

// ------------------------- Utility Functions -----------------------------

// Naive function to compute (base^exp) % mod
int naivePowerMod(int base, int exp, int mod) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return result;
}

// Check if g is a primitive root modulo p
bool isPrimitiveRoot(int g, int p) {
    set<int> seen;
    for (int i = 1; i < p; i++) {
        int val = naivePowerMod(g, i, p);
        if (seen.find(val) != seen.end()) {
            return false;
        }
        seen.insert(val);
    }
    return true;
}

// Find the smallest primitive root modulo p
int findPrimitiveRoot(int p) {
    for (int g = 2; g < p; g++) {
        if (isPrimitiveRoot(g, p)) {
            return g;
        }
    }
    return -1;
}

// ------------------------- Main Program ----------------------------------

int main() {
    // Step 1: Choose a small prime number
    int p;
    cout << "Enter a small prime number (p): ";
    cin >> p;

    // Step 2: Find primitive root g
    int g = findPrimitiveRoot(p);
    if (g == -1) {
        cout << "Failed to find a primitive root for p = " << p << endl;
        return 1;
    }

    cout << "\nPublicly known values:\n";
    cout << "Prime number (p): " << p << endl;
    cout << "Primitive root (g): " << g << endl;

    // Step 3: Choose private keys (secret)
    int a, b;
    cout << "\nEnter Alice's private key (a): ";
    cin >> a;
    cout << "Enter Bob's private key (b): ";
    cin >> b;

    // Step 4: Generate public keys
    int A = naivePowerMod(g, a, p); // Alice sends A = g^a % p
    int B = naivePowerMod(g, b, p); // Bob sends B = g^b % p

    cout << "\nPublic keys exchanged:\n";
    cout << "Alice sends A = " << A << endl;
    cout << "Bob sends B = " << B << endl;

    // Step 5: Compute shared secrets
    int secretAlice = naivePowerMod(B, a, p);
    int secretBob   = naivePowerMod(A, b, p);

    cout << "\nShared secret keys computed:\n";
    cout << "Alice's secret key: " << secretAlice << endl;
    cout << "Bob's secret key: " << secretBob << endl;

    // Step 6: Confirm if both match
    if (secretAlice == secretBob) {
        cout << "\n✅ Success! Shared secret key is: " << secretAlice << endl;
    } else {
        cout << "\n❌ Error: Shared secrets do not match!" << endl;
    }

    return 0;
}


/*
Enter a small prime number (p): 23

Publicly known values:
Prime number (p): 23
Primitive root (g): 5

Enter Alice's private key (a): 6
Enter Bob's private key (b): 15

Public keys exchanged:
Alice sends A = 8
Bob sends B = 2

Shared secret keys computed:
Alice's secret key: 2
Bob's secret key: 2

✅ Success! Shared secret key is: 2
*/