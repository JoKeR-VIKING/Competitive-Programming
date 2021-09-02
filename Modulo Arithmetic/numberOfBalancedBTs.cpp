#include<bits/stdc++.h>
#define MOD 1000000007

using ll = long long;

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        ll n;
        cin>>n;
        
        ll* dp = new ll[n+1];
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 3;
        
        for (int i=3;i<=n;i++)
        {
            dp[i] = (dp[i-1] % MOD * dp[i-1] % MOD) % MOD;
            dp[i] = (dp[i] % MOD + (2 * (dp[i-1] % MOD * dp[i-2] % MOD) % MOD) % MOD) % MOD;
        }
        
        cout<<dp[n]<<"\n";
    }
    
    return 0;
}
