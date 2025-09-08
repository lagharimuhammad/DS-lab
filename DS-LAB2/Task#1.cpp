#include<iostream>
using namespace std;

class Matrix
{
	int rows;
	int columns;
	int** matrix;
	
	public:
	
	Matrix(int r, int c)
	{
		allocate(r,c);
	}
	
	~Matrix()
	{
		deallocate();
	}
		
	void allocate(int row, int col)
	{
		rows = row;
		columns = col;
		
		matrix = new int*[rows];
		for(int i = 0; i < rows; i++)
		{
			matrix[i] = new int[columns];
		}
		
		//initially, set all values to 0
		
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	
	void enterValues()
	{
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				cout << " Enter value at " << i << "th row and " << j << "th column: " << endl;
				cin >> matrix[i][j];
		    }
		}
	}
	
	void deallocate()
	{
		for(int i = 0; i < rows; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	
	void resize(int newRow, int newCol)
	{
		int** newMatrix = new int*[newRow];
		for(int i = 0; i < newRow; i++)
		{
			newMatrix[i] = new int[newCol];
			for(int j = 0; j < newCol; j++)
			{
				if(i < rows && j < columns)
				{
					newMatrix[i][j] = matrix[i][j];
				}
				else 
				{
					newMatrix[i][j] = 0;
				}
				
			}
		}
		
		deallocate();
		matrix = newMatrix;
		columns = newCol;
		rows = newRow;
	}
	
	void transpose()
	{
		int** newMatrix = new int*[columns];
		for(int i = 0; i < columns; i++)
		{
			newMatrix[i] = new int[rows];
			for(int j = 0; j < rows; j++)
			{
				newMatrix[i][j] = matrix[j][i];
			}
		}
			
		deallocate();
		matrix = newMatrix;
		int t = rows;
		rows = columns;
		columns = t;
	}
	
	void print()
	{
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				int s = i + j;
				if(s % 2 == 1)
				{
					cout << matrix[i][j] + 2 << " ";
				}
				else 
				{
					cout << matrix[i][j] << " ";
				}
			}
			cout << endl;
		}
	}
	
};

int main()
{
	int i,j;
	cout << "Enter you rows and columns: " << endl;
	cin >> i >> j;
	Matrix m(i,j);
	
	m.enterValues();
	m.print();
	
	int ni, nj;
	cout << "Enter you new rows and new columns: " << endl;
	cin >> ni >> nj;
	m.resize(ni,nj);
	cout << "New matrix: " << endl;
	m.print();
	
	
	cout<< "Transpose: " << endl;
	m.transpose();
	m.print();
	
	return 0;
}