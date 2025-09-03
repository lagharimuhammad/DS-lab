#include<iostream>
using namespace std;

class BankAccount
{
	double balance;
	
	public:
		
	BankAccount()
	{
		balance = 0.0;
		cout << "Default constr calleed \n";
	}
	
	BankAccount(double initial)
	{
		balance = initial;
		cout << "parameterized constr called \n";
	}
	
	BankAccount(const BankAccount &obj)
	{
		balance = obj.balance;
		cout << "Shallow copy constructor \n";
	}
	
	void deduct(double amount)
	{
		if( amount <= balance)
		{
			balance -= amount;
			cout << "Transaction completed \n";
		}
		else
		{
			cout << "Unsufficeient balance \n";
		}
	}
	
	void display()
	{
		cout << balance << endl;
	}
	
	double returnBalance ()
	{
		return balance;
	}
			
};

int main()
{
	BankAccount a1;
	a1.display();
	
	BankAccount a2(1000);
	a2.display();
	
	BankAccount a3(a2);
	
	a3.deduct(200);
	a3.display();
	a2.display();
	
	return 0;
}