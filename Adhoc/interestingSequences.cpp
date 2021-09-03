#include<bits/stdc++.h>

using ll = long long;

using namespace std;

ll findCost(ll* arr, ll mid, ll k, ll l, ll n)
{
    ll inc = 0, dec = 0;
    
    for (ll i=0;i<n;i++)
    {
        if (arr[i] < mid)
        	inc += mid - arr[i];
        else if (arr[i] > mid)
        	dec += arr[i] - mid;
    }

    if (inc >= dec)
        return dec * k + (inc - dec) * l;
    else
        return LLONG_MAX;
}

int main()
{
    ll n, k, l, start = LLONG_MAX, end = LLONG_MIN, cost = LLONG_MAX;
    cin>>n>>k>>l;
    
    ll* arr = new ll[n];
    
    for (ll i=0;i<n;i++)
    {
        cin>>arr[i];
        start = min(start, arr[i]);
        end = max(end, arr[i]);
	}
    
    for (ll i=start;i<=end;i++)
    {
        ll currentCost = findCost(arr, i, k, l, n);
        
        if (cost < currentCost)
            break;
        
        cost = currentCost;
    }
    
    cout<<cost<<"\n";
    
    return 0;
}
