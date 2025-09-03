#include<iostream>
#include<string.h>
using namespace std;

class Exam 
{
	char* name;
	char* date;
	float marks;
	
	public:
		Exam(const char* n, const char* d, float m ) 
		{
			name = new char[strlen(n + 1)];
			strcpy(name,n);
			date = new char[strlen(d + 1)];
			strcpy(date, d);
			marks = m; 
		}
		
		~Exam()
		{
			delete[] name;
			delete[] date;
		}
		
		void display()
		{
			cout << "Student name: " << name << endl;
			cout << " Date: "  << date << endl;
			cout << "SCore: " << marks << endl;
		}
};

int main()
{
	Exam e1("Baqar", "3/9/2025", 78.2);
	cout << "First Instance" << endl;
	e1.display();
	
	Exam e2 = e1;
	cout << "Shallow copied" << endl;
	e2.display();
	
	return 0;
}