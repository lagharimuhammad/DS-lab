#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
public:
    vector<int> heap;

    MaxHeap(vector<int> arr)
    {
        heap = arr;
        buildHeap();
    }

    void buildHeap()
    {
        for (int i = heap.size() / 2 - 1; i >= 0; i--)
            heapifyDown(i);
    }

    void heapifyDown(int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;
        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i)
    {
        int parent = (i - 1) / 2;
        if (i > 0 && heap[i] > heap[parent])
        {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

    void update_key(int index, int new_val)
    {
        int old = heap[index];
        heap[index] = new_val;

        if (new_val > old)
            heapifyUp(index);
        else
            heapifyDown(index);
    }

    void delete_element(int index)
    {
        heap[index] = heap.back();
        heap.pop_back();
        heapifyDown(index);
    }

    void print()
    {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main()
{
    vector<int> arr = {8, 7, 6, 5, 4};

    MaxHeap h(arr);

    cout << "Original Max Heap: ";
    h.print();

    h.update_key(3, 10);
    cout << "After update_key(3,10): ";
    h.print();

    h.delete_element(1);
    cout << "After delete_element(1): ";
    h.print();

    return 0;
}