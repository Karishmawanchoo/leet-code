#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int MinsoFar(vector<int>& prices) {
        int minSoFar = prices[0];
        int ans = 0;
        for(int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - minSoFar;
            if(profit > ans) {
                ans = profit;
            }
            minSoFar = min(prices[i], minSoFar);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input
    int maxProfit = solution.MinsoFar(prices);
    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}






