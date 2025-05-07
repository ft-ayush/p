#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string encrypt(string plaintext, int key) {
    string ciphertext = "";
    int len = plaintext.length();
    while (len % key != 0) {
        plaintext += '_';
        len++;
    }
    for (int col = 0; col < key; col++) {
        for (int row = 0; row < len / key; row++) {
            ciphertext += plaintext[row * key + col];
        }
    }
    return ciphertext;
}




string decrypt(string ciphertext, int key) {
    string plaintext = "";
    int len = ciphertext.length();
    int rows = len / key;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < key; col++) {
            plaintext += ciphertext[col * rows + row];
        }
    }
   
    plaintext.erase(remove(plaintext.begin(),plaintext.end(),'_'),plaintext.end());
    return plaintext;
}





int main() {
    string text = "HELLOTRANSPOSITIONPRIYANSHU7344";
    int key = 5;
    cout << "Original Text: " << text << endl;
    string encrypted = encrypt(text, key);
    cout << "Encrypted Text: " << encrypted << endl;
    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted Text: " << decrypted << endl;
    return 0;
}
