#include<bits/stdc++.h>

using ll = long long;

using namespace std;

int main()
{
    ll t;
    cin>>t;
    
    while (t--)
    {
        ll n, k;
        cin>>n>>k;
        
        ll* boxes = new ll[n];
        ll start = 0, end = LLONG_MIN, maxCandies = INT_MIN;
        
        for (ll i=0;i<n;i++)
        {
            cin>>boxes[i];
            
            end = max(end, boxes[i]);
        }
        
        while (start <= end)
        {
            ll mid = start + (end - start)/2, studentsProvided = 0;
            
            for (ll i=0;i<n;i++)
            {
                studentsProvided += boxes[i]/mid;
                
                if (studentsProvided >= k)
                {
                    maxCandies = max(maxCandies, mid);
                    start = mid + 1;
                    break;
                }
            }
            
            if (studentsProvided < k)
            {
                end = mid - 1;
            }
        }
        
    	cout<<maxCandies<<"\n";
    }
    
    return 0;
}
