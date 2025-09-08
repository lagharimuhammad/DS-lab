#include<iostream>
using namespace std;

int main()
{
	int** Database = new int*[5];
	for(int i = 0; i < 5; i++)
	{
		Database[i] = new int[4];
	}
	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			cout << "Enter Student " << i+1 << " score in " << j+1 << " course: ";
			cin >> Database[i][j];
			cout << endl;
		}
	}
	
	//for total per student
	for(int i = 0; i < 5; i++)
	{
		int total = 0;
		for(int j = 0; j < 4; j++)
		{
			total += Database[i][j];
		}
		
		cout << "Total of student " << i + 1 << " is: " << total << endl;
	}
	
	//for average per subject
	for(int i = 0; i < 4; i++)
	{
		int sum = 0;
		for(int j = 0; j < 5; j++)
		{
			sum += Database[j][i];
		}
		float average = sum/5.0;
        cout << "Course " << i+1 << " average: " << average << endl;
	}
	
	// for topper
	int totalPerStudent[5] = {0};
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			totalPerStudent[i] += Database[i][j];
		}
	}
	
	int max = 0;
	int index = -1;
	for(int i = 0; i < 5; i++)
	{
		if(totalPerStudent[i] > max)
		{
			max = totalPerStudent[i];
			index = i+1;
		}
	}
	
	cout << index << " Student is the topper";
	
	for(int i = 0; i < 5; i++)
	{
		delete[] Database[i];
	}
	delete[] Database;
	
	return 0;
}