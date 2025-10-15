#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    char arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char c)
    {
        if (top >= 99)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = c;
    }

    char pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty()
    {
        return top < 0;
    }
};

int main()
{
    string str = "BORROWROB";
    Stack s;

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    string reversed = "";
    while (!s.isEmpty())
    {
        reversed += s.pop();
    }

    cout << reversed << endl;

    if (str == reversed)
    {
        cout << "PALINDROME" << endl;
    }
    else
    {
        cout << "NOT PALINDROME" << endl;
    }

    return 0;

}
