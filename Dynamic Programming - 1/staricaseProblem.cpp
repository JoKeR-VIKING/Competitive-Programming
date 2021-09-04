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
        int n;
        cin>>n;
        
        if (n < 3)
        {
            cout<<n<<"\n";
            continue;
        }
        else if (n == 3)
        {
            cout<<4<<"\n";
            continue;
        }
        
        ll* dp = new ll[n+1];
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        
        for (int i=4;i<=n;i++)
        {
            dp[i] = (dp[i-1] % MOD + dp[i-2] % MOD + dp[i-3] % MOD) % MOD;
        }
        
        cout<<dp[n]<<"\n";
    }
    
    return 0;
}
