#include <iostream>
using namespace std;
struct Node
{
    char val;
    Node *next;
};
struct Stack
{
    Node *top;
    Stack() { top = NULL; }
    void push(char c)
    {
        Node *n = new Node;
        n->val = c;
        n->next = top;
        top = n;
    }
    char pop()
    {
        char c = top->val;
        Node *t = top;
        top = top->next;
        delete t;
        return c;
    }
    bool e() { return top == NULL; }
    char p() { return top ? top->val : 0; }
};
int pr(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}
int main()
{
    char in[] = "a+b*(c^d-e)^(f+g*h)-i", out[100];
    int k = 0;
    Stack s;
    for (int i = 0; in[i]; i++)
    {
        char c = in[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            out[k++] = c;
        else if (c == '(')
            s.push(c);
        else if (c == ')')
        {
            while (!s.e() && s.p() != '(')
                out[k++] = s.pop();
            s.pop();
        }
        else
        {
            while (!s.e() && pr(s.p()) >= pr(c))
                out[k++] = s.pop();
            s.push(c);
        }
    }
    while (!s.e())
        out[k++] = s.pop();
    out[k] = 0;
    cout << out;
}