// Weighted Job Scheduling

// You are given N jobs where every job is represented as:
// 1. Start Time
// 2. Finish Time
// 3. Profit Associated
// Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
// Input Format:
// The first line of input contains an integer denoting N.
// Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
// Constraints:
// 1 ≤ N ≤ 10^6
// 1 ≤ ai, di, p ≤ 10^6
// Output Format:
// Output one integer, the maximum profit that can be achieved.
// Sample Input 1
// 4
// 3 10 20
// 1 2 50
// 6 19 100
// 2 100 200
// Sample Output 1
// 250

#include<bits/stdc++.h>

using namespace std;

class Job
{
public:
    int start, finish, profit;
};

bool sortFunc(Job j1, Job j2)
{
    return j1.finish < j2.finish;
}

int binarySearch(Job* arr, int n)
{
    int start = 0, end = n-1;
    
    while (start <= end)
    {
        int mid = start + (end - start)/2;
        
        if (arr[n].start >= arr[mid].finish)
        {
            if (arr[n].start >= arr[mid+1].finish)
                start = mid + 1;
            else
                return mid;
        }
        else
            end = mid - 1;
    }
    
    return -1;
}

int main()
{
    int n;
    cin>>n;
    
    Job* arr = new Job[n];
    
    for (int i=0;i<n;i++)
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
    
    sort(arr, arr+n, sortFunc);
    int* dp = new int[n];
    
    dp[0] = arr[0].profit;
    
    for (int i=1;i<n;i++)   
        dp[i] = max(arr[i].profit + dp[binarySearch(arr, i)], dp[i-1]);
    
    cout<<dp[n-1]<<"\n";
    
    return 0;
}
