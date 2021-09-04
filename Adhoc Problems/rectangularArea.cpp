#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    unordered_map<int, int> m;
    int maxLen = INT_MIN;
    
    while (t--)
    {
        int x, y;
        cin>>x>>y;
        
        if (m.count(x))
            m[x] = max(m[x], y);
        else
            m[x] = y;
        
        maxLen = max(maxLen, x);
    }
    
    int height = 0, totalHeight = 0;
    
    for (int i=maxLen;i>=1;i--)
    {
        if (m[i] > height)
            height = m[i];
        
        totalHeight += height;
    }
    
    cout<<totalHeight<<"\n";
    
    return 0;
}
