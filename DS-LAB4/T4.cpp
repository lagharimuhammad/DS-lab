#include<iostream>
using namespace std;

bool duplicatorDetector(int array[], int num)
{
	for(int i = 0; i < num - 1; i++)
	{
		for(int j = 0; j < num - 1 - i; j++)
		{
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	
	for(int i = 0; i < num; i++)
	{
		if(array[i] == array[i+1])
		{
			return true;
		}
	}
	
	return false;
}

int main()
{
	int num = 10;
	int array1[num] = {0, 2, 4, 6, 8, 1, 3, -7, 11, -3};
	int array2[num] = {0, 2, 4, 6, 8, 0, 3, -7, 11, -3};
	
	
	cout << "Array 1: " << endl;
	if(duplicatorDetector(array1,num))
	{
		cout << "There are duplicates";
	}
	else
	{
		cout << "There are no duplicates";
	}
	
	cout << endl << "Array 2: " << endl;
	if(duplicatorDetector(array2,num))
	{
		cout << "There are duplicates";
	}
	else
	{
		cout << "There are no duplicates";
	}
}