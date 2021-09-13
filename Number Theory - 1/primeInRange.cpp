#include<bits/stdc++.h>

using namespace std;

bool checkPrime(int n)
{
    for (int i=2;i<=sqrt(n);i++)
    {
        if (n % i == 0)
            return false;
    }
    
    return true;
}

int main()
{
    int n, counter = 0;
    cin>>n;
    
    for (int i=2;i<=n;i++)
    {
        if (checkPrime(i))
            counter++;
    }
    
    cout<<counter<<"\n";
    
    return 0;
}
