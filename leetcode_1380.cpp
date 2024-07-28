/*Given an m x n matrix of distinct numbers, return all lucky numbers 
in the matrix in any order. A lucky number is an element of the matrix such 
that it is the minimum element in its row and maximum in its column.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();

        vector<int> rowMin;
        for (int i = 0; i < N; i++) {

            int rMin = INT_MAX;
            for (int j = 0; j < M; j++) {
                rMin = min(rMin, matrix[i][j]);
            }
            rowMin.push_back(rMin);
        }

        vector<int> colMax;
        for (int i = 0; i < M; i++) {

            int cMax = INT_MIN;
            for (int j = 0; j < N; j++) {
                cMax = max(cMax, matrix[j][i]);
            }
            colMax.push_back(cMax);
        }

        vector<int> luckyNumbers;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    luckyNumbers.push_back(matrix[i][j]);
                }
            }
        }

        return luckyNumbers;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};
    vector<int> result = solution.luckyNumbers(matrix);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}