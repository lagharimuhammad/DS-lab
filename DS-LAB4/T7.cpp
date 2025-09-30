#include<iostream>
#include<string>
using namespace std;

int binarySearch(string array[], int size, string key, int &steps)
{
	steps = 0;
	int left = 0, right = size - 1;
	while (left <= right) 
	{
		steps++;
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

int linearSearch(string array[], int size, string key, int &steps)
{
	steps = 0;
	for(int i = 0; i < size; i++)
	{
		steps++;
		if(array[i] == key)
		{
			return i;
		}
	}
	return -1;
}

void sortArray(string array[], int size)
{
	
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - 1 - i; j++)
		{
			if(array[j] > array[j+1])
			{
				string temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	
}

int main()
{
	string arr[] = {"Baqar", "Kashif", "Salman", "Sheraz", "Basit", "Rizwan", "Tariq", "Anwer", "Umair", "Hassan"};
	int size = 10;
	
	sortArray(arr, size);
	
	string keys[] = {"Rizwan", "Amir", "Tariq"};
	
	for(int i = 0; i < 3; i++)
	{ 	int CountB;
		int CountL;
		int indexB = binarySearch(arr, size, keys[i], CountB);
		cout << "In Binary search, for Name: " << keys[i] << ", Index: " << indexB <<", Number of Steps: " << CountB << endl;
		int indexL = linearSearch(arr, size, keys[i], CountL);
		cout << "In Linear search, for Name: " << keys[i] << ", Index: " << indexL <<", Number of Steps: " << CountL << endl;
	}
	/*Binary search is solving problem in fewer steps than linear search,
	 making it more time efficient and faster*/
}