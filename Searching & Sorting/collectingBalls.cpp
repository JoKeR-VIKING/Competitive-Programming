#include<bits/stdc++.h>

using ll = long long;

using namespace std;

bool check(ll k, ll n)
{
    ll sum = 0, current = n;
    
    while (current > 0)
    {
        sum += min(current, k);
        current -= k;
        
        current -= current/10;
    }
    
    if (n % 2)
        n++;
    
    if (sum >= n/2)
        return true;
    
    return false;
}

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        ll n;
        cin>>n;
        
        ll start = 1, end = n, k = n;
        
        while (start <= end)
        {
            ll mid = start + (end - start)/2;
            
            if (check(mid, n))
            {
                k = min(mid, k);
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        
        cout<<k<<"\n";
    }
    
    return 0;
}
