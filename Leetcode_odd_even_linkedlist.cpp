//lets say you have 10 , 13,14,16,18,20 elements in to your list
//display even and odd element from the list
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int value;
    Node* next; 
    Node(int data) {
        value = data;
        next = nullptr;
    }
};
void insertAtFirst(Node*& head, int value) {
    Node* new_node = new Node(value);
    new_node->next = head; 
    head = new_node; 
}
void displayEvenOdd(Node* head) {
    cout << "Even elements are : " << endl;
    Node* temp = head;
    while(temp!=NULL){
        if (temp->value % 2 == 0) {
            cout << temp->value << " ";
        }
        temp = temp->next;
    }
    cout << endl;

    cout << "Odd elements are : " << endl;
    temp = head;
    while(temp!=NULL){
        if (temp->value % 2 != 0) {
            cout << temp->value << " ";
        }
        temp = temp->next;
    }
    cout << endl;
    
}
int main() {
    Node* n1 = new Node(10);
    Node* n2 = new Node(13);
    Node* n3 = new Node(14);
    Node* n4 = new Node(16);
    Node* n5 = new Node(18);
    Node* n6 = new Node(20);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    Node* head = n1;
    displayEvenOdd(head);
    // insertAtFirst(head, 20);
    // display(head);
    return 0;
}
