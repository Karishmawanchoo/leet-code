//Given the head of a singly linked list, return true if it is a palindrome 
//or false otherwise
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> listVals;
        while (head) {
            listVals.push_back(head->val);
            head = head->next;
        }      
        int left = 0, right = listVals.size() - 1;
        while (left < right) {
            if (listVals[left] != listVals[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution solution;
    cout << (solution.isPalindrome(head) ? "True" : "False") << endl;
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
    return 0;
}
