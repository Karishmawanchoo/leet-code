/*Given the head of a linked list, return the node where the cycle begins. 
If there is no cycle, return null. There is a cycle in a linked list if there 
is some node in the list that can be reached again by continuously following 
the next pointer. Internally, pos is used to denote the index of the node that 
tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. 
Note that pos is not passed as a parameter. Do not modify the linked list.*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) { // cycle detected
                slow = head; // reset slow to the head
                while (slow != fast) { // find the entrance of the cycle
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // the start of the cycle
            }
        }
        
        return nullptr; // no cycle
    }
};

int main() {
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);
    
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; // Cycle here

    Solution solution;
    ListNode* cycleNode = solution.detectCycle(head);

    if (cycleNode) {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }  
  return 0;
}
