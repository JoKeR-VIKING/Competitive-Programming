// Minimum In SubArray

// You are given a sequence A[1], A[2], ..., A[N] of N numbers ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are Q queries, and each query is defined in either of the following two ways:
// Query on range:
// You are given two numbers i and j; the answer to each query is the minimum number between the range (i, j) (including both i and j). Note that in this query, i and j lies in the range: [1, N].
// Update query:
// You are given two numbers i and B; update A[i] to B. Note that in this query, i lies in the range: [1, N].
// Input Format:
// The first line of input contains two integers: N and Q, representing the length of the sequence and the number of queries. 
// The second line of input contains N space-separated integers, A[i].  
// Next, Q lines contain the queries. Each line contains one character, followed by two space-separated integers. For the query on range, the character will be q and for the update query, the character will be u. 
// Constraints:
// 1 ≤ i ≤ N
// 0 ≤ B ≤ 10^8
// 1 ≤ i <= j ≤ N
// Output Format:
// For each query on range, print the minimum number between the range, in a new line.
// Sample Input 1:
// 4 3
// 5 2 4 3
// q 1 3
// u 1 1
// q 3 4
// Sample Output 1:
// 2
// 3

#include<bits/stdc++.h>

using namespace std;

void buildTree(int* arr, int* segmentTree, int start, int end, int idx)
{
    if (start == end)
    {
        segmentTree[idx] = arr[start];
        return;
    }
    
    int mid = start + (end - start)/2;
    
    buildTree(arr, segmentTree, start, mid, 2*idx + 1);
    buildTree(arr, segmentTree, mid + 1, end, 2*idx + 2);
    
    segmentTree[idx] = min(segmentTree[2*idx + 1], segmentTree[2*idx + 2]);
}

void updateTree(int* arr, int* segmentTree, int start, int end, int idx, int pos, int val)
{
    if (start == end)
    {
        arr[pos] = segmentTree[idx] = val;
        return;
    }
    
    int mid = start + (end - start)/2;
    
    if (pos <= mid)
        updateTree(arr, segmentTree, start, mid, 2*idx + 1, pos, val);
    else
        updateTree(arr, segmentTree, mid + 1, end, 2*idx + 2, pos, val);
    
    segmentTree[idx] = min(segmentTree[2*idx + 1], segmentTree[2*idx + 2]);
}

int minInSubarray(int* segmentTree, int start, int end, int idx, int l, int r)
{
    if (start > r || end < l)
    	return INT_MAX;
    if (start >= l && end <= r)
        return segmentTree[idx];
    
    int mid = start + (end - start)/2;
    
    if (r <= mid)
    	return minInSubarray(segmentTree, start, mid, 2*idx + 1, l, r);
    if (l > mid)
        return minInSubarray(segmentTree, mid + 1, end, 2*idx + 2, l, r);
    
    int x = minInSubarray(segmentTree, start, mid, 2*idx + 1, l, r);
    int y = minInSubarray(segmentTree, mid + 1, end, 2*idx + 2, l, r);
    
    return min(x, y);
}

int main()
{
    int n, q;
    cin>>n>>q;
    
    int* arr = new int[n];
    int* segmentTree = new int[4*n];
    
    for (int i=0;i<n;i++)
    	cin>>arr[i];
    
    buildTree(arr, segmentTree, 0, n-1, 0);
    
    while (q--)
    {
        char c;
        cin>>c;
        
        if (c == 'u')
        {
            int pos, val;
            cin>>pos>>val;
            
            updateTree(arr, segmentTree, 0, n-1, 0, pos-1, val);
        }
        else
        {
            int l, r;
            cin>>l>>r;
            
            cout<<minInSubarray(segmentTree, 0, n-1, 0, l-1, r-1)<<"\n";
        }
    }
    
    return 0;
}
