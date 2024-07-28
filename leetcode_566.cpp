/*n MATLAB, there is a handy function called reshape which can reshape an m x n 
matrix into a new one with a different size r x c keeping its original data.
You are given an m x n matrix mat and two integers r and c representing the 
number of rows and the number of columns of the wanted reshaped matrix.
The reshaped matrix should be filled with all the elements of the original
matrix in the same row-traversing order as they were. If the reshape 
operation with given parameters is possible and legal, output the new reshaped 
matrix; Otherwise, output the original matrix.*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c);
};

vector<vector<int>> Solution::matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size();      // Number of rows in original matrix
    int n = mat[0].size();   // Number of columns in original matrix

    // Check if reshape is possible
    if (m * n != r * c) {
        return mat;
    }

    vector<vector<int>> reshapedMatrix(r, vector<int>(c, 0));
    int row = 0, column = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            reshapedMatrix[row][column] = mat[i][j];
            ++column;
            if (column == c) {
                column = 0;
                ++row;
            }
        }
    }

    return reshapedMatrix;
}

int main() {
    Solution sol;
    int m, n, r, c;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    cin >> r >> c;
    vector<vector<int>> reshaped = sol.matrixReshape(mat, r, c);

    for (const auto& row : reshaped) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
