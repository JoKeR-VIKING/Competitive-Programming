// Largest Bitonic Subsequence

// You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
// Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
// Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
// Input Format:
// First line will contain T (number of test case), each test is consists of two lines. 
// Line 1 : A positive Integer N, i.e., the size of array
// Line 2 : N space-separated integers as elements of the array 
// Output Format:
// Length of Largest Bitonic subsequence for each test case in a newline.
// Input Constraints:
// 1 <= T <= 10
// 1<= N <= 5000
// Sample Input 1:
// 1
// 6
// 15 20 20 6 4 2
// Sample Output 1:
// 5
// Sample Output 1 Explanation:
// Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
// Sample Input 2:
// 1
// 2
// 1 5
// Sample Output 2:
// 2
// Sample Input 3:
// 1
// 2
// 5 1
// Sample Output 3:
// 2

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
        
        int* longestIncreasingSub = new int[n];
        int* longestDecreasingSub = new int[n];
        int maxLen = INT_MIN;
        
        for (int i=0;i<n;i++)
        {
            longestIncreasingSub[i] = 1;
            
            for (int j=i-1;j>=0;j--)
            {
                if (arr[i] > arr[j])
                	longestIncreasingSub[i] = max(longestIncreasingSub[i], longestIncreasingSub[j] + 1);
            }
        }
        
        for (int i=n-1;i>=0;i--)
        {
            longestDecreasingSub[i] = 1;
            
            for (int j=i+1;j<n;j++)
            {
                if (arr[i] > arr[j])
                	longestDecreasingSub[i] = max(longestDecreasingSub[i], longestDecreasingSub[j] + 1);
            }
        }
        
        for (int i=0;i<n;i++)
        {
            maxLen = max(maxLen, longestIncreasingSub[i] + longestDecreasingSub[i]);
        }
        
        cout<<maxLen - 1<<"\n";
    }
    
    return 0;
}
