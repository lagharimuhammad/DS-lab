#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

class CircularLinkedList
{
    Node* start;

public:
    CircularLinkedList() : start(nullptr) {}

    void addAtEnd(int val)
    {
        Node* newNode = new Node(val);
        if (!start)
        {
            start = newNode;
            newNode->next = start;
            return;
        }
        Node* curr = start;
        while (curr->next != start)
            curr = curr->next;
        curr->next = newNode;
        newNode->next = start;
    }

    void addAtFront(int val)
    {
        Node* newNode = new Node(val);
        if (!start)
        {
            start = newNode;
            newNode->next = start;
            return;
        }
        Node* curr = start;
        while (curr->next != start)
            curr = curr->next;
        newNode->next = start;
        curr->next = newNode;
        start = newNode;
    }

    void addAtPosition(int val, int pos)
    {
        if (pos == 1)
        {
            addAtFront(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* curr = start;
        int idx = 1;
        while (idx < pos - 1 && curr->next != start)
        {
            curr = curr->next;
            idx++;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void removeByValue(int val)
    {
        if (!start)
            return;

        Node* curr = start;
        Node* prev = nullptr;

        if (start->value == val)
        {
            if (start->next == start)
            {
                delete start;
                start = nullptr;
                return;
            }
            Node* temp = start;
            while (temp->next != start)
                temp = temp->next;
            temp->next = start->next;
            Node* toDelete = start;
            start = start->next;
            delete toDelete;
            return;
        }

        do
        {
            prev = curr;
            curr = curr->next;
            if (curr->value == val)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }
        } while (curr != start);
    }

    void display()
    {
        if (!start)
        {
            cout << "List is empty.\n";
            return;
        }
        Node* curr = start;
        cout << "Circular List: ";
        do
        {
            cout << curr->value << " ";
            curr = curr->next;
        } while (curr != start);
        cout << "\n";
    }
};

int main()
{
    CircularLinkedList clist;
    clist.addAtEnd(10);
    clist.addAtEnd(20);
    clist.addAtEnd(30);
    clist.display();

    clist.addAtFront(5);
    clist.display();

    clist.addAtPosition(15, 3);
    clist.display();

    clist.removeByValue(20);
    clist.display();

    clist.removeByValue(5);
    clist.display();

    clist.removeByValue(100);  
    clist.display();

    return 0;
}
