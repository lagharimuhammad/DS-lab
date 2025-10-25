#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

Node *getTail(Node *cur)
{
    while (cur != nullptr && cur->next != nullptr)
        cur = cur->next;
    return cur;
}

Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *prev = nullptr;
    Node *cur = head;
    Node *tail = pivot;

    *newHead = nullptr;
    *newEnd = pivot;

    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if (*newHead == nullptr)
                *newHead = cur;
            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev != nullptr)
                prev->next = cur->next;

            Node *temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if (*newHead == nullptr)
        *newHead = pivot;

    *newEnd = tail;

    return pivot;
}

Node *quickSortRecur(Node *head, Node *end)
{
    if (!head || head == end)
        return head;

    Node *newHead = nullptr, *newEnd = nullptr;

    Node *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {
        Node *temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = nullptr;

        newHead = quickSortRecur(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node **headRef)
{
    if (*headRef == nullptr)
        return;
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
}

void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    push(&head, 3);
    push(&head, 5);
    push(&head, 1);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 10);

    cout << "Original List:" << endl;
    printList(head);
    quickSort(&head);
    cout << "Sorted List:" << endl;
    printList(head);

    return 0;
}