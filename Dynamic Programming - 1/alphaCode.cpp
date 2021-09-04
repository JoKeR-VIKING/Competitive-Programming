#include<bits/stdc++.h>
#define MOD 1000000007

using ll = long long;

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        string s;
        cin>>s;
        
        if (s == "0")
        {
            cout<<0<<"\n";
            continue;
        }
        else if (s.length() <= 1)
        {
            cout<<1<<"\n";
            continue;
        }
        
        int* number = new int[s.length()];
        ll* dp = new ll[s.length() + 1];
        
        for (int i=0;i<s.length();i++)
            number[i] = s[i] - '0';
        
        dp[0] = dp[1] = 1;
        
        for (int i=2;i<=s.length();i++)
        {
            if (number[i - 1] == 0)
            {
                if (number[i - 2] * 10 + number[i - 1] >= 10)
                {
                    dp[i] = dp[i - 1];
                    continue;
                }
                
                dp[s.length()] = 0;
                break;
            }
            
            dp[i] = dp[i - 1];
            
            if (number[i - 2] * 10 + number[i - 1] <= 26 && number[i - 2] * 10 + number[i - 1] >= 10)
                dp[i] = (dp[i] % MOD + dp[i - 2] % MOD) % MOD;
        }
        
        cout<<dp[s.length()]<<"\n";
    }
    
    return 0;
}
