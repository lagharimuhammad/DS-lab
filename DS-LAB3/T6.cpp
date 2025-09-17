#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val, Node* nextNode = nullptr)
    {
        data = val;
        next = nextNode;
    }
};

Node* arrayToLinkedList(const vector<int>& values)
{
    if (values.empty()) return nullptr;
    Node* head = new Node(values[0]);
    Node* current = head;
    for (int i = 1; i < (int)values.size(); i++)
    {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}

void printList(Node* head)
{
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* deleteNodeAtPosition(Node* head, int position)
{
    if (!head) return nullptr;
    if (position == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    Node* previous = nullptr;
    int count = 1;

    while (current != nullptr && count < position)
    {
        previous = current;
        current = current->next;
        count++;
    }

    if (current)
    {
        previous->next = current->next;
        delete current;
    }

    return head;
}

int main()
{
    vector<int> arr = {2, 3, 5, 4, 7};
    Node* head = arrayToLinkedList(arr);
    head = deleteNodeAtPosition(head, 3);
    printList(head);
    return 0;
}
