#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate numeric key order
vector<int> getKeyOrder(string key) {
    vector<pair<char, int>> keyOrder;
    vector<int> order(key.length());

    for (int i = 0; i < key.length(); i++) {
        keyOrder.push_back({key[i], i});
    }
    sort(keyOrder.begin(), keyOrder.end());

    for (int i = 0; i < key.length(); i++) {
        order[keyOrder[i].second] = i;
    }
    return order;
}

// Encryption function
string encrypt(string text, string key) {
    int col = key.length();
    int row = (text.length() + col - 1) / col; // Calculate required rows
    vector<int> order = getKeyOrder(key);

    // Fill matrix row-wise
    vector<vector<char>> matrix(row, vector<char>(col, ' '));
    int index = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (index < text.length()) {
                matrix[i][j] = text[index++];
            }
        }
    }

    // Read column-wise based on key order
    string ciphertext = "";
    for (int i = 0; i < col; i++) {
        int colIdx = find(order.begin(), order.end(), i) - order.begin();
        for (int j = 0; j < row; j++) {
            if (matrix[j][colIdx] != ' ')
                ciphertext += matrix[j][colIdx];
        }
    }
    return ciphertext;
}

// Decryption function
string decrypt(string ciphertext, string key) {
    int col = key.length();
    int row = (ciphertext.length() + col - 1) / col;
    vector<int> order = getKeyOrder(key);

    // Fill matrix column-wise
    vector<vector<char>> matrix(row, vector<char>(col, ' '));
    int index = 0;
    for (int i = 0; i < col; i++) {
        int colIdx = find(order.begin(), order.end(), i) - order.begin();
        for (int j = 0; j < row; j++) {
            if (index < ciphertext.length()) {
                matrix[j][colIdx] = ciphertext[index++];
            }
        }
    }

    // Read row-wise to get plaintext
    string plaintext = "";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] != ' ')
                plaintext += matrix[i][j];
        }
    }
    return plaintext;
}

// Driver function
int main() {
    string plaintext = "HELLOTRANSPOSITION";
    string key = "3214"; // Key used for transposition

    string encryptedText = encrypt(plaintext, key);
    cout << "Encrypted Text: " << encryptedText << endl;

    string decryptedText = decrypt(encryptedText, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

/*
Encrypted Text: LOHOSNRLTEPTANISIO
Decrypted Text: HELLOTRANSPOSITION
*/