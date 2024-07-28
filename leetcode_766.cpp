/*Given an m x n matrix, return true if the matrix is Toeplitz. 
Otherwise, return false.A matrix is Toeplitz if every diagonal from top-left 
to bottom-right has the same elements.*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int temp =matrix[0][0];
         for(int i=1;i<matrix.size();i++){
             for(int j=1;j<matrix[0].size();j++){
             if(matrix[i-1][j-1]!=matrix[i][j])
                 return false;
             }
         }
        return true;
    }
};
int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,2,3,4},{5,1,
    2,3},{9,5,1,2} };
    cout<<boolalpha<<s.isToeplitzMatrix(matrix)<<endl;
}