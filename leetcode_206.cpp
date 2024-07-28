//Reverse linked list
#include<bits/stdc++.h>
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* forward = curr->next; // Save the next node
            curr->next = prev;              // Reverse the current node's pointer
            prev = curr;                    // Move prev to current node
            curr = forward;                 // Move to the next node
        }
        return prev; 
    }
};
int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);
    ListNode* temp = reversedHead;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    while (reversedHead != NULL) {
        ListNode* next = reversedHead->next;
        delete reversedHead;
        reversedHead = next;
    }
    return 0;
}
