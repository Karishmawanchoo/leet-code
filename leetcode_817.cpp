/*You are given the head of a linked list containing unique integer values 
and an integer array nums that is a subset of the linked list values.
Return the number of connected components in nums where two values are 
connected if they appear consecutively in the linked list.*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        
        int ans = 0;
        bool inComponent = false;
        while (head) {
            if (st.count(head->val)) {
                if (!inComponent) {
                    ans++;
                    inComponent = true;
                }
            } else {

                inComponent = false;
            }
            head = head->next;
        }
        return ans;
    }
};
