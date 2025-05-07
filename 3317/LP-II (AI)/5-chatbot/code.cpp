/*
    Name : Ayush Pandey
    Roll No : 3317

    ASSIGNMENT-5
    Problem Statement :
        Develop an elementary chatbot for any suitable customer interaction
        application.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to convert input to lowercase for better matching
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Chatbot function
void chat() {
    string input;
    cout << "Customer Support Chatbot (Type 'bye' to exit)\n";

    while (true) {
        cout << "You: ";
        getline(cin, input);
        input = toLowerCase(input);  // Convert input to lowercase

        if (input == "bye" || input == "exit" || input == "quit") {
            cout << "Chatbot: Goodbye! Have a great day!\n";
            break;
        } else if (input == "hi" || input == "hello" || input == "hey") {
            cout << "Chatbot: Hello! How can I help you today?\n";
        } else if (input == "what is your name?") {
            cout << "Chatbot: I am a simple chatbot created for customer support.\n";
        } else if (input == "how can i contact customer service?") {
            cout << "Chatbot: You can reach customer service at support@example.com or call +1-800-123-4567.\n";
        } else if (input == "what are your working hours?") {
            cout << "Chatbot: Our support team is available from 9 AM to 6 PM, Monday to Friday.\n";
        } else {
            cout << "Chatbot: I'm sorry, I don't understand that. Can you rephrase your question?\n";
        }
    }
}

// Main function
int main() {
    chat();
    return 0;
}