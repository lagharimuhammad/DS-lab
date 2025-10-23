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
    q.en(1);
    q.en(2);
    q.en(3);
    q.d();
    cout << "\n";
    q.de();
    q.d();
}