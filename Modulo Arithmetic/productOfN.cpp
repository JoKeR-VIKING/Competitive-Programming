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
        
        ll product = 1;
        
        for (int i=1;i<=n;i++)
            product = (product % MOD * i % MOD) % MOD;
        
        cout<<product<<"\n";
    }
    
    return 0;
}
