#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargest(vector<int> arr, int K)
{
    priority_queue<int> pq;

    for (int x : arr)
        pq.push(x);

    while (K-- > 1)
        pq.pop();

    return pq.top();
}

int main()
{
    vector<int> a1 = {1, 23, 12, 9, 30, 2, 50};
    cout << "3rd largest = " << kthLargest(a1, 3) << endl;

    vector<int> a2 = {12, 3, 5, 7, 19};
    cout << "2nd largest = " << kthLargest(a2, 2) << endl;

    return 0;
}
