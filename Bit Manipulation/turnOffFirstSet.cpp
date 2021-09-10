#include<bits/stdc++.h>

using ll = long long;

using namespace std;

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        ll n;
        cin>>n;

        int i = log2(n & ~(n-1));

        cout<<(n - (ll)pow(2, i))<<"\n";
    }

    return 0;
}
