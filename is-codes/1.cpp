#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    
    // Taking user input
    cout << "Enter a string: ";
    getline(cin, input);
    
    string andResult = "", xorResult = "";

    // Applying bitwise AND and XOR with 127
    for (char c : input) {
        andResult += static_cast<char>(c & 127);
        xorResult += static_cast<char>(c ^ 127);
    }

    // Displaying the results
    cout << "\nOriginal String: " << input;
    cout << "\nBitwise AND with 127: " << andResult;
    cout << "\nBitwise XOR with 127: " << xorResult;

    return 0;
}
