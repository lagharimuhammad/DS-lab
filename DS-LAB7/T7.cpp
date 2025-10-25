#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons = 0;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partitionFirst(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

int partitionRandom(int arr[], int low, int high)
{
    int pivotIndex = low + rand() % (high - low + 1);
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int partitionMiddle(int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    int pivot = arr[mid];
    swap(arr[mid], arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int medianOfThree(int a, int b, int c)
{
    if ((a > b && a < c) || (a < b && a > c))
        return a;
    if ((b > a && b < c) || (b < a && b > c))
        return b;
    return c;
}

int partitionMedian(int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    int pivotVal = medianOfThree(arr[low], arr[mid], arr[high]);
    int pivotIndex = (pivotVal == arr[low]) ? low : (pivotVal == arr[mid] ? mid : high);
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int method)
{
    if (low < high)
    {
        int pi;
        if (method == 1)
            pi = partitionFirst(arr, low, high);
        else if (method == 2)
            pi = partitionRandom(arr, low, high);
        else if (method == 3)
            pi = partitionMiddle(arr, low, high);
        else
            pi = partitionMedian(arr, low, high);

        quickSort(arr, low, pi - 1, method);
        quickSort(arr, pi + 1, high, method);
    }
}

void copyArray(int src[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    srand(time(0));
    int arr[] = {90, 40, 70, 10, 30, 80, 50, 60, 100, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[10];

    cout << "Original Array:" << endl;
    printArray(arr, n);

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 1);
    cout << "\nFirst Element Pivot: " << endl << comparisons << endl;
    printArray(temp, n);

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 2);
    cout << "\nRandom Pivot: " << endl << comparisons << endl;
    printArray(temp, n);

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 3);
    cout << "\nMiddle Element Pivot: " << endl << comparisons << endl;
    printArray(temp, n);

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 4);
    cout << "\nMedian of Three Pivot: " << endl << comparisons << endl;
    printArray(temp, n);

    return 0;
}