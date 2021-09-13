#include<bits/stdc++.h>

using namespace std;

int sieveOfEratosthenes(int N)
{
    vector<bool> divisorCount(N);
	int counter = 0;
    
    for (int i=2;i<=N;i++)
    {
        if (!divisorCount[i])
        {
            counter++;
            for (int j=2*i;j<=N;j+=i)
            {
                divisorCount[j] = true;
            }
        }
    }

    return counter;
}

int main()
{
    int n;
    cin>>n;
    
    cout<<2<<"\n";
    int counter = sieveOfEratosthenes(n+1);
    
    cout<<min(counter, n-counter)<<" "<<max(counter, n-counter)<<"\n";
    
    return 0;
}
