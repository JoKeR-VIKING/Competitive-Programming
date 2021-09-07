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
        int* dp = new int[n];
        
        for (int i=0;i<n;i++)
        	cin>>arr[i];
        
        dp[0] = 1;
        
        for (int i=1;i<n;i++)
        {
            if (arr[i] <= arr[i-1])
                dp[i] = 1;
            else
                dp[i] = dp[i-1] + 1;
        }
        
        for (int i=n-2;i>=0;i--)
        {
            if (arr[i] > arr[i+1])
            {
                if (dp[i] <= dp[i+1])
                    dp[i] = dp[i+1] + 1;
            }
        }
        
        cout<<accumulate(dp, dp+n, 0)<<"\n";
    }
    
    return 0;
}
