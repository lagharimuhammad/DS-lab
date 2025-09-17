#include<iostream>
using namespace std;

void selectionSort(int arr[], int val)
{
    for(int i = 0; i < val; i++)
    {
        int min = i;
        for(int j = i+1; j < val-1; j++)
        {
            if(arr[j] < arr[min])
            min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int arr[10];
    for(int i = 0; i < 10; i++)
    {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }
    selectionSort(arr, 10);

    for(int i = 0; i < 4; i++)
    {
        cout << "Element " << i+1 << ": " << arr[i]<< endl;
    }
}
