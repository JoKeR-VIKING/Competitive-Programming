#include<bits/stdc++.h>

using ll = long long;

using namespace std;

int search(ll* shops, int start, int end, ll money)
{
    int idx = -1;
    
    while (start <= end)
    {
        int mid = start + (end - start)/2;
        
        if (shops[mid] == money)
            return mid;
        
        if (shops[mid] < money)
        {
            idx = max(idx, mid);
            start = mid + 1;
        }
        else
            end = mid - 1;
        
    }
    
    return idx;
}

int main()
{
    int n;
    cin>>n;
    
    ll* shops = new ll[n];
    cin>>shops[0];
    
    for (int i=1;i<n;i++)
    {
        cin>>shops[i];
        shops[i] += shops[i-1];
    }
    
    int days;
    cin>>days;
    
    while (days--)
    {
        ll money;
        cin>>money;
        
        int idx = search(shops, 0, n-1, money);
        
        if (idx == -1)
        {
            cout<<0<<" "<<money<<"\n";
            continue;
        }
        
        cout<<idx + 1<<" "<<money - shops[idx]<<"\n";
    }
    
    return 0;
}
