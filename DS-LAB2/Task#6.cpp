#include<iostream>
#include<string>
using namespace std;

int main()
{
	int rows;
	cout << "Number of rows, enter pls: ";
	cin >> rows;
	
	string** seatPlan = new string*[rows];
	
	int* seatNumber = new int[rows];
	
	for(int i = 0; i < rows; i++)
	{
		cout << "Enter number of seats in " << i+1 << " row: ";
		cin >> seatNumber[i];
		
		seatPlan[i] = new string[seatNumber[i]];
	}
	
	cin.ignore();
	
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < seatNumber[i]; j++)
		{
			cout << "Enter name for seat (" << i+1 << "," << j+1 << "): ";
			getline(cin, seatPlan[i][j]);
		}
	}
	
	for(int i = 0; i < rows; i++)
	{
		cout << "Row " << i+1 << "-> ";
		for(int j = 0; j < seatNumber[i]; j++)
		{
			cout << seatPlan[i][j] << ", ";
		}
		cout << "\n";
	}
	
	for(int i = 0; i < rows; i++)
	{
		delete[] seatPlan[i];
	}
	delete[] seatPlan;
	delete[] seatNumber;
	
	return 0;
}