#include <iostream>

using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim) 
{
    int sum = 0;
    if (dim == 1) 
	{
        int current_size = *sizes;
        
        for (int i = 0; i < current_size; i++) 
		{
            sum += *arr[i];
        }
        return sum;
    }
    int current_size = *sizes;
    
    for (int i = 0; i < current_size; i++) 
	{
        sum += recursiveArraySum((int**)arr[i], sizes + 1, dim - 1);
    }
    return sum;
}

int main() 
{
    int dim = 2;
    int rows = 2;
    int cols = 3;
    
    int* sizes = new int[dim];
    sizes[0] = rows;
    sizes[1] = cols;
    
    int** outer = new int*[rows];
    
    for (int j = 0; j < rows; j++) 
	{
        int** row = new int*[cols];
        
        for (int k = 0; k < cols; k++) 
		{
            row[k] = new int(j * cols + k + 1);
        }
        outer[j] = (int*)row;
    }
    int total_sum = recursiveArraySum(outer, sizes, dim);
    
    cout << total_sum << endl;
    for (int j = 0; j < rows; j++) 
	{
        int** row = (int**)outer[j];
        
        for (int k = 0; k < cols; k++) 
		{
            delete row[k];
        }
        delete[] row;
    }
    
    delete[] outer;
    delete[] sizes;
    return 0;
}
