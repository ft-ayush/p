#include <iostream>
using namespace std;

const int MAX = 20;        // Max board size (can be adjusted)
int board[MAX][MAX] = {0}; // Initialize with 0

// Check if placing a queen at board[row][col] is safe
bool isSafe(int row, int col, int n)
{
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Recursive function to solve N-Queens
bool solveNQueens(int row, int n)
{
    if (row == n)
        return true;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, n))
        {
            board[row][col] = 1;

            if (solveNQueens(row + 1, n))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

// Print the board
void printSolution(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the board size (n): ";
    cin >> n;

    if (solveNQueens(0, n))
    {
        cout << "Solution exists:\n";
        printSolution(n);
    }
    else
    {
        cout << "No solution exists\n";
    }

    return 0;
}
