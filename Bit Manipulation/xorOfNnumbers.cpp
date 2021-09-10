#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        int n;
        cin>>n;
        
        if (n % 4 == 3)
            cout<<0<<"\n";
        else if (n % 4 == 2)
            cout<<n+1<<"\n";
        else if (n % 4 == 1)
            cout<<1<<"\n";
        else
            cout<<n<<"\n";
    }
    
    return 0;
}
