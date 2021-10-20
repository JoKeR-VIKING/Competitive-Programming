// Counting Even/Odd
// Send Feedback
// Tanmay and Rohit are best buddies. One day Tanmay gives Rohit a problem to test his intelligence and skills. He gives him an array of N natural numbers and asks him to solve the following queries:-
// Query 0:
// 0 x y
// This operation modifies the element present at index i to x.
// Query 1:
// 1 x y 
// This operation counts the number of even numbers in range l to r inclusive.
// Query 2:
// 2 x y 
// This operation counts the number of odd numbers in range l to r inclusive.
// Input Format:
// First line of the input contains the number N. 
// Next line contains N natural numbers. 
// Next line contains an integer Q followed by Q queries.
// 0 x y - modify the number at index x to y. 
// 1 x y - count the number of even numbers in range l to r inclusive.
// 2 x y - count the number of odd numbers in range l to r inclusive.
// Constraints:
// 1<=N,Q<=10^5
// 1<=l<=r<=N 
// 0<=Ai<=10^9
// 1<=x<=N
// 0<=y<=10^9
// Output Format:
//  For each query, print the answer in a new line.
// Note: Indexing starts from 1
// Sample Input 1:
// 6
// 1 2 3 4 5 6
// 4
// 1 2 5
// 2 1 4
// 0 5 4
// 1 1 6
// Sample Output 1:
// 2
// 2
// 4

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

class Node
{
public:
    ll even_count, odd_count;
};

void buildTree(ll* arr, Node* segmentTree, int start, int end, int idx)
{
    if (start == end)
    {
        if (arr[start] % 2)
            segmentTree[idx] = {0, 1};
        else
            segmentTree[idx] = {1, 0};
        
        return;
    }
    
    int mid = start + (end - start)/2;
    buildTree(arr, segmentTree, start, mid, 2*idx + 1);
    buildTree(arr, segmentTree, mid + 1, end, 2*idx + 2);
    
    segmentTree[idx] = {segmentTree[2*idx + 1].even_count + segmentTree[2*idx + 2].even_count, segmentTree[2*idx + 1].odd_count + segmentTree[2*idx + 2].odd_count};
}

void update(ll* arr, Node* segmentTree, int start, int end, int idx, int pos, int val)
{
    if (start == end)
    {
        arr[start] = val;
        
        if (val % 2)
            segmentTree[idx] = {0, 1};
        else
            segmentTree[idx] = {1, 0};
        
        return;
    }
    
    int mid = start + (end - start)/2;
    
    if (pos <= mid)
    	update(arr, segmentTree, start, mid, 2*idx + 1, pos, val);
    else
    	update(arr, segmentTree, mid + 1, end, 2*idx + 2, pos, val);
    
    segmentTree[idx] = {segmentTree[2*idx + 1].even_count + segmentTree[2*idx + 2].even_count, segmentTree[2*idx + 1].odd_count + segmentTree[2*idx + 2].odd_count};
}

Node query(Node* segmentTree, int start, int end, int idx, int l, int r)
{
    if (end < l || start > r)
        return {0, 0};
    if (start >= l && end <= r)
        return segmentTree[idx];
    
    int mid = start + (end - start)/2;
    Node x = query(segmentTree, start, mid, 2*idx + 1, l, r);
    Node y = query(segmentTree, mid + 1, end, 2*idx + 2, l, r);
    
    return {x.even_count + y.even_count, x.odd_count + y.odd_count};
}

int main()
{
    int n;
    cin>>n;
    
    ll* arr = new ll[n];
    Node* segmentTree = new Node[4*n];
    
    for (int i=0;i<n;i++)
        cin>>arr[i];
    
    buildTree(arr, segmentTree, 0, n-1, 0);
    
    int q;
    cin>>q;
    
    while (q--)
    {
        int op;
        cin>>op;
        
        if (op == 0)
        {
            ll x, y;
            cin>>x>>y;
            
            update(arr, segmentTree, 0, n-1, 0, x-1, y);
        }
        else if (op == 1)
        {
            ll x, y;
            cin>>x>>y;
            
            cout<<query(segmentTree, 0, n-1, 0, x-1, y-1).even_count<<"\n";
        }
        else
        {
            ll x, y;
            cin>>x>>y;
            
            cout<<query(segmentTree, 0, n-1, 0, x-1, y-1).odd_count<<"\n";
        }
    }
    
    return 0;
}
