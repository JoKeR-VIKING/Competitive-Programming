#include<bits/stdc++.h>

using ll = long long;

using namespace std;

int main()
{
    ll n, x, y, zeroPairs = 0;
    cin>>n>>x>>y;
    
    string s;
    cin>>s;
    
    if (s[0] == '0')
        zeroPairs++;
    
    for (int i=0;i<n;i++)
    {
        if (s[i] == '1' && s[i+1] == '0')
        {
            zeroPairs++;
    	}
    }
    
    if (zeroPairs == 0)
        cout<<0<<"\n";
    else
    	cout<<(zeroPairs - 1) * min(x, y) + y<<"\n";
    
    
    return 0;
}
