#include <iostream>
using namespace std;

int main() {
    // const char* str = "Hello From Priyanshu";
    const char *str="MY name is ankit";
    cout << "Original String: " << str << "\n\n";
    
    cout << "Character\tAND with 127\tXOR with 127\n";
    cout << "---------\t-------------\t--------------\n";

    for (int i = 0; str[i] != '\0'; ++i) {
        char original = str[i];
        char andResult = original & 127;
        char xorResult = original ^ 127;

        cout << original << "\t\t"
             << andResult << "\t\t"
             << xorResult << "\n";
    }

    return 0;
}

