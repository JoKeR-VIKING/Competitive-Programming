// Trader Profit

// Mike is a stock trader and makes a profit by buying and selling stocks. He buys a stock at a lower price and sells it at a higher price to book a profit. He has come to know the stock prices of a particular stock for n upcoming days in future and wants to calculate the maximum profit by doing the right transactions (single transaction = buying + selling). Can you help him maximize his profit?
// Note: A transaction starts after the previous transaction has ended. Two transactions can't overlap or run in parallel.
// The stock prices are given in the form of an array A for n days.
// Given the stock prices and a positive integer k, find and print the maximum profit Mike can make in at most k transactions.
// Input Format:
// The first line of input contains an integer T(number of test cases).

// The first line of each test case contains a positive integer k, denoting the number of transactions. 

// The second line of each test case contains a positive integer n, denoting the length of the array A.

// The third line of each test case contains n space-separated positive integers, denoting the prices of each day in the array A.
// Output Format
// For each test case print the maximum profit earned by Mike on a new line. 
// Constraints:
// 1 <= T <= 10^3
// 0 < k <= 10

// 2 <= n <= 10^4

// 0 <= elements of array A <= 10^5
// Sample Input
// 3
// 2
// 6
// 10 22 5 75 65 80
// 3
// 4
// 20 580 420 900
// 1
// 5
// 100 90 80 50 25
// Sample Output
// 87
// 1040
// 0

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        int k, n;
        cin>>k>>n;
        
        int* prices = new int[n];
        
        for (int i=0;i<n;i++)
            cin>>prices[i];
        
        int** dp = new int*[k+1];
        
        for (int i=0;i<=k;i++)
            dp[i] = new int[n]();
        
        for (int i=0;i<=k;i++)
            dp[i][0] = 0;
        
        for (int i=0;i<n;i++)
            dp[0][i] = 0;
        
        for (int i=1;i<=k;i++)
        {
            int maxStock = INT_MIN;
            
            for (int j=1;j<n;j++)
            {
                maxStock = max(maxStock, dp[i-1][j-1] - prices[j-1]);
            	dp[i][j] = max(dp[i][j-1], maxStock + prices[j]);
        	}
        }
        
        cout<<dp[k][n-1]<<"\n";
    }
    
    return 0;
}
