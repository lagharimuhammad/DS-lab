#include<iostream>
using namespace std;

int main()
{
	int num;
	cout << "How many children birth year are there: ";
	cin >> num;
	int array[num];
	
	for(int i = 0; i < num; i++)
	{
		cout << "Enter year number " << i+1 << ": ";
		cin >> array[i];
	}
	
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
	
	cout << "| ";
	for(int i = 0; i < num; i++)
	{
		cout << array[i] << " | ";
	}
}