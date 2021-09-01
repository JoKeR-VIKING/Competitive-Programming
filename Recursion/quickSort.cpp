#include<bits/stdc++.h>

using namespace std;

void quickSort(int input[], int start, int end)
{
    if (start >= end)
        return;
    
    int current = input[start], minNo = start;
    
    for (int i=start+1;i<end;i++)
    {
        if (input[i] < current)
            minNo++;
    }
    
    int temp = input[minNo];
    input[minNo] = current;
    input[start] = temp;
    
    int i = start, j = minNo + 1;
    
    while (i < minNo && j < end)
    {
        if (input[i] < current && input[j] >= current)
        {
            i++;
            j++;
        }
        else if (input[i] < current)
        {
            i++;
        }
        else if (input[j] >= current)
        {
            j++;
        }
        else
        {
            temp = input[i];
    		input[i] = input[j];
    		input[j] = temp;
            
            i++;
            j++;
        }
    }
    
    quickSort(input, start, minNo);
    quickSort(input, minNo + 1, end);
}

void quickSort(int input[], int size)
{
    int start = 0, end = size;
    
    quickSort(input, start, end);
}

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        int n;
        cin >> n;

        int *input = new int[n];

        for(int i = 0; i < n; i++) 
        {
            cin >> input[i];
        }

        quickSort(input, n);

        for(int i = 0; i < n; i++) 
        {
            cout << input[i] << " ";
        }
        
        cout<<"\n";
    }
}
