#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    int score;
    Node *next;
};

void addNode(Node **head, string name, int score)
{
    Node *newNode = new Node{name, score, nullptr};
    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

int getMax(Node *head)
{
    int max = 0;
    while (head != nullptr)
    {
        if (head->score > max)
            max = head->score;
        head = head->next;
    }
    return max;
}

int getDigit(int num, int exp)
{
    return (num / exp) % 10;
}

Node *countingSort(Node *head, int exp)
{
    Node *output[10001] = {nullptr};
    Node *tail[10] = {nullptr};
    Node *curr = head;
    while (curr != nullptr)
    {
        int digit = getDigit(curr->score, exp);
        if (output[digit] == nullptr)
        {
            output[digit] = curr;
            tail[digit] = curr;
        }
        else
        {
            tail[digit]->next = curr;
            tail[digit] = curr;
        }
        curr = curr->next;
    }
    Node *newHead = nullptr;
    Node *last = nullptr;
    for (int i = 0; i < 10; i++)
    {
        if (output[i] != nullptr)
        {
            if (newHead == nullptr)
            {
                newHead = output[i];
                last = tail[i];
            }
            else
            {
                last->next = output[i];
                last = tail[i];
            }
        }
    }
    if (last != nullptr)
        last->next = nullptr;
    return newHead;
}

void radixSort(Node **head)
{
    int maxVal = getMax(*head);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        *head = countingSort(*head, exp);
}

bool deleteRecord(Node **head, string name, int score)
{
    Node *temp = *head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->name == name && temp->score == score)
        {
            if (prev == nullptr)
                *head = temp->next;
            else
                prev->next = temp->next;
            delete temp;
            return true;
        }
        prev = temp;
        temp = temp->next;
    }
    return false;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}

int main()
{
    Node *head = nullptr;
    addNode(&head, "Anwer", 65);
    addNode(&head, "Kashif", 71);
    addNode(&head, "Baqar", 90);
    addNode(&head, "Omer", 95);
    addNode(&head, "Ahmed Jalaal", 88);
    radixSort(&head);
    printList(head);

    string name;
    int score;
    cin >> name >> score;

    if (deleteRecord(&head, name, score))
        printList(head);
    else
        printList(head);

    return 0;
}