#include <iostream>
#include <cstring>
using namespace std;
struct Node
{
    char url[30];
    Node *next;
};
struct LL
{
    Node *head;
    LL() { head = NULL; }
    void addFront(const char *s)
    {
        Node *n = new Node;
        strcpy(n->url, s);
        n->next = head;
        head = n;
    }
    void delFront()
    {
        if (head)
        {
            Node *t = head;
            head = head->next;
            delete t;
        }
    }
};
struct Stack
{
    Node *top;
    Stack() { top = NULL; }
    void push(const char *s)
    {
        Node *n = new Node;
        strcpy(n->url, s);
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
    char *peek() { return top ? top->url : (char *)""; }
};
int main()
{
    const char *s[5] = {"Google", "Facebook", "X", "Snapchat", "Instagram"};
    LL l;
    Stack st;
    for (int i = 0; i < 5; i++)
    {
        l.addFront(s[i]);
        st.push(s[i]);
    }
    st.pop();
    l.delFront();
    st.pop();
    l.delFront();
    cout << st.peek();
}