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
        int n, value;
        cin>>n;
        
        int* denominations = new int[n];
        
        for (int i=0;i<n;i++)
            cin>>denominations[i];
        
        cin>>value;
        
        ll* dp = new ll[value + 1]();
        
        dp[0] = 1;
        
        for (int i=0;i<n;i++)
        {
            int current = denominations[i];
            
            for (int j=current;j<=value;j++)
            {
                dp[j] = (dp[j] % MOD + dp[j - current] % MOD) % MOD;
            }
        }
        
        cout<<dp[value]<<"\n";
    }
    
    return 0;
}
