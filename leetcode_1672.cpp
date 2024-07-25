#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution{
public:
 int maximumWealth(vector<vector<int>>& accounts) {
  int total=0;
  int sum=0;
  for(int i=0;i<accounts.size();i++){
   // for(int j=0;j<accounts[0].size();j++){
   // sum+=accounts[i][j];
   // }
   // if(sum>max){
   // max=sum;
   // }
   // sum=0;
   sum=accumulate(accounts[i].begin(),accounts[i].end(),0);
   // if(sum>max){
   // max=sum;
   // }
    total=max(total,sum);
   sum=0;
  }
  return total;
}
};
int main(){
    Solution s;
    vector<vector<int>> accounts={{1,2,3},{3,2,1}};
    cout<<"Maximum wealth is : "<<s.maximumWealth(accounts)<<endl;
    return 0;
}