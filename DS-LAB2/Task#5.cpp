#include<iostream>
using namespace std;

int main()
{
	int courses[4] = {3,4,2,1};
	string dept[4] = {"SE", "AI", "CS", "DS"};
	
	double* gpa[4];
	for(int i = 0; i < 4; i++)
	{
		gpa[i] = new double[courses[i]];
	}
	
	for(int i = 0; i < 4; i++)
	{
		cout << "enter gpa for " << dept[i] << " courses: " << endl;
		for(int j = 0; j < courses[i]; j++)
		{
			cout << "Courses " << j+1 << ": ";
			cin >> gpa[i][j]; 
		}
	}
	
	for(int i = 0; i < 4; i++)
	{
		cout << endl << dept[i] << " -> ";
		for (int j = 0; j < courses[i]; j++)
		{
			cout << gpa[i][j] << " ";
		}
		cout << endl;
	}
	
	for(int i = 0; i < 4; i++)
	{
		delete[] gpa[i];
	}
	
	return 0;
}