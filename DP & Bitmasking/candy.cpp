#include<bits/stdc++.h>

using ll = long long;

using namespace std;

ll distributeCandies(bool** arr, ll* dp, ll n, ll i, ll mask)
{
    if (i >= n)
    	return 1; 
    
    if (dp[mask] != -1)
        return dp[mask];
    
    ll ways = 0;
    
    for (ll j=0;j<n;j++)
    {
        if (!(mask & (1 << j)) && arr[i][j])
        {
            ways += distributeCandies(arr, dp, n, i+1, mask | (1 << j));
        }
    }
    
    dp[mask] = ways;
    return dp[mask];
}

int main()
{
    ll t;
    cin>>t;
    
    while (t--)
    {
        ll n;
        cin>>n;
        
        bool** arr = new bool*[n];
        ll* dp = new ll[(1<<n)];
        
        for (ll i=0;i<n;i++)
        {
            arr[i] = new bool[n];
            
            for (ll j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }
        
        for (ll i=0;i<(1<<n);i++)
            dp[i] = -1;
        
        ll ways = distributeCandies(arr, dp, n, 0, 0);
        
        cout<<ways<<"\n";
    }
    
    return 0;
}
