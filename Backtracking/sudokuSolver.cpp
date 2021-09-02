#include<bits/stdc++.h>

using namespace std;

int board[9][9];

bool canPlaceHorizontally(int i, int num)
{
    for (int k=0;k<9;k++)
    {
        if (board[i][k] == num)
            return false;
    }
    
    return true;
}

bool canPlaceVertically(int j, int num)
{
    for (int k=0;k<9;k++)
    {
        if (board[k][j] == num)
            return false;
    }
    
    return true;
}

bool canPlaceGrid(int i, int j, int num)
{
    i = i - i%3;
    j = j - j%3;
    
    for (int k=0;k<3;k++)
    {
        for (int l=0;l<3;l++)
        {
            if (board[k + i][l + j] == num)
                return false;
        }
    }
    
    return true;
}

bool checker(int value, int row, int col)
{
	if(canPlaceVertically(col, value) && canPlaceHorizontally(row, value) && canPlaceGrid(row, col, value))
	{
		return true;
	}
	return false;
}

bool find_empty_location(int& row, int &col)
{
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			if(board[i][j]==0)
			{
				row = i;
				col = j;
				return true;
			}
		}
	}
    
	return false;
}

bool solveSudoku()
{
	int row=0, col=0;
    
	if(!find_empty_location(row, col))
	{
		return true;
	}
    
	for(int i=1; i<=9; i++)
	{
		if (checker(i, row, col))
		{
			board[row][col] = i;
            
			if(solveSudoku())
			{
				return true;
			}
			else
			{
				board[row][col] = 0;
			}
		}
	}
    
	return false;
}

int main()
{
    for (int i=0;i<9;i++)
        for (int j=0;j<9;j++)
            cin>>board[i][j];
    
    bool isPossible = solveSudoku();
    
    cout<<(isPossible ? "true" : "false")<<"\n";
    
    return 0;
}
