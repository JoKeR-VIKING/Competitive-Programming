#include<bits/stdc++.h>

using namespace std;

void strategyPossible(int* arr, int n)
{
    int swapCount = 0;
    
    for(int i=0;i<n;i++)
    {
        if(abs(arr[i]-i-1) > 2)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    
    for (int i=n-1;i>=2;i--)
    {
        if (arr[i] == i+1)
            continue;
        
        if (arr[i-1] == i+1)
        {
            swapCount++;
            swap(arr[i-1], arr[i]);
        }
        else if (arr[i-2] == i+1)
        {
            swapCount += 2;
            swap(arr[i-2], arr[i-1]);
            swap(arr[i-1], arr[i]);
        }
        else
        {
            cout<<"NO\n";
            return;
        }
    }
    
    if (arr[0] == 2 && arr[1] == 1)
    {
        swap(arr[0], arr[1]);
        swapCount++;
    }
    
    if (arr[0] == 1 && arr[1] == 2)
        cout<<"YES\n"<<swapCount<<"\n";
    else
        cout<<"NO\n";
}

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        int n;
        cin>>n;
        
        int* arr = new int[n];
        
        for (int i=0;i<n;i++)
            cin>>arr[i];
        
        strategyPossible(arr, n);
    }
    
    return 0;
}
