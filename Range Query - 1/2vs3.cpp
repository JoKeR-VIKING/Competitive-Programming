// 2 vs 3
// Send Feedback
// The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
// The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
// Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
// Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

// Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
// The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
// Input format:
// The first line contains N denoting the length of the binary string .
// The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
// This is followed up by Q lines where each line contains a query.
// Output format:
// For each query of Type 0 print the value modulo 3.
// Constraints:
// 1<= N <=10^5
// 1<= Q <= 10^5
// 0 <= l <= r < N
// Sample Input
// 5
// 10010
// 6
// 0 2 4
// 0 2 3
// 1 1
// 0 0 4
// 1 1
// 0 0 3
// Sample Output
// 2
// 1
// 2
// 1

#include<bits/stdc++.h>

using namespace std;

int power[100001];

void buildPower()
{
    power[0] = 1;

    for(int i = 1; i < 100001; i++)
        power[i] = (power[i-1] * 2) % 3;
}

void buildTree(string& s, int* segmentTree, int start, int end, int idx)
{
    if (start == end)
    {
        segmentTree[idx] = (s[start] == '1' ? 1 : 0);
        return;
    }

    int mid = start + (end - start)/2;
    buildTree(s, segmentTree, start, mid, 2*idx + 1);
    buildTree(s, segmentTree, mid + 1, end, 2*idx + 2);

    segmentTree[idx] = (((power[end - mid] % 3) * segmentTree[2*idx + 1] % 3) % 3 + segmentTree[2*idx + 2] % 3) % 3;
}

void updateTree(string& s, int* segmentTree, int start, int end, int idx, int pos)
{
    if (start == end)
    {
        s[pos] = '1';
        segmentTree[idx] = 1;
        return;
    }

    int mid = start + (end - start)/2;

    if (pos <= mid)
        updateTree(s, segmentTree, start, mid, 2*idx + 1, pos);
    else
        updateTree(s, segmentTree, mid + 1, end, 2*idx + 2, pos);

    segmentTree[idx] = (((power[end - mid] % 3) * segmentTree[2*idx + 1] % 3) % 3 + segmentTree[2*idx + 2] % 3) % 3;
}

int query(int* segmentTree, int start, int end, int idx, int l, int r)
{
    if (end < l || start > r)
        return 0;
    if (start >= l && end <= r)
        return ((int)power[r-end] * segmentTree[idx]) % 3;

    int mid = start + (end - start)/2;

    int x = query(segmentTree, start, mid, 2*idx + 1, l, r);
    int y = query(segmentTree, mid + 1, end, 2*idx + 2, l, r);

    return (x % 3 + y % 3) % 3;
}

int main()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int* segmentTree = new int[4*n]();
    buildPower();
    buildTree(s, segmentTree, 0, s.length()-1, 0);

    int q;
    cin>>q;

    while (q--)
    {
        int type;
        cin>>type;

        if (type == 1)
        {
            int pos;
            cin>>pos;

            updateTree(s, segmentTree, 0, s.length()-1, 0, pos);
        }
        else
        {
            int l, r;
            cin>>l>>r;

            cout<<query(segmentTree, 0, s.length()-1, 0, l, r)<<"\n";
        }
    }

    return 0;
}
