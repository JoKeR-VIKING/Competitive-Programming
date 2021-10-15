// Divisors Of Factorial

// Given a number, find the total number of divisors of the factorial of the number.
// Since the answer can be very large, print answer modulo 10^9+7.
// Input Format:
// The first line contains T, number of test cases.
// T lines follow each containing the number N.
// Output Format:
// Print T lines of output each containing the answer.
// Constraints
// 1 <= T <= 500
// 0 <= N <= 50000
// Sample Input:
// 3
// 2
// 3
// 4
// Sample Output:
// 2
// 4
// 8

#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;
using ll = long long;

vector<int> sieveOfEratosthenes(int n)
{
    vector<int> primeNumbers;
    vector<int> isPrime(n+1, true);
    
    for (int i=2;i<=n;i++)
    {
        if (isPrime[i])
        {
            primeNumbers.push_back(i);
            
            for (int j=2*i;j<=n;j+=i)
            	isPrime[j] = false;
        }
    }
    
    return primeNumbers;
}

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        int n;
        cin>>n;
        
        vector<int> primeNumbers = sieveOfEratosthenes(n);
        ll totalDivisors = 1;
        
        for (auto& it : primeNumbers)
        {
            ll sum = 0;
            
            for (int i=1;pow(it, i)<=n;i++)
                sum += n/pow(it, i);
            
            sum++;
            totalDivisors = (totalDivisors % MOD * sum % MOD) % MOD;
        }
        
        cout<<totalDivisors<<"\n";
    }
    
    return 0;
}
