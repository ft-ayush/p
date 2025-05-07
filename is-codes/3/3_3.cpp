#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Function to compute (base^exp) % mod using naive method
int naivePowerMod(int base, int exp, int mod) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return result;
}

// Function to check if g is a primitive root modulo p
bool isPrimitiveRoot(int g, int p) {
    set<int> seen; // to store remainders

    for (int i = 1; i < p; i++) {
        int val = naivePowerMod(g, i, p);
        if (seen.find(val) != seen.end()) {
            return false; // duplicate found — not a primitive root
        }
        seen.insert(val);
    }

    return true;
}

// Function to find the smallest primitive root modulo p
int findPrimitiveRoot(int p) {
    for (int g = 2; g < p; g++) {
        if (isPrimitiveRoot(g, p)) {
            return g;
        }
    }
    return -1; // No primitive root found (should not happen for prime p)
}

int main() {
    int p;

    cout << "Enter a prime number p: ";
    cin >> p;

    int primitiveRoot = findPrimitiveRoot(p);

    if (primitiveRoot != -1) {
        cout << "The smallest primitive root modulo " << p << " is: " << primitiveRoot << endl;
    } else {
        cout << "No primitive root found for " << p << "." << endl;
    }

    return 0;
}


/*
Output:

Enter a prime number p: 23
The smallest primitive root modulo 23 is: 5
*/