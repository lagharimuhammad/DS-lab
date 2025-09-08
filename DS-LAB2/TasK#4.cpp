#include<iostream>
using namespace std;

int main()
{
	bool friends[5][5] = {
							{0,0,0,1,1},
							{0,0,1,0,1},
							{0,1,0,0,0},
							{1,0,0,0,0},
							{1,1,0,1,0}
						 };
						 
	int f1,f2;
	cout << "Enter person 1 and person 2: ";
	cin >> f1 >> f2;
	
	bool flag = false;
	for(int i = 0; i < 5; i++)
	{
		if(friends[f1][i] && friends[f2][i])
		{
			flag = true;
			break;
		}
	}
	
	if(flag)
	{
		cout << "they are friend";
	}
	else 
		cout << "not friends";
	
	return 0;
}