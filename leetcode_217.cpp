/*Given an integer array nums, return true if any value appears at 
least twice in the array, and return false if every element is distinct.
Example 1: Input: nums = [1,2,3,1] ; Output: true
Example 2: Input: nums = [1,2,3,4] ; Output: false
Example 3: Input: nums = [1,1,1,3,3,4,3,2,4,2] ; Output: true*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> a(nums.begin(),nums.end());
        return (nums.size()!=a.size());
    }
};
int main(){
    Solution s;
    vector<int> v1 = {1,2,3,1};
    vector<int> v2 = {1,2,3,4};
    vector<int> v3 = {1,1,1,3,3,4,3,2,4,2};
    cout<<boolalpha<<s.containsDuplicate(v1)<<endl; // true
    cout<<boolalpha<<s.containsDuplicate(v2)<<endl; // false
    cout<<boolalpha<<s.containsDuplicate(v3)<<endl; // false
    return 0;
}