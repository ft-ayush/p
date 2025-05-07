/*
    Name : Ayush Pandey
    Roll No : 3317

    ASSIGNMENT-4
    Problem Statement :
        Implement a solution for a Constraint Satisfaction Problem using Branch
        and Bound and Backtracking for n-queens problem or a graph coloring
        problem.
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_N 15 // Maximum board size

// ---------------------------- PRINT FUNCTIONS ----------------------------

void printSolution(const vector<vector<int>> &board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

void printCompactSolution(const vector<int> &queenCol, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (queenCol[i] == j ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// ---------------------------- BACKTRACKING SOLUTION ----------------------------

bool isSafeBacktracking(vector<vector<int>> &board, int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i][col]) return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) return false;
    }
    return true;
}

bool solveNQueensBacktracking(vector<vector<int>> &board, int row, int N) {
    if (row == N) {
        printSolution(board, N);
        return true;
    }

    bool foundSolution = false;
    for (int col = 0; col < N; col++) {
        if (isSafeBacktracking(board, row, col, N)) {
            board[row][col] = 1;
            foundSolution |= solveNQueensBacktracking(board, row + 1, N);
            board[row][col] = 0; // Backtrack
        }
    }

    return foundSolution;
}

// ---------------------------- BRANCH & BOUND (ROW-WISE, O(N) SPACE) ----------------------------

bool solveNQueensBranchBoundRowWise(int row, int N, vector<bool> &colUsed, vector<bool> &upperDiag, vector<bool> &lowerDiag, vector<int> &queenCol) {
    if (row == N) {
        printCompactSolution(queenCol, N);
        return true;
    }

    bool foundSolution = false;
    for (int col = 0; col < N; col++) {
        int upIdx = row + col;
        int lowIdx = row - col + N - 1;

        if (!colUsed[col] && !upperDiag[upIdx] && !lowerDiag[lowIdx]) {
            queenCol[row] = col;
            colUsed[col] = upperDiag[upIdx] = lowerDiag[lowIdx] = true;

            foundSolution |= solveNQueensBranchBoundRowWise(row + 1, N, colUsed, upperDiag, lowerDiag, queenCol);

            // Backtrack
            colUsed[col] = upperDiag[upIdx] = lowerDiag[lowIdx] = false;
        }
    }

    return foundSolution;
}

// ---------------------------- MENU FUNCTION ----------------------------

void menu() {
    int choice, N;
    do {
        cout << "\n===== N-Queens Problem Solver =====\n";
        cout << "1. Solve using Backtracking\n";
        cout << "2. Solve using Branch & Bound (row-wise, O(N) space)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        }

        cout << "Enter value of N (board size): ";
        cin >> N;
        
        if (N < 1 || N > MAX_N) {
            cout << "Invalid input! Please enter N between 1 and " << MAX_N << ".\n";
            continue;
        }

        if (choice == 1) {
            vector<vector<int>> board(N, vector<int>(N, 0));
            cout << "\nSolving using Backtracking:\n";
            if (!solveNQueensBacktracking(board, 0, N)) {
                cout << "No solution found for N = " << N << " using Backtracking.\n";
            }
        } 
        else if (choice == 2) {
            vector<bool> colUsed(N, false), upperDiag(2 * N - 1, false), lowerDiag(2 * N - 1, false);
            vector<int> queenCol(N, -1);
            cout << "\nSolving using Branch & Bound (row-wise, O(N) space):\n";
            if (!solveNQueensBranchBoundRowWise(0, N, colUsed, upperDiag, lowerDiag, queenCol)) {
                cout << "No solution found for N = " << N << " using Branch & Bound.\n";
            }
        } 
        else {
            cout << "Invalid choice! Please select a valid option.\n";
        }

    } while (choice != 3);
}

// ---------------------------- MAIN FUNCTION ----------------------------

int main() {
    menu();
    return 0;
}


/*
Backtracking:
TC = O(N * N!)
SC = O(N^2) + O(N) for the recursion stack.

Branch & Bound:
TC = O(N!) but fast due to pruning
SC = O(N) + O(N) for the recursion stack.
*/