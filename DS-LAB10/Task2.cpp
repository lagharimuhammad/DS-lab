#include <iostream>
#include <vector>
using namespace std;

bool isMaxHeap(const vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i <= n / 2 - 1; i++)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[i] < arr[l])
            return false;
        if (r < n && arr[i] < arr[r])
            return false;
    }
    return true;
}

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    vector<int> arr = {8, 7, 6, 5, 4};

    cout << (isMaxHeap(arr) ? "Array is a Max Heap\n" : "Array is NOT a Max Heap\n");

    heapSort(arr);

    cout << "Sorted (ascending): ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
