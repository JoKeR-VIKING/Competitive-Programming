#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        int n, m;
        cin>>n>>m;

        int** arr = new int*[n];
        int** dp = new int*[n];
        
        for (int i=0;i<n;i++)
        {
            arr[i] = new int[m];
            dp[i] = new int[m]();
            
            for (int j=0;j<m;j++)
                cin>>arr[i][j];
        }
        
        dp[n-1][m-1] = 1;
        
        for (int i=n-2;i>=0;i--)
            dp[i][m-1] = max(1, dp[i+1][m-1] - arr[i][m-1]);
        
        for (int i=m-2;i>=0;i--)
            dp[n-1][i] = max(1, dp[n-1][i+1] - arr[n-1][i]);
        
        for (int i=n-2;i>=0;i--)
        {
            for (int j=m-2;j>=0;j--)
            {
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - arr[i][j]);
            }
        }
        
        cout<<dp[0][0]<<"\n";
    }

    return 0;
}
