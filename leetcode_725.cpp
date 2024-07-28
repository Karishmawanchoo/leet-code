/*Given the head of a singly linked list and an integer k, split the linked 
list into k consecutive linked list parts.
The length of each part should be as equal as possible: no two parts should have a
size differing by more than one. This may lead to some parts being null.
The parts should be in the order of occurrence in the input list, and parts occurring 
earlier should always have a size greater than or equal to parts occurring later.
Return an array of the k parts.*/
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int n = 0;
        while (curr) {
            curr = curr->next;
            n++;
        }
        int q = n / k; 
        int r = n % k; 

        vector<int> iLen(k, q); 
        fill(iLen.begin(), iLen.begin() + r, q + 1);

        vector<ListNode*> ans(k);
        curr = head;
        for (int i = 0; i < k; i++) {
            ans[i] = curr;
            for (int j = 0; j < iLen[i] - 1; j++) {
                if (curr) curr = curr->next;
            }
            if (curr) {
                ListNode* prev = curr;
                curr = curr->next;
                prev->next = nullptr;
            }
        }
        return ans;
    }
};

ListNode* createList(vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int value : values) {
        if (!head) {
            head = new ListNode(value);
            tail = head;
        } else {
            tail->next = new ListNode(value);
            tail = tail->next;
        }
    }
    return head;
}
void printListParts(vector<ListNode*>& parts) {
    for (ListNode* part : parts) {
        ListNode* current = part;
        while (current) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode* head = createList(values);

    int k = 3; 

    Solution solution;
    vector<ListNode*> parts = solution.splitListToParts(head, k);
    printListParts(parts);
    for (ListNode* part : parts) {
        while (part) {
            ListNode* next = part->next;
            delete part;
            part = next;
        }
    }

    return 0;
}
