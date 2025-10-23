#include <iostream>
#include <cstring>
using namespace std;
struct Node
{
    char data[50];
    Node *next;
};
struct Stack
{
    Node *top;
    Stack() { top = NULL; }
    bool empty() { return top == NULL; }
    void push(const char *s)
    {
        Node *n = new Node;
        strcpy(n->data, s);
        n->next = top;
        top = n;
    }
    void pop()
    {
        if (top)
        {
            Node *t = top;
            top = top->next;
            delete t;
        }
    }
    char *peek() { return top ? top->data : (char *)""; }
};
int main()
{
    Stack s;
    s.push("Meeting");
    cout << (s.empty() ? "Empty\n" : "Not empty\n");
    cout << s.peek() << "\n";
    s.pop();
    cout << (s.empty() ? "Empty\n" : "Not empty\n");
}