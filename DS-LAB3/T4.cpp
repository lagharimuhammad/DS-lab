#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value, Node *nextNode = nullptr)
    {
        data = value;
        next = nextNode;
    }
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

Node* arrayToLinkedList(vector<int> values)
{
    Node* headNode = new Node(values[0]);
    Node* currentNode = headNode;
    for (int i = 1; i < values.size(); i++)
    {
        Node* newNode = new Node(values[i]);
        currentNode->next = newNode;
        currentNode = newNode;
    }
    return headNode;
}

void displayList(Node* headNode)
{
    Node* currentNode = headNode;
    if (!currentNode)
    {
        cout << "The list is empty.\n";
        return;
    }
    while (currentNode != nullptr)
    {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

Node* rearrangeList(Node* headNode)
{
    Node* evenHead = nullptr, *evenTail = nullptr;
    Node* oddHead = nullptr, *oddTail = nullptr;

    Node* currentNode = headNode;

    while (currentNode != nullptr)
    {
        if (currentNode->data % 2 == 0)
        {
            if (evenHead == nullptr)
            {
                evenHead = currentNode;
                evenTail = currentNode;
            }
            else
            {
                evenTail->next = currentNode;
                evenTail = evenTail->next;
            }
        }
        else
        {
            if (oddHead == nullptr)
            {
                oddHead = currentNode;
                oddTail = currentNode;
            }
            else
            {
                oddTail->next = currentNode;
                oddTail = oddTail->next;
            }
        }
        currentNode = currentNode->next;
    }

    if (evenHead == nullptr)
        return oddHead;
    if (oddHead == nullptr)
        return evenHead;

    evenTail->next = oddHead;
    oddTail->next = nullptr;

    return evenHead;
}

int main()
{
    vector<int> numbers = {8, 12, 10, 4};
    Node* headNode = arrayToLinkedList(numbers);
    headNode = rearrangeList(headNode);
    displayList(headNode);

    numbers = {1, 2, 4, 7, 5, 8, 10, 12, 13};
    headNode = arrayToLinkedList(numbers);
    headNode = rearrangeList(headNode);
    displayList(headNode);

    return 0;
}
