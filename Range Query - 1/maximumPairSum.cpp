// Maximum Pair Sum

// You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
// Update:
// This will be indicated in the input of a 'U' followed by space and then two integers i and x.
// U i x
// This operation sets the value of A[i] to x.
// Query:
// This will be indicated in the input of a 'Q' followed by a single space and then two integers i and j.
// Q x y
// You must find two integers i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
// Input Format:
// The first line of input contains an integer N, representing the length of the sequence. 
// The second line of input contains of N space separated integers, A[i]. 
// The third line of input contains an integer Q, Q ≤ 10^5, representing the number of operations. 
// Next Q lines contain the operations.
// Constraints:
// 1 ≤ i ≤ N
// 0 ≤ x ≤ 10^8
// 1 ≤ x < y ≤ N
// Output Format:
// For each query, print the maximum sum mentioned above, in a new line.
// Sample Input 1:
// 5
// 1 2 3 4 5
// 6
// Q 2 4
// Q 2 5
// U 1 6
// Q 1 5
// U 1 7
// Q 1 5
// Sample Output 1:
// 7
// 9
// 11
// 12

#include<bits/stdc++.h>

using namespace std;

void buildMaxTree(int* arr, pair<int, int>* maxTree, int start, int end, int idx)
{
    if (start == end)
    {
        maxTree[idx] = {0, arr[start]};
        return;
    }
    
    int mid = start + (end - start)/2;
    buildMaxTree(arr, maxTree, start, mid, 2*idx + 1);
    buildMaxTree(arr, maxTree, mid + 1, end, 2*idx + 2);
    
    int x = min(max(maxTree[2*idx + 1].first, maxTree[2*idx + 2].second), max(maxTree[2*idx + 1].second, maxTree[2*idx + 2].first));
    int y = max(maxTree[2*idx + 1].second, maxTree[2*idx + 2].second);
    
    maxTree[idx] = {x, y};
}

void updateMaxTree(int* arr, pair<int, int>* maxTree, int start, int end, int idx, int pos, int val)
{
    if (start == end)
    {
        arr[pos] = maxTree[idx].second = val;
        return;
    }
    
    int mid = start + (end - start)/2;
    
    if (pos <= mid)
    	updateMaxTree(arr, maxTree, start, mid, 2*idx + 1, pos, val);
    else
    	updateMaxTree(arr, maxTree, mid + 1, end, 2*idx + 2, pos, val);
    
    int x = min(max(maxTree[2*idx + 1].first, maxTree[2*idx + 2].second), max(maxTree[2*idx + 1].second, maxTree[2*idx + 2].first));
    int y = max(maxTree[2*idx + 1].second, maxTree[2*idx + 2].second);
    
    maxTree[idx] = {x, y};
}

pair<int, int> greatestPairSum(pair<int, int>* maxTree, int start, int end, int idx, int l, int r)
{
    if (end < l || start > r)
        return {0, 0};
    if (start >= l && end <= r)
        return maxTree[idx];
    
    int mid = start + (end - start)/2;
    
    pair<int, int> x = greatestPairSum(maxTree, start, mid, 2*idx + 1, l, r);
    pair<int, int> y = greatestPairSum(maxTree, mid + 1, end, 2*idx + 2, l, r);
    
    int a = min(max(x.first, y.second), max(x.second, y.first));
    int b = max(x.second, y.second);
    
    return {a, b};
}

int main()
{
    int n;
    cin>>n;
    
    int* arr = new int[n];
    pair<int, int>* maxTree = new pair<int, int>[4*n]();
    
    for (int i=0;i<n;i++)
        cin>>arr[i];
    
    buildMaxTree(arr, maxTree, 0, n-1, 0);
    
    int q;
    cin>>q;
    
    while (q--)
    {
        char c;
        cin>>c;
        
        if (c == 'Q')
        {
            int l, r;
            cin>>l>>r;
            
            pair<int, int> ans = greatestPairSum(maxTree, 0, n-1, 0, l-1, r-1);
            
            cout<<ans.first + ans.second<<"\n";
        }
        else
        {
            int pos, val;
            cin>>pos>>val;
            
            updateMaxTree(arr, maxTree, 0, n-1, 0, pos-1, val);
        }
    }
    
    return 0;
}
