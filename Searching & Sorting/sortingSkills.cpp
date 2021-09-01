#include<bits/stdc++.h>

using namespace std;

bool helper(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i] > arr[i+1])
        {
            if(arr[i] - arr[i+1] == 1)
                swap(arr[i], arr[i+1]);
            else
                return false;
        }
    }
    
    return true;
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        int* arr = new int[n];
        
        for(int i=0;i<n;i++) 
            cin>>arr[i];
        
        if (helper(arr, n))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

    return 0;
}
