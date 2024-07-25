//Given an array of meeting time intervals where intervals[i]=[starti, endi],
//determine if a person could attend all meetings.
//input = [[0,30],[5,10],[15,20]]
//output= false
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canAttendMeetings(vector<vector<int>>& intervals) {
    if (intervals.empty()) return true;

    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return false; 
        }
    }
    return true;
}

int main() {
    vector<vector<int>> intervals = {{7,10}, {2,4}};
    bool result = canAttendMeetings(intervals);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
