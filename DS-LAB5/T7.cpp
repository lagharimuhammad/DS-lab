#include<iostream>
using namespace std;

#define N 5

void print(int arr[N][N])
{
	for(int i = 0; i < N; i++)
	{
		cout << "| ";
		for(int j = 0; j < N; j++)
		{
			cout << arr[i][j] << " |";
		}
		cout << endl;
	}
}
/////////////////////////////
bool isSafe(int x, int y, int maze[N][N])
{
	return ( x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}
//////////////////////////////
bool solveGame(int maze[N][N], int x, int y, int working[N][N])
{
	if(x == N-1 && y == N-1 && maze[x][y] == 1)
	{
		working[x][y] = 1;
		print(working);
		working[x][y] = 0;
		return true;
	}
	
	if(isSafe(x,y,maze))
	{
		working[x][y] = 1;
		
		if(solveGame(maze,x+1,y,working)) //down
			return true;
			
		if(solveGame(maze,x,y+1,working)) //right
			return true;
			
		if(solveGame(maze,x-1,y,working)) //up
			return true;
			
		if(solveGame(maze,x,y-1,working)) //left
			return true;
			
	
		working[x][y] = 0;
		return false;
	}
	return false;
}

void startGame(int maze[N][N])
{
	int working[N][N] = {{0}};
	
	if(solveGame(maze,0,0,working))
	{
		cout << "Nice game" << endl;
		print(working);
	}
	else
	{
		cout << "Game ended";
		return;
	}
}

int main()

{
	int maze[N][N] = 
	{
		{1,1,1,0,1},
		{0,0,1,0,1},
		{1,1,1,1,1},
		{1,0,0,0,0},
		{1,1,1,1,1}
	};
	
	startGame(maze);
	return 0;
}