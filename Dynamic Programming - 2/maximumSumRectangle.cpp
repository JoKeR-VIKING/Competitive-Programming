// Maximum Sum Rectangle

// Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
// Input Format:
// First line of input will contain T(number of test case), each test case follows as.
// First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
// Output Format:
// Output a single integer, maximum sum rectangle for each test case in a newline.
// Constraints
// 1 <= T <= 50
// 1<=n,m<=100
// -10^5 <= mat[i][j] <= 10^5
// Sample Input
// 1
// 4 5
// 1 2 -1 -4 -20
// -8 -3 4 2 1
// 3 8 10 1 3
// -4 -1 1 7 -6
// Sample Output
// 29

//O(n^4) approach very slow

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        int n, m;
        cin>>n>>m;
        
        int** arr = new int*[n];
        int** summation = new int*[n];
        
        for (int i=0;i<n;i++)
        {
            arr[i] = new int[m];
            summation[i] = new int[m];
            
            for (int j=0;j<m;j++)
            {
                cin>>arr[i][j];
                summation[i][j] = 0;
            }
        }
        
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                for (int k=i;k<n;k++)
                {
                    for (int l=j;l<m;l++)
                    {
                        summation[i][j] += arr[k][l];
                    }
                }
            }
        }
        
        int maxSum = INT_MIN;
        
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                for (int k=i;k<n;k++)
                {
                    for (int l=j;l<m;l++)
                    {
                        int sum = summation[i][j];
                        
                        if (k != n-1)
                            sum -= summation[k+1][j];
                        if (l != m-1)
                            sum -= summation[i][l+1];
                        if (k != n-1 && l != m-1)
                            sum += summation[k+1][l+1];
                        
                        maxSum = max(maxSum, sum);
                    }
                }
            }
        }
        
        cout<<maxSum<<"\n";
    }
    
    return 0;
}

// DP approach
