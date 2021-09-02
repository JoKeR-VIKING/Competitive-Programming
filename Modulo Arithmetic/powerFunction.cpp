#include<bits/stdc++.h>
#define MOD 1000000007

using ll = long long;

using namespace std;

ll power(int x, int n)
{
    if (n == 0)
        return 1;
    
    return (x % MOD * power(x, n-1) % MOD) % MOD;
}

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        int x, n;
        cin>>x>>n;
        
       cout<<power(x, n)<<"\n";
    }
    
    return 0;
}
