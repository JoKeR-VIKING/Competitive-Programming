#include<bits/stdc++.h>

using ll = long long;

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    ll* booths = new ll[n];
    
    for (int i=0;i<n;i++)
        cin>>booths[i];
    
    ll* rotationsRequired = new ll[n];
    pair<ll, ll> minRotations = {INT_MAX, INT_MAX};
    
    for (int i=0;i<n;i++)
    {
        if ((booths[i] - i)%n == 0)
        {
            rotationsRequired[i] = (booths[i] - i)/n;
        }
        else if (booths[i] - i < 0)
        {
            rotationsRequired[i] = 0;
        }
        else
        {
            rotationsRequired[i] = (booths[i] - i)/n + 1;
        }
    }
    
    for (int i=0;i<n;i++)
    {
        if (rotationsRequired[i] < minRotations.first)
        {
            minRotations.first = rotationsRequired[i];
            minRotations.second = i;
        }
    }
    
    cout<<minRotations.second + 1<<"\n";
    
    return 0;
}
