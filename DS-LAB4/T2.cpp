#include<iostream>
using namespace std;

int main()
{
	int num = 9;
	int array[num] = {20, 12, 15, 2, 10, 1, 13, 9, 5};
	
	for(int i = 1; i < num; i++)
	{
		int k = array[i];
		int j = i-1;
		while( j >= 0 && array[j] > k)
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = k;
	}
	
	// after sorting all
	
	int val = array[num-1];
	for(int i = num - 1; i > num/2; i--)
	{
		array[i] = array[i-1];
	}
	array[num/2] = val;
	
	for(int i = 0; i < num; i++)
	cout << array[i] << " " ;
	
}