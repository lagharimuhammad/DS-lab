#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int guessNum(int mark, int currPlayer, int totalPlayer)
{
	if(currPlayer > totalPlayer)
	{
		cout << "No player guess the word" << endl;
		return mark;
	}
	
	int guess;
	cout << "Enter your guess (1-100: ";
	cin >> guess;
	
	if(mark == guess)
	{
		cout << "Player " << currPlayer << " wins." << endl;
		return mark;
	}
	else if (guess > mark)
	{
		cout << "Guess is too big" << endl;
	}
	else
	{
		cout << "Guess is too small" << endl;
	}
	
	guessNum( mark, currPlayer+1, totalPlayer);
}

int main()
{
	srand(time(0));
	int mark = rand() % 100+1;
	
	int totalPlayer;
	cout << "Enter number of player: ";
	cin >> totalPlayer;
	
	int val = guessNum(mark, 1, totalPlayer);
	cout << "Mark was " << val;
}