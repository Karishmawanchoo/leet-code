#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
 int findMaxConsecutiveOnes(vector<int>& nums) {
 int count=0,max=0;
 int s=0,e=0,n=nums.size();
 while(s<n && e<n){
  if(nums[s]==1){
   e=e+1;
   while(e<n && nums[e]==1){
    e++;
   }
  }
  count=e-s;
  if(count>max){
   max=count;
  }
  s=e+1;
  e=e+1;
 }
  return max;
 }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,0,1,1,1};
    cout << s.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}