#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
 int findMaxConsecutiveOnes(vector<int>& nums) {
  int sum=0,mSum=0;
  for(int i=0;i<nums.size();i++)
  {
   if(nums[i]==0)
   {
    sum=0;
   }
   else{
    sum+=1;
    if(sum>mSum)
     mSum=sum;
   }
  }
  return mSum;
 }
};

int main(){
    Solution s;
    vector<int> nums={1,1,0,1,1,1};
    cout<<s.findMaxConsecutiveOnes(nums)<<endl;
    return 0;
}