#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    map<int, int> m;
    
    int a, b, c, counter = 0;
    cin>>a>>b>>c;
    
    int i = 0;
    
    while (i++ < a+b+c)
    {
        int temp;
        cin>>temp;
        
        m[temp]++;
        
        if (m[temp] == 2)
            counter++;
    }
    
    cout<<counter<<"\n";
    
    for (auto& it : m)
    {
        if (it.second > 1)
            cout<<it.first<<"\n";
    }
    
    return 0;
}
