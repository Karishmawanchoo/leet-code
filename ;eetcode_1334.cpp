/*There are n cities numbered from 0 to n-1. Given the array edges where 
edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge 
between cities fromi and toi, and given the integer distanceThreshold.
Return the city with the smallest number of cities that are reachable through 
some path and whose distance is at most distanceThreshold, If there are multiple 
such cities, return the city with the greatest number.
Notice that the distance of a path connecting cities i and j is equal to the sum of 
the edges' weights along that path.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max()));
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != numeric_limits<int>::max() && dist[k][j] != numeric_limits<int>::max()) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        int minReachableCities = numeric_limits<int>::max();
        int bestCity = -1;
        
        for (int i = 0; i < n; ++i) {
            int reachableCities = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) {
                    reachableCities++;
                }
            }
            if (reachableCities <= minReachableCities) {
                minReachableCities = reachableCities;
                bestCity = i;
            }
        }
        
        return bestCity;
    }
};

int main() {
    vector<vector<int>> edges = {
        {0, 1, 10}, {0, 2, 20}, {1, 2, 5}, {2, 3, 15}, {3, 4, 10}, {4, 5, 20},
        {5, 6, 15}, {6, 7, 10}, {7, 8, 5}, {8, 9, 20}, {9, 10, 15}, {10, 11, 10},
        {11, 12, 5}, {12, 13, 20}, {13, 14, 15}, {14, 15, 10}, {15, 16, 5},
        {16, 17, 20}, {17, 18, 15}, {18, 19, 10}, {19, 20, 5}
    };
    int n = 21;
    int distanceThreshold = 30;
    
    Solution solution;
    int bestCity = solution.findTheCity(n, edges, distanceThreshold);
    
    cout << "The best city is: " << bestCity << endl;
    
    return 0;
}
