#include<bits/stdc++.h>

using ll = long long;

using namespace std;

int main()
{
	int t;
    cin>>t;
    
    while (t--)
    {
        ll n, c;
        cin>>n>>c;
        
        vector<ll> stalls(n);
        
        for (int i=0;i<n;i++)
            cin>>stalls[i];
        
        sort(stalls.begin(), stalls.end());
        
        ll maxDist = 0, start = 1, end = stalls.back() - stalls[0];
        
        while (start <= end)
        {
            ll j = 0, k = 1, temp = 1, mid = start + (end - start)/2;
            
            while (k < stalls.size() && temp != c)
            {
                if (stalls[k] - stalls[j] >= mid)
                {
                    temp++;
                    j = k;
            	}
                
                k++;
            }
            
            if (temp == c)
            {
                maxDist = max(maxDist, mid);
                start = mid + 1;
        	}
            else
            {
                end = mid - 1;
            }
        }
        
        cout<<maxDist<<"\n";
    }
    
    return 0;
}
