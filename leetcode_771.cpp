#include<iostream>
#include<string>
using namespace std;
class Solution{
    public:
    int numjewelsAndstones(string jewels, string stones){
        int count = 0;
        for(int i = 0; i < jewels.length(); i++){
            for(int j = 0; j < stones.length(); j++){
                if(jewels[i] == stones[j]){
                    count++;
                }
            }
        }
        return count++;
    }
};
int main(){
    string jewels = "aA";
    string stones = "aAAbbbb";
    Solution s;
    cout << "Output : " << s.numjewelsAndstones(jewels, stones) << endl;
    return 0;
}