#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* arrayToLinkedList(const vector<int>& vals)
{
    if (vals.empty()) return nullptr;
    Node* head = new Node(vals[0]);
    Node* curr = head;
    for (int i = 1; i < (int)vals.size(); i++)
    {
        curr->next = new Node(vals[i]);
        curr = curr->next;
    }
    return head;
}

void deleteList(Node* head)
{
    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool checkPalindrome(Node* headNode)
{
    if (!headNode || !headNode->next)
        return true;

    Node* slowPtr = headNode;
    Node* fastPtr = headNode;
    while (fastPtr->next && fastPtr->next->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    Node* prevNode = nullptr;
    Node* currentNode = slowPtr->next;
    while (currentNode)
    {
        Node* nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }

    Node* left = headNode;
    Node* right = prevNode;
    while (right)
    {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->next;
    }

    return true;
}

int main()
{
    vector<vector<int>> testCases = {
        {1, 2, 3, 2, 1},
        {1, 2, 2, 1},
        {1, 2, 3, 4, 5},
        {1},
        {}
    };

    for (auto& test : testCases)
    {
        Node* head = arrayToLinkedList(test);
        bool result = checkPalindrome(head);
        cout << "List: ";
        for (int v : test) cout << v << " ";
        cout << (result ? "-> Is a palindrome" : "-> Not a palindrome") << "\n";
        deleteList(head);
    }

    return 0;
}
