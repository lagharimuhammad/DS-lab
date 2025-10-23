#include <iostream>
using namespace std;
struct Node
{
    float val;
    Node *next;
};
struct Stack
{
    Node *top;
    Stack() { top = NULL; }
    void push(float v)
    {
        Node *n = new Node;
        n->val = v;
        n->next = top;
        top = n;
    }
    float pop()
    {
        float v = top->val;
        Node *t = top;
        top = top->next;
        delete t;
        return v;
    }
};
int main()
{
    Stack s;
    s.push(12);
    s.push(13);
    float a = s.pop(), b = s.pop();
    float r = b + a - 5 * (0.5 + 0.5) + 1;
    cout << "x = " << r;
}