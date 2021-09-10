#include<bits/stdc++.h>

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
        
        ll x = 0;
        
        for (int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            x = (x ^ temp);
        }
        
        cout<<x<<"\n";
    }
    
    return 0;
}
