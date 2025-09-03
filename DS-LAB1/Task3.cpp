#include<iostream>
using namespace std;

class Box
{
	int* value;
	
	public:
		Box(int v = 0)
		{
			value = new int(v);
			cout << "Constr called" << endl;
		}
		
		~Box()
		{
			delete value;
			cout << "Destructor called" << endl;
		}
		
		Box(const Box &other)
		{
			value = new int(*other.value);
			cout << "Copy constr" << endl;
		}
		
		Box& operator =(const Box& other)
		{
			if(this != &other)
			{
				delete value;
				value = new int(*other.value);
				cout << "copy constr" << endl;
				return *this;
			}
		}
		
		void set(int v)
		{
			*value = v;
		}
		
		int get()
		{
			return *value;
		}
};

int main()
{
	Box b1(100);
	Box b2 = b1;
	Box b3;
	b3 = b1;
	
	cout<<"B1: " << b1.get() << endl;
	cout<<"B2: " << b2.get() << endl;
	cout<<"B3: " << b3.get() << endl;
	
	cout << "Afer Change:" << endl;
	
	b1.set(1);
	cout<<"B1: " << b1.get() << endl;
	cout<<"B2: " << b2.get() << endl;
	cout<<"B3: " << b3.get() << endl;
	return 0;
}