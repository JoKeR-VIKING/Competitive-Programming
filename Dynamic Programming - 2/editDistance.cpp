// Edit Distance - Problem

// Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
// 1. Delete a character

// 2. Replace a character with another one

// 3. Insert a character
// Note - Strings don't contain spaces
// Input Format :
// First line of input will contain T (number of test cases), each test case consists of two lines.
// Line 1 : String s
// Line 2 : String t
// Output Format :
// For each test case print the Edit Distance value in new line.
// Constraints:
// 1 <= T <= 100
// 1<= m,n <= 100
// Sample Input 1 :
// 1
// abc
// dc
// Sample Output 1 :
// 2

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        string s1, s2;
        cin>>s1>>s2;
        
        int** dp = new int*[s1.length()+1];
        
        for (int i=0;i<=s1.length();i++)
            dp[i] = new int[s2.length()+1];
        
        dp[0][0] = 0;
        
        for (int i=1;i<=s1.length();i++)
            dp[i][0] = i;
        
        for (int i=1;i<=s2.length();i++)
            dp[0][i] = i;
        
        for (int i=1;i<=s1.length();i++)
        {
            for (int j=1;j<=s2.length();j++)
            {
                if (s1[i-1] != s2[j-1])
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                else
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        
        cout<<dp[s1.length()][s2.length()]<<"\n";
    }
    
    return 0;
}
