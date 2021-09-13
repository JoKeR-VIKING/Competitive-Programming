#include<bits/stdc++.h>

using namespace std;

vector<int> sieveOfEratosthenes(int N, vector<bool>& primeCheck)
{
    vector<int> primeNumbers;

    for (int i=2;i<=N;i++)
    {
        if (!primeCheck[i])
        {
            primeNumbers.push_back(i);
            for (int j=2*i;j<=N;j+=i)
            {
                primeCheck[j] = true;
            }
        }
    }

    return primeNumbers;
}

int main()
{
    int n, i = 0, j = 1, counter = 0;
    cin>>n;
    
    vector<bool> primeCheck(n);
    vector<int> primeNumbers = sieveOfEratosthenes(n, primeCheck);
    
    while (j < primeNumbers.size())
    {
        if (primeNumbers[i] + primeNumbers[j] + 1 > n)
            break;
        if (!primeCheck[primeNumbers[i] + primeNumbers[j] + 1])
        	counter++;
        
        i++;
        j++;
    }
    
    cout<<counter<<"\n";
    
    return 0;
}
