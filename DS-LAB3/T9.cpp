#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* process(Node* head) {
    if (!head || !head->next)
        return head;

    Node* alt_head = head->next;
    Node* prev = head;
    Node* curr = alt_head;

    while (curr && curr->next) {
        prev->next = curr->next;
        prev = prev->next;
        curr->next = prev->next;
        curr = curr->next;
    }

    prev->next = nullptr;

    Node* prev_node = nullptr;
    Node* curr_node = alt_head;
    while (curr_node) {
        Node* next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    Node* reversed_head = prev_node;

    Node* tail = head;
    while (tail->next)
        tail = tail->next;
    tail->next = reversed_head;

    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

int main() {
    // Create linked list: 10->4->9->1->3->5->9->4
    Node* head = new Node(10);
    head->next = new Node(4);
    head->next->next = new Node(9);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next = new Node(4);

    cout << "Original list:\n";
    printList(head);

    head = process(head);

    cout << "Modified list:\n";
    printList(head);

    return 0;
}
