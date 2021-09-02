/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>

using namespace std;

void ratInMaze(bool** orignalMaze, bool** backTrackedMaze, int i, int j, int n)
{
    if (i == n-1 && j == n-1)
    {
        backTrackedMaze[i][j] = 1;
        
        for (int k=0;k<n;k++)
            for (int l=0;l<n;l++)
                cout<<backTrackedMaze[k][l]<<" ";
        
        cout<<"\n";
        return;
    }
    
    if (i == n || j == n || i < 0 || j < 0 || orignalMaze[i][j] == 0 || backTrackedMaze[i][j] == 1)
        return;
    
    backTrackedMaze[i][j] = 1;
    
    ratInMaze(orignalMaze, backTrackedMaze, i+1, j, n);
    ratInMaze(orignalMaze, backTrackedMaze, i-1, j, n);
    ratInMaze(orignalMaze, backTrackedMaze, i, j+1, n);
    ratInMaze(orignalMaze, backTrackedMaze, i, j-1, n);
    
    backTrackedMaze[i][j] = 0;
}

int main() 
{
    int n;
    cin>>n;
    
    bool** orignalMaze = new bool*[n];
    bool** backTrackedMaze = new bool*[n];
    
    for (int i=0;i<n;i++)
    {
        orignalMaze[i] = new bool[n];
        backTrackedMaze[i] = new bool[n];
        
        for (int j=0;j<n;j++)
        {
            cin>>orignalMaze[i][j];
            backTrackedMaze[i][j] = 0;
        }
	}
    
    ratInMaze(orignalMaze, backTrackedMaze, 0, 0, n);
    
	return 0;
}
