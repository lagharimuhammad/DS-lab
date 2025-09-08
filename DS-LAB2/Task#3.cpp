#include<iostream>
using namespace std;

int main()
{
	int dept;
	cout << "Enter number of departments: ";
	cin >> dept;
	
	int* studentNumber = new int[dept];
	
	int*** courses = new int**[dept];
	
	for(int i = 0; i < dept; i++)
	{
		cout << "Enter student in each Department: ";
		cin >> studentNumber[i];
		
		courses[i] = new int*[studentNumber[i]];
		
		for(int j = 0; j < studentNumber[i]; j++)
		{
			courses[i][j] = new int [5];
		}
	}
	
	for(int i = 0; i < dept; i++)
	{
		cout << "Department " << i+1 << " : " << endl;
		for(int j = 0; j < studentNumber[i]; j++)
		{
			cout << "Student " << 1+j << " gets marks: " << endl;
			for(int k = 0; k < 5; k++)
			{
				cout << "Enter " << k + 1 << " course marks: ";
				cin >> courses[i][j][k];
			}
		}
	}
	
	for(int i = 0; i < dept; i++)
	{
		int high = -999999;
		int low = 999999;
		int sum = 0;
		
		cout << "Departmwnt: " << i + 1 << endl;
		
		for(int j = 0; j < studentNumber[i]; j++)
		{
			int singleSum = 0;
			
			for(int k = 0; k < 5; k++)
			{
				singleSum += courses[i][j][k];
			}
			
			if(singleSum > high)
			{
				high = singleSum;
			}
			
			if(singleSum < low)
			{
				low = singleSum;
			}
			
			sum += singleSum;
		}
		double a = (double)sum/studentNumber[i];
		
		cout << "Highiest: " << high << endl;
		cout << "Lowest: " << low << endl;
		cout << "Average: " << a << endl;
	}
	
	return 0;
}