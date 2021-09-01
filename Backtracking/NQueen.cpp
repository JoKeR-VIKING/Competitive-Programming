#include<bits/stdc++.h>

using namespace std;

bool isPossible(vector<vector<int>>& board, int i, int j, int n)
{
    int k = i, l = j;
    
    for (;k>=0;k--)
    {
        if (board[k][j] == 1)
            return false;
    }
    
    k = i;
    
    for (;l>=0;l--)
    {
        if (board[i][l] == 1)
            return false;
    }
    
    l = j;
    
    while (k >= 0 && l >= 0)
    {
        if (board[k][l] == 1)
            return false;
        
        k--;
        l--;
    }
    
    k = i;
    l = j;
    
    while (k >= 0 && l < n)
    {
        if (board[k][l] == 1)
            return false;
        
        k--;
        l++;
    }
    
    return true;
}

void nQueen(vector<vector<int>>& board, int i, int j, int n)
{
    if (i == n)
    {
        for (auto& it1 : board)
        {
            for (auto& it2 : it1)
            {
                cout<<it2<<" ";
            }
        }
        cout<<"\n";
        
        return;
    }
    
    for (;i<n;i++)
    {
        for (;j<n;j++)
        {
            bool canBePlaced = isPossible(board, i, j, n);
            
            if (canBePlaced)
            {
                board[i][j] = 1;
                nQueen(board, i+1, 0, n);
                board[i][j] = 0;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    nQueen(board, 0, 0, n);
    
    return 0;
}
