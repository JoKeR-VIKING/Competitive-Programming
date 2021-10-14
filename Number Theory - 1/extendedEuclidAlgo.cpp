#include<bits/stdc++.h>

using ll = long long;

using namespace std;

class Triplet
{
public:
    int x, y, gcd;
};

Triplet extendedEuclid(int a, int b)
{
    if (b == 0)
        return {1, 0, a};

    Triplet smallAns = extendedEuclid(b, a%b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - smallAns.y * (a/b);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin>>a>>b;

    Triplet ans = extendedEuclid(a, b);
    cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd<<"\n";

    return 0;
}
