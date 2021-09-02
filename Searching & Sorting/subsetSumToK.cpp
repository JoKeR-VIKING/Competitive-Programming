#include<bits/stdc++.h>

using ll = long long;

using namespace std;

ll subsetSumToK(ll* arr, int n, ll k, vector<ll> temp)
{
    if (accumulate(temp.begin(), temp.end(), 0) == k)
    	return 1;
    
    if (accumulate(temp.begin(), temp.end(), 0) > k || n == 0)
        return 0;
    
    ll counter1 = subsetSumToK(arr+1, n-1, k, temp);
    
    temp.push_back(arr[0]);
    ll counter2 = subsetSumToK(arr+1, n-1, k, temp);
    temp.pop_back();
    
    return counter1 + counter2;
}

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        int n;
        ll k;
        cin>>n>>k;
        
        ll* arr = new ll[n];
        
        for (int i=0;i<n;i++)
            cin>>arr[i];
        
        if (k == 0)
            cout<<pow(2, count(arr, arr+n, 0))<<"\n";
        else
        	cout<<subsetSumToK(arr, n, k, {})<<"\n";
    }
    
    return 0;
}
