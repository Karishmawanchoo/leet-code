//SORTING THE SENTENCE
#include <iostream>
#include <string>
#include <unordered_map>  
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        unordered_map<int, string> mp;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            int pos = word.back() - '0';  
            word.pop_back();  
            mp[pos] = word;  
        }

        string result = "";
        for (int i = 1; i <= mp.size(); i++) {
            result += mp[i];
            if (i != mp.size()) {
                result += " ";
            }
        }
        return result;
    }
};

int main() {
    string s;
    cout << "Enter the string: " << endl;
    getline(cin, s);
    Solution sol; 
    cout << sol.sortSentence(s) << endl;  
    return 0;
}
