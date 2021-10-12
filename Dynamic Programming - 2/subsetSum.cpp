// Subset Sum - Problem

// Given an array of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
// Input Format
// First-line will contain T(number of test cases), each test case consists of three lines. 
// First-line contains a single integer N(length of input array).
// Second-line contains n space-separated integers denoting the elements of array.
// The last line contains a single positive integer k.
// Output Format
// Output Yes if there exists a subset whose sum is k, else output No for each test case in new line.
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 500
// 1 <= arr[i] <= 10^4
// 1 <= K <= 500
// Sample Input
// 1
// 3
// 1 2 3
// 4
// Sample Output
// Yes

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        int n;
        cin>>n;
        
        int* arr = new int[n];
        
        for (int i=0;i<n;i++)
            cin>>arr[i];
        
        int k;
        cin>>k;
        
        bool** dp = new bool*[n+1];
        
        for (int i=0;i<=n;i++)
            dp[i] = new bool[k+1];
        
        for (int i=0;i<=n;i++)
            dp[i][0] = 0;
        
        for (int i=0;i<=k;i++)
            dp[0][i] = 0;
        
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=k;j++)
            {
                if (arr[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else if (arr[i-1] == j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        
        cout<<(dp[n][k] ? "Yes\n" : "No\n");
    }
    
    return 0;
}
