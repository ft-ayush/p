/*
    Name : Ayush Pandey
    Roll No : 3317

    ASSIGNMENT-6
    Problem Statement :
        Implement any one of the following Expert System
            I.   Information management
            II.  Hospitals and medical facilities
            III. Help desks management
            IV.  Employee performance evaluation
            V.   Stock market trading
            VI.  Airline scheduling and cargo schedules
*/

#include <iostream>
#include <string>

using namespace std;

// Function to get user input (y/n)
bool askQuestion(string question) {
    string answer;
    cout << question << " (y/n): ";
    cin >> answer;
    return (answer == "y" || answer == "Y");
}

int main() {
    cout << "=== Employee Performance Evaluation Expert System ===" << endl;

    char moreEmployees;
    do {
        // Asking performance-related questions
        bool punctuality = askQuestion("Is the employee punctual?");
        bool taskCompletion = askQuestion("Does the employee complete tasks on time?");
        bool teamwork = askQuestion("Does the employee work well in a team?");
        bool leadership = askQuestion("Does the employee exhibit leadership qualities?");
        bool innovation = askQuestion("Does the employee show innovation and creativity?");

        // Evaluate Performance Based on Rules
        if (punctuality && taskCompletion && teamwork && leadership && innovation) {
            cout << "\nEmployee Performance: EXCELLENT" << endl;
        }
        else if (punctuality && taskCompletion && teamwork && (!leadership || !innovation)) {
            cout << "\nEmployee Performance: GOOD" << endl;
        }
        else if (punctuality && !taskCompletion && teamwork && (!leadership || !innovation)) {
            cout << "\nEmployee Performance: AVERAGE" << endl;
        }
        else if (!punctuality && !taskCompletion && !teamwork && !leadership && !innovation) {
            cout << "\nEmployee Performance: POOR" << endl;
        }
        else if ((!punctuality || !taskCompletion || !teamwork) && leadership && innovation) {
            cout << "\nEmployee Performance: HAS POTENTIAL BUT NEEDS IMPROVEMENT" << endl;
        }
        else {
            cout << "\nEmployee Performance: NEEDS SIGNIFICANT IMPROVEMENT" << endl;
        }

        // Ask if another employee needs to be evaluated
        cout << "\nWould you like to evaluate another employee? (y/n): ";
        cin >> moreEmployees;

    } while (moreEmployees == 'y' || moreEmployees == 'Y');

    return 0;
}
