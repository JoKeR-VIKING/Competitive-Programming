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
        
        int* dp = new int[n+1];
        
        dp[0] = 0;
        dp[1] = 1;
        
        for (int i=2;i<=n;i++)
        {
            dp[i] = i;
            
            for (int j=2;j<=sqrt(i);j++)
            {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        
        cout<<dp[n]<<"\n";
    }
    
    return 0;
}
