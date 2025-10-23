#include <iostream>
using namespace std;
struct Q
{
    int a[20];
    int f, r;
    Q() { f = r = -1; }
    void en(int x)
    {
        if (r == 19)
            return;
        if (f == -1)
            f = 0;
        a[++r] = x;
    }
    void de()
    {
        if (f == -1 || f > r)
            return;
        f++;
    }
    void d()
    {
        for (int i = f; i <= r; i++)
            cout << a[i] << " ";
    }
};
int main()
{
    Q q;
    int id[7] = {13, 7, 4, 1, 6, 8, 10};
    for (int i = 0; i < 7; i++)
        q.en(id[i]);
    q.de();
    q.de();
    q.d();
}