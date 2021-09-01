#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main() 
{
    int n, q;
    cin>>n>>q;
    
    vector<long long> numbers;
    queue<long long> pendingNumbers, pendingQueries;
    
    for (int i=0;i<n;i++)
    {
        long long temp;
        cin>>temp;
        
        numbers.push_back(temp);
    }
    
    sort(numbers.begin(), numbers.end());
    int j = 1;
    
    while (q--)
    {
        int k;
        cin>>k;
        pendingQueries.push(k);
    }
    
    while ((!numbers.empty() || !pendingNumbers.empty()) && !pendingQueries.empty())
    {
        long long x;
        
        if (!numbers.empty() && (pendingNumbers.empty() || numbers.back() > pendingNumbers.front()))
        {
            x = numbers.back();
            numbers.pop_back();
        }
        else
        {
            x = pendingNumbers.front();
            pendingNumbers.pop();
        }
        
        if (j++ == pendingQueries.front())
        {
            pendingQueries.pop();
            cout<<x<<"\n";
        }
        
        if (x / 2 > 0)
            pendingNumbers.push(x/2);
    }
	
	return 0;
}
