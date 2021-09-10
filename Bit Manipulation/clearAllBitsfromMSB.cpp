#include<bits/stdc++.h>

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
        
        int i;
        cin>>i;
        
        cout<<(n & (1 << i) - 1)<<"\n";
    }
    
    return 0;
}
