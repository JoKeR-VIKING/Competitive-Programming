#include<bits/stdc++.h>

using namespace std;

void mergeFunc(int input[], int start, int mid, int end)
{
    int i = start, j = mid+1, curr = 0;
    int output[end - start + 1];
    
    while (i <= mid && j <= end)
    {
        if (input[i] < input[j])
            output[curr++] = input[i++];
        else
            output[curr++] = input[j++];
    }
    
    while (i <= mid)
        output[curr++] = input[i++];
    
    while (j <= end)
        output[curr++] = input[j++];
    
    for (int k=start;k<=end;k++)
        input[k] = output[k - start];
}

void sortFunc(int input[], int start, int end)
{
    if (start == end)
        return;
    
    int mid = (start+end)/2;
    
    sortFunc(input, start, mid);
    sortFunc(input, mid+1, end);
    
    mergeFunc(input, start, mid, end);
}

void mergeSort(int input[], int size)
{
    int start = 0, end = size-1;
    
    sortFunc(input, start, end);
}

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        int n;
        cin>>n;
        
        int* input = new int[n];
        
        for (int i=0;i<n;i++)
            cin>>input[i];
        
        mergeSort(input, n);
        
        for (int i=0;i<n;i++)
            cout<<input[i]<<" ";
        
        cout<<"\n";
    }
}
