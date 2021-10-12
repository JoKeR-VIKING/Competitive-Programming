// Knapsnack - Problem

// A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
// Note: Space complexity should be O(W).
// Input Format :
// Line 1 : N i.e. number of items
// Line 2 : N Integers i.e. weights of items separated by space
// Line 3 : N Integers i.e. values of items separated by space
// Line 4 : Integer W i.e. maximum weight thief can carry
// Output Format :
// Line 1 : Maximum value V
// Constraints
// 1 <= N <= 10^4
// 1<= wi <= 100
// 1 <= vi <= 100
// 1 <= W <= 1000
// Sample Input 1 :
// 4
// 1 2 4 5
// 5 4 8 6
// 5
// Sample Output :
// 13

#include<bits/stdc++.h>

using namespace std;

int knapSack(int* weights, int* values, int maxCapacity, int n)
{
    int** dp = new int*[n+1];
    
    for (int i=0;i<=n;i++)
        dp[i] = new int[maxCapacity+1];
    
    for (int i=0;i<=n;i++)
        dp[i][0] = 0;
    
    for (int i=0;i<=maxCapacity;i++)
        dp[0][i] = 0;
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=maxCapacity;j++)
        {
            if (j >= weights[i-1])
            	dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j - weights[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[n][maxCapacity];
}

int main()
{
    int n;
    cin>>n;
    
    int* weights = new int[n];
    int* values = new int[n];
    
    for (int i=0;i<n;i++)
        cin>>weights[i];
    
    for (int i=0;i<n;i++)
        cin>>values[i];
    
    int maxCapacity;
    cin>>maxCapacity;
    
    cout<<knapSack(weights, values, maxCapacity, n)<<"\n";
        
    return 0;
}
