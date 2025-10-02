#include <iostream>
using namespace std;

const int N = 4;
bool* col_used;
bool* diag1;
bool* diag2;
int max_flags = 0;

void backtrack(int row, int placed) 
{
    if (row == N) 
	{
        if (placed > max_flags) 
		{
			max_flags = placed;
		}
        return;
    }
    backtrack(row + 1, placed);
    
    for (int c = 0; c < N; c++) 
	{
        int d1 = row + c;
        int d2 = row - c + N - 1;
        
        if (!col_used[c] && !diag1[d1] && !diag2[d2]) 
		{
            col_used[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            backtrack(row + 1, placed + 1);
            col_used[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
}

int main() 
{
    col_used = new bool[N];
    diag1 = new bool[2 * N - 1];
    diag2 = new bool[2 * N - 1];
    for (int i = 0; i < N; i++) 
	{
		col_used[i] = false;
	}
		
    for (int i = 0; i < 2 * N - 1; i++) 
	{
        diag1[i] = false;
        diag2[i] = false;
    }
    backtrack(0, 0);
    cout << max_flags << endl;
    
    delete[] col_used;
    delete[] diag1;
    delete[] diag2;
    return 0;
}