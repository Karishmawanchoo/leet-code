/*Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.*/
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        while (fastPointer != nullptr && fastPointer->next != nullptr) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        return slowPointer;
    }
};
ListNode* createList(const vector<int>& values) {
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
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5, 6};
    ListNode* head = createList(values);

    Solution solution;
    ListNode* middle = solution.middleNode(head);

    if (middle) {
        cout << "Middle node value: " << middle->val << endl;
        cout << "List from middle node: ";
        printList(middle);
    } else {
        cout << "The list is empty." << endl;
    }
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
