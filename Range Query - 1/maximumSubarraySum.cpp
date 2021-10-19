// Maximum Sum In Subarray

// You are given a sequence A[1], A[2], ..., A[N].
// A query is defined as follows:
// Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }. 
// Given M queries, write a program that outputs the results of these queries.
// Input Format:
// The first line of input contains an integer N.
// In the second line contains N space separated integers.
// The third line contains the integer M.
// Next M lines contains 2 integers x and y.
// Output Format:
// For each query, print the answer in a new line.
// Constraints:
// 1 <= N <= 10^5
// 1 < = Q <= 10^5
// -10^4 <= arr[i] <= 10^4
// Sample Input 1:
// 3 
// -1 2 3 
// 1
// 1 2
// Sample Output 1:
// 2

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

class Sum
{
public:
    ll prefixSum, suffixSum, bestSum, sum;
};

void buildTree(int* arr, Sum* segmentTree, int start, int end, int idx)
{
    if (start == end)
    {
        segmentTree[idx].prefixSum = segmentTree[idx].suffixSum = segmentTree[idx].bestSum = segmentTree[idx].sum = arr[start];
        return;
    }
    
    int mid = start + (end - start)/2;
    buildTree(arr, segmentTree, start, mid, 2*idx + 1);
    buildTree(arr, segmentTree, mid + 1, end, 2*idx + 2);
    
    segmentTree[idx].sum = segmentTree[2*idx + 1].sum + segmentTree[2*idx + 2].sum;
    segmentTree[idx].prefixSum = max(segmentTree[2*idx + 1].prefixSum, segmentTree[2*idx + 1].sum + segmentTree[2*idx + 2].prefixSum);
    segmentTree[idx].suffixSum = max(segmentTree[2*idx + 2].suffixSum, segmentTree[2*idx + 1].suffixSum + segmentTree[2*idx + 2].sum);
    segmentTree[idx].bestSum = max(segmentTree[idx].prefixSum, max(segmentTree[idx].suffixSum, 
                               max(segmentTree[2*idx + 1].bestSum, 
                               max(segmentTree[2*idx + 2].bestSum, 
                               segmentTree[2*idx + 1].suffixSum + segmentTree[2*idx + 2].prefixSum))));
    
}

Sum greatestSumSubarray(Sum* segmentTree, int start, int end, int idx, int l, int r)
{
    if (end < l || start > r)
        return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
    if (start >= l && end <= r)
        return segmentTree[idx];
    
    int mid = start + (end - start)/2;
    Sum x = greatestSumSubarray(segmentTree, start, mid, 2*idx + 1, l, r);
    Sum y = greatestSumSubarray(segmentTree, mid + 1, end, 2*idx + 2, l, r);
    
    Sum ans;
    
    ans.sum = x.sum + y.sum;
    ans.prefixSum = max(x.prefixSum, x.sum + y.prefixSum);
    ans.suffixSum = max(y.suffixSum, y.sum + x.suffixSum);
    ans.bestSum = max(ans.prefixSum, max(ans.suffixSum, max(x.bestSum, max(y.bestSum, x.suffixSum + y.prefixSum))));
    
    return ans;
}

int main()
{
    int n;
    cin>>n;
    
    int* arr = new int[n];
    Sum* segmentTree = new Sum[4*n];
    
    for (int i=0;i<n;i++)
    	cin>>arr[i];
    
    buildTree(arr, segmentTree, 0, n-1, 0);
    
    int q;
    cin>>q;
    
    while (q--)
    {
        int l, r;
        cin>>l>>r;
        
        cout<<greatestSumSubarray(segmentTree, 0, n-1, 0, l-1, r-1).bestSum<<"\n";
    }
    
    return 0;
}
