#include <iostream>
using namespace std;

const int SIZE = 4;

int grid[SIZE][SIZE] = 
{
    {1, 1, 1, 1},
    {0, 0, 0, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 1}
};

bool visited[SIZE][SIZE];

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

bool isSafe(int row, int col) 
{
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE &&grid[row][col] == 1 && !visited[row][col]);
}

bool findPath(int row, int col, int targetRow, int targetCol) 
{
    if (row == targetRow && col == targetCol) 
	{
        return true;
    }

    visited[row][col] = true;

    for (int d = 0; d < 4; d++) {
        int nextRow = row + dirX[d];
        int nextCol = col + dirY[d];

        if (isSafe(nextRow, nextCol)) 
		{
            if (findPath(nextRow, nextCol, targetRow, targetCol)) 
			{
                return true;
            }
        }
    }

    visited[row][col] = false;
    return false;
}

int main() 
{
    int startRow = 0, startCol = 0;
    int endRow = 2, endCol = 0;

    for (int i = 0; i < SIZE; i++) 
	{
        for (int j = 0; j < SIZE; j++) 
		{
            visited[i][j] = false;
        }
    }

    if (findPath(startRow, startCol, endRow, endCol)) 
	{
        cout << "Path exists" << endl;
    } 
	else 
	{
        cout << "No path exists" << endl;
    }

    return 0;
}
