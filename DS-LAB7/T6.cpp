#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n, int exp)
{
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr1[10] = {45, 95, 75, 65, 15, 5, 10, 70, 30, 10};
    int arr2[10] = {75, 65, 40, 80, 100, 5, 45, 85, 95, 30};

    cout << "Combined Array: " << endl;
    int combined[20];
    for (int i = 0; i < 10; i++)
        combined[i] = arr1[i];
    for (int i = 0; i < 10; i++)
        combined[i + 10] = arr2[i];

    printArray(combined, 20);

    int arrRadix[20];
    int arrMerge[20];
    for (int i = 0; i < 20; i++)
    {
        arrRadix[i] = combined[i];
        arrMerge[i] = combined[i];
    }

    radixSort(arrRadix, 20);
    mergeSort(arrMerge, 0, 19);

    cout << endl << "Sorted using Radix Sort:" << endl;
    printArray(arrRadix, 20);

    cout << endl << "Sorted using Merge Sort:" << endl;
    printArray(arrMerge, 20);

    return 0;
}
