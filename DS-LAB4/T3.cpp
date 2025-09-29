#include<iostream>
#include<string>
using namespace std;

int main()
{
	int num = 10;
	string array[num] = {"banana", "cherry", "apple", "mango", "grape", "date", "pomegranate", "pineapple", "orange", "peach"};
	
	for(int i = 0; i < num - 1; i++)
	{
		for(int j = 0; j < num - 1 - i; j++)
		{
			if(array[j] > array[j+1])
			{
				string temp = array[j];
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