// https://codeforces.com/contest/1037/problem/C

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    string a, b;
    cin>>a>>b;
    
    int i = 0, j = 0, cost = 0;
    
    while (i < n && j < n)
    {
        if (a[i] != b[j])
        {
            if (a[i+1] != b[j+1] && a[i+1] != a[i])
            {
                cost += 1;
                i ++;
                j ++;
            }
            else
                cost += 1;
        }
        
        i++;
        j++;
    }
    
    cout<<cost<<"\n";
    
    return 0;
}
