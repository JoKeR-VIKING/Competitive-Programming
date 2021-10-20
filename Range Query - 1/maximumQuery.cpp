// Maximum Query
// Send Feedback
// You are given an array of integet of size N and Q queries in form of (l, r). You are supposed to find the maximum value of array between index l and r (both inclusive)
// Input Format:
// First line of input contain an integer N (number of elements in the array)
// Second line contain N space-separated integers denoting the elements of the array
// Third line contain an integer Q (number of queries to be processed)
// Next Q line contain two space-separated integers denoting l and r.
// Output Format:
// For each test case print the output in newline.
// Constraints:
// 1 <= N <= 10^4
// 1 <= Q <= 10^6
// 1 <= arr[i] <= 10^9
// 0 <= l <= r < N
// Sample Input:
// 5
// 1 2 3 5 4
// 2 
// 0 1
// 3 4
// Sample Output:
// 2
// 5

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void buildTree(ll* arr, ll* segmentTree, int start, int end, int idx)
{
    if (start == end)
    {
        segmentTree[idx] = arr[start];
        return;
    }
    
    int mid = start + (end - start)/2;
    buildTree(arr, segmentTree, start, mid, 2*idx + 1);
    buildTree(arr, segmentTree, mid + 1, end, 2*idx + 2);
    
    segmentTree[idx] = max(segmentTree[2*idx + 1], segmentTree[2*idx + 2]);
}

ll maxOfInterval(ll* segmentTree, int start, int end, int idx, int l, int r)
{
    if (end < l || start > r)
        return 0;
    if (start >= l && end <= r)
        return segmentTree[idx];
    
    int mid = start + (end - start)/2;
    ll x = maxOfInterval(segmentTree, start, mid, 2*idx + 1, l, r);
    ll y = maxOfInterval(segmentTree, mid + 1, end, 2*idx + 2, l, r);
    
    return max(x, y);
}

int main()
{
    int n;
    cin>>n;
    
    ll* arr = new ll[n];
    ll* segmentTree = new ll[4*n]();
    
    for (int i=0;i<n;i++)
        cin>>arr[i];
    
    buildTree(arr, segmentTree, 0, n-1, 0);
    
    int q;
    cin>>q;
    
    while (q--)
    {
        int l, r;
        cin>>l>>r;
        
        cout<<maxOfInterval(segmentTree, 0, n-1, 0, l, r)<<"\n";
    }
    
    return 0;
}
