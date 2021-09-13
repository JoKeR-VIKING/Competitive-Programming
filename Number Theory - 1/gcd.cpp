#include<bits/stdc++.h>

using ll = long long;

using namespace std;

ll gcd(int x, int y)
{
    if (y == 0)
        return x;
    
    return gcd(y, x%y);
}

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        ll x, y;
        cin>>x>>y;
        
        cout<<gcd(x, y)<<"\n";
    }
    
    return 0;
}
