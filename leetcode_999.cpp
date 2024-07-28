/*You are given an 8 x 8 matrix representing a chessboard. There is exactly one 
white rook represented by 'R', some number of white bishops 'B', and some number of 
black pawns 'p'. Empty squares are represented by '.'.
A rook can move any number of squares horizontally or vertically (up, down, left, right) 
until it reaches another piece or the edge of the board. A rook is attacking a pawn if it 
can move to the pawn's square in one move.
Note: A rook cannot move through other pieces, such as bishops or pawns. This means 
a rook cannot attack a pawn if there is another piece blocking the path.
Return the number of pawns the white rook is attacking.*/
#include <bits/stdc++.h>
using namespace std;
int numRookCaptures(vector<vector<char>>& board) {
    int rookRow = -1, rookCol = -1;
    // Find the position of the rook 'R'
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == 'R') {
                rookRow = i;
                rookCol = j;
                break;
            }
        }
        if (rookRow != -1) break;
    }
    int captures = 0;
    // Check upwards
    for (int i = rookRow - 1; i >= 0; --i) {
        if (board[i][rookCol] == 'B') break;   // Bishop blocks the path
        if (board[i][rookCol] == 'p') {
            captures++;
            break;  // Capture the pawn and stop
        }
    }
    // Check downwards
    for (int i = rookRow + 1; i < 8; ++i) {
        if (board[i][rookCol] == 'B') break;
        if (board[i][rookCol] == 'p') {
            captures++;
            break;
        }
    }
    // Check left
    for (int j = rookCol - 1; j >= 0; --j) {
        if (board[rookRow][j] == 'B') break;
        if (board[rookRow][j] == 'p') {
            captures++;
            break;
        }
    }
    // Check right
    for (int j = rookCol + 1; j < 8; ++j) {
        if (board[rookRow][j] == 'B') break;
        if (board[rookRow][j] == 'p') {
            captures++;
            break;
        }
    }
    return captures;
}

int main() {
    vector<vector<char>> board = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'.', '.', '.', 'R', '.', '.', '.', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'}
    };
    cout << numRookCaptures(board) << endl; // Output: 3
    return 0;
}