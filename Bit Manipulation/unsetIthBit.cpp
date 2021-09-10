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
        
        if (!(n & (1 << i)))
            cout<<n<<"\n";
        else
            cout<<n - (1 << i)<<"\n";
    }
    
    return 0;
}
