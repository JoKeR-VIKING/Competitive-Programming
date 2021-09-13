#include<bits/stdc++.h>

using namespace std;

vector<int> sieveOfEratosthenes(int N)
{
    vector<int> divisorCount(N);

    for (int i=2;i<=N;i++)
    {
        if (!divisorCount[i])
        {
            for (int j=2*i;j<=N;j+=i)
            {
                divisorCount[j]++;
            }
        }
    }

    return divisorCount;
}

int main()
{
    int N, counter = 0;
    cin>>N;
    
    vector<int> divisorCount = sieveOfEratosthenes(N);
    
    for (int i=6;i<=N;i++)
    {
        if (divisorCount[i] == 2)
            counter++;
    }
    
    cout<<counter<<"\n";
    
    return 0;
}
