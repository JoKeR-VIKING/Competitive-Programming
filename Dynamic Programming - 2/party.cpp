// PARTY - Problem

// You just received another bill which you cannot pay because you lack the money.
// Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.
// You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.
// You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
// Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.
// Input Format:
// First line of input will contain an integer N (number of parties).
// Next line of input will contain N space-separated integers denoting the entry fee of Ith party.
// Next line will contain N space-separated integers denoting the amount of fun Ith party provide.
// Last line of input will contain an integer W party budget.
// Output Format:
// For each test case your program must output the sum of the entrance fees and the sum of all fun values of an optimal solution. Both numbers must be separated by a single space. 
// Note: In case of multiple cost provides the maximum fun output the minimum total cost.
// Sample Input:
// 5
// 1 7 9 7 2 
// 5 5 2 4 7 
// 12
// Sample Output:
// 10 17

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int* entryFee = new int[n];
    int* fun = new int[n];
    
    for (int i=0;i<n;i++)
        cin>>entryFee[i];
    
    for (int i=0;i<n;i++)
        cin>>fun[i];
    
    int budget;
    cin>>budget;
    
    int** dp = new int*[n+1];
    
    for (int i=0;i<=n;i++)
        dp[i] = new int[budget+1];
    
    for (int i=0;i<=n;i++)
        dp[i][0] = 0;
    
    for (int i=0;i<=budget;i++)
        dp[0][i] = 0;
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=budget;j++)
        {
            if (j >= entryFee[i-1])
            	dp[i][j] = max(dp[i-1][j], fun[i-1] + dp[i-1][j - entryFee[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    int minFee = INT_MAX;
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=budget;j++)
        {
            if (dp[i][j] == dp[n][budget])
            	minFee = min(minFee, j);
        }
    }
    
    cout<<minFee<<" "<<dp[n][budget]<<"\n";
    
    return 0;
}
