#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;

bool isSafe(int n, int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(int n, int row) {
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(n, row, col)) {
            board[row][col] = 1;

            if (solveNQueens(n, row + 1))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (board[i][j] ? 'Q' : '.') << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter value of N: ";
    cin >> n;

    board.assign(n, vector<int>(n, 0));

    if (solveNQueens(n, 0))
        printBoard(n);
    else
        cout << "No solution exists for N = " << n << endl;

    return 0;
}
