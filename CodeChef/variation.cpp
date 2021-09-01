#include <bits/stdc++.h>
#define MOD 1000000007

using ll = long long;

using namespace std;

int main() 
{
    ll n, k;
    cin>>n>>k;
    
    vector<ll> vect(n);
    
    for (int i=0;i<n;i++)
        cin>>vect[i];
        
    sort(vect.begin(), vect.end());
    
    ll i = 0, j = 1, sets = 0;
    
    while (i < n)
    {
        while (j < n && vect[j] - vect[i] < k)
            j++;
        
        if (j == n)
            break;
        
        sets += n - j;
        i++;
    }
    
    cout<<sets<<"\n";
	
	return 0;
}
