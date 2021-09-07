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
        
        int* dp = new int[1001];
        int* frequency = new int[1001];
        
        dp[0] = frequency[0] = 0;
        
        for (int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            frequency[temp]++;
    	}
        
        dp[1] = frequency[1];
        
        for (int i=2;i<=1000;i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + i*frequency[i]);
        }
        
        cout<<dp[1000]<<"\n";
    }
    
    return 0;
}
