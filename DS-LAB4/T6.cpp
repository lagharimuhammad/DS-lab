#include<iostream>
using namespace std;

void sortArray(int array[], int size)
{
	
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - 1 - i; j++)
		{
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	
}

int searchArray(int array[], int size, int key)
{
	int left = 0, right = size - 1;
	while (left <= right) 
	{
		int mid = left + (right - left) / 2;
		if (array[mid] == key) 	
		{
			return mid;
		}
		else if (array[mid] < key) 
		{
			left = mid + 1;
		}
		else 
		{
			right = mid - 1;
		}
	}
return -1;
}

int sortAndSearch(int array[], int size, int target)
{
	sortArray(array,size);
	int pos = searchArray(array,size,target);
	return pos;
}

int main()
{
	int size = 10, target;
	int arr[size] = {22, 33, 39, 07, 9, 40, 05, 15, 67, 44};
	
	cout << "Enter target: ";
	cin >> target;
	
	for(int x = 0; x < size; x++)
	cout << arr[x] << " ";
	
	cout << endl;
	
	int index = sortAndSearch(arr,size,target);
	
	if(index == -1)
	{
	cout << "target not found" << endl;
	arr[size] = target;
	size++;
	index = sortAndSearch(arr,size,target);
	}
	
	cout << "Target found at position: " << index << endl;
	
	for(int x = 0; x < size; x++)
	cout << arr[x] << " ";
	
}