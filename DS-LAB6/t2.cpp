#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

struct Transaction
{
    int id;
    float amt;
    char desc[30];
    int flag;
    Transaction *next;
};

struct Stack
{
    Transaction *top;
    int count;
    Stack()
    {
        top = NULL;
        count = 0;
    }
    void push(float a, const char *d)
    {
        Transaction *t = new Transaction;
        t->id = ++count;
        t->next = top;
        top = t;
        int len = strlen(d);
        if (len > 20)
        {
            strncpy(t->desc, d, 17);
            t->desc[17] = '.';
            t->desc[18] = '.';
            t->desc[19] = '.';
            t->desc[20] = '\0';
        }
        else
            strcpy(t->desc, d);
        if (a >= 0)
        {
            if (a >= 1500)
                a -= a * 0.3;
            else if (a >= 1000)
                a -= a * 0.15;
            else if (a >= 500)
                a -= a * 0.05;
            t->flag = 1;
        }
        else
            t->flag = 0;
        t->amt = a;
    }
    Transaction pop()
    {
        Transaction temp = *top;
        Transaction *del = top;
        top = top->next;
        delete del;
        temp.amt *= -1;
        strcat(temp.desc, " [REVERSED]");
        temp.flag = 2;
        return temp;
    }
    void display()
    {
        Transaction *c = top;
        while (c)
        {
            cout << "[" << c->id << ", " << c->amt << ", " << c->desc << ", " << c->flag << "]\n";
            c = c->next;
        }
    }
};

char s2[50];
int top2 = -1;
void pushc(char c) { s2[++top2] = c; }
char popc() { return s2[top2--]; }
int prec(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}
void infixtopost(char in[], char out[])
{
    int k = 0;
    for (int i = 0; in[i]; i++)
    {
        if ((in[i] >= '0' && in[i] <= '9') || in[i] == '.')
            out[k++] = in[i];
        else if (in[i] == '(')
            pushc(in[i]);
        else if (in[i] == ')')
        {
            out[k++] = ' ';
            while (top2 != -1 && s2[top2] != '(')
            {
                out[k++] = popc();
                out[k++] = ' ';
            }
            top2--;
        }
        else if (in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/')
        {
            out[k++] = ' ';
            while (top2 != -1 && prec(s2[top2]) >= prec(in[i]))
            {
                out[k++] = popc();
                out[k++] = ' ';
            }
            pushc(in[i]);
        }
    }
    while (top2 != -1)
    {
        out[k++] = ' ';
        out[k++] = popc();
    }
    out[k] = '\0';
}

float s3[50];
int top3 = -1;
void pushf(float x) { s3[++top3] = x; }
float popf() { return s3[top3--]; }
float eval(char *p)
{
    for (int i = 0; p[i];)
    {
        if ((p[i] >= '0' && p[i] <= '9') || p[i] == '.')
        {
            float v = 0;
            float d = 0.1;
            int dot = 0;
            while ((p[i] >= '0' && p[i] <= '9') || p[i] == '.')
            {
                if (p[i] == '.')
                    dot = 1;
                else if (!dot)
                    v = v * 10 + (p[i] - '0');
                else
                {
                    v += d * (p[i] - '0');
                    d /= 10;
                }
                i++;
            }
            pushf(v);
        }
        else if (p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/')
        {
            float b = popf(), a = popf();
            if (p[i] == '+')
                pushf(a + b);
            else if (p[i] == '-')
                pushf(a - b);
            else if (p[i] == '*')
                pushf(a * b);
            else
                pushf(a / b);
            i++;
        }
        else
            i++;
    }
    return s3[top3];
}

int main()
{
    srand(time(0));
    struct Pre
    {
        float amt;
        const char *desc;
    } arr[7] = {
        {1200, "Sale: Kurta"}, 
        {450, "Sale: Chappal"}, 
        {-300, "Refund: Torn Shirt"}, 
        {1700, "Sale: Shalwar Kameez"}, 
        {800, "Sale: Sandel"}, 
        {-500, "Refund: Damaged Shoes"}, 
        {1600, "Sale: Waistcoat"}};
    Stack st;
    for (int i = 0; i < 4; i++)
    {
        int r = rand() % 7;
        st.push(arr[r].amt, arr[r].desc);
    }
    cout << "Pushed Transactions:\n";
    st.display();
    char in[] = "(100+20)*0.9-5", out[50];
    infixtopost(in, out);
    cout << "\nExpression Result: " << eval(out) << "\n";
    Transaction t = st.pop();
    cout << "\nReversed Transaction:\n"
         << t.desc << ", " << t.amt << ", " << t.flag << "\n";
    cout << "\nRemaining Stack:\n";
    st.display();
}